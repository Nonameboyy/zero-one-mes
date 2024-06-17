package com.zeroone.star.sysmanagement.controller;


import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.sysmanagement.logmanagement.OperationLog.OperationLogQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.sysmanagement.logmanagement.OperationLog.OperationLogVO;
import com.zeroone.star.sysmanagement.entity.SysOperLog;
import com.zeroone.star.sysmanagement.service.ISysOperLogService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.Min;
import java.io.ByteArrayOutputStream;
import java.util.List;

import static com.zeroone.star.sysmanagement.constants.OperLogConstants.*;

/**
 * 操作日志记录的RESTful API控制器。
 * 提供对操作日志的增删查以及导出功能的支持。
 *
 * 主要方法包括：
 * - 删除指定ID的操作日志条目
 * - 清空所有操作日志
 * - 导出操作日志为Excel文件并下载
 * - 将操作日志导出到FastDFS分布式文件系统
 *
 * 使用了Hutool库进行日期处理，EasyExcelComponent进行Excel操作，
 * 以及FastDfsClientComponent处理与FastDFS的交互。
 *
 * @author lenyan
 * @since 2024-05-19
 */
@RestController
@RequestMapping("/sys/operlog")
@Api(tags = "操作日志记录")
@Validated
@Slf4j
public class SysOperLogController {
    @Resource
    private ISysOperLogService sysOperLogService; // 操作日志服务接口，用于CRUD操作

    @Resource
    private EasyExcelComponent excel; // Excel操作组件，用于导出Excel

    @Resource
    private FastDfsClientComponent dfs; // FastDFS客户端组件，用于文件上传操作

    @Value("${fastdfs.nginx-servers}") // 从配置文件读取FastDFS的Nginx服务器地址前缀
    private String urlPrefix;


    /**
     * 根据操作日志ID列表批量删除日志记录。
     * 成功时返回成功信息，否则返回失败提示。
     *
     * @param operIds 操作日志ID列表
     * @return 包含操作结果信息的JsonVO对象
     */
    @ApiOperation(value = "删除日志")
    @DeleteMapping("/remove-operlog/{operIds}")
    public JsonVO<String> removeOperLog(@PathVariable List<Long> operIds) {
        Boolean result = sysOperLogService.removeByIds(operIds);
        if (!result) {
            return JsonVO.fail(LOG_NOT_EXIST_MESSAGE);
        }
        return JsonVO.success(DELETE_SUCCESS_MESSAGE);
    }

    /**
     * 清空所有的操作日志记录。
     * 成功执行后返回清除成功的提示信息。
     *
     * @return 包含操作结果信息的JsonVO对象
     */
    @ApiOperation(value = "清空日志")
    @DeleteMapping("/clean-operlog")
    public JsonVO<String> removeAllOperLog() {
        sysOperLogService.removeAllOperLog();
        return JsonVO.success(CLEAR_SUCCESS_MESSAGE);
    }

    /**
     * 导出操作日志记录为Excel文件并提供下载。
     * 生成的Excel文件名包含当前日期时间戳，以"xlsx"格式提供下载。
     *
     * @return 包含Excel文件字节流的HTTP响应实体
     */
    @SneakyThrows
    @GetMapping(value = "export-operlog", produces = "application/octet-stream")
    @ApiOperation(value = "导出操作日志")
    public ResponseEntity<byte[]> downloadOperLogExcel() {

        List<SysOperLog> sysOperLogs = sysOperLogService.Operloginfo();

        // 构建一个输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        // 导出数据到输出流
        excel.export("导出操作日志", out, SysOperLog.class, sysOperLogs);
        // 获取字节数据
        byte[] bytes = out.toByteArray();
        out.close();

        // 构建响应头
        HttpHeaders headers = new HttpHeaders();
        String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        headers.add("Content-Disposition", "attachment;filename=" + filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        // 响应文件给客户端
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }
    @ApiOperation( value = "分页获取日志")
    @GetMapping  ("/page")
    public JsonVO<PageDTO<OperationLogVO>> getOperationLogPage( OperationLogQuery query) {
        if (query == null){
            throw new RuntimeException("参数不能为空");
        }
        PageDTO<SysOperLog> sysOperLogs = sysOperLogService.selectOperLogList(query);
        PageDTO<OperationLogVO> operationLogVOPageDTO = new PageDTO<>();
        BeanUtil.copyProperties(sysOperLogs, operationLogVOPageDTO);
        return JsonVO.success(operationLogVOPageDTO);
    }

    @ApiOperation( value = "获取日志详情")
    @GetMapping("/{operId}")
    public JsonVO<OperationLogVO> getOperationLogDetail(@PathVariable("operId") @Min(value = 1, message = "id最小值为1")Long operId) {
        if (operId == null){
            throw new RuntimeException("参数不能为空");
        }
        SysOperLog sysOperLog = sysOperLogService.selectOperLogById(operId);
        OperationLogVO operationLogVO = new OperationLogVO();
        BeanUtil.copyProperties(sysOperLog, operationLogVO);
        log.debug("获取日志详情成功");
        return JsonVO.success(operationLogVO);
    }

    /**
     * 导出操作日志到FastDFS分布式文件系统，并返回文件访问URL。
     * 成功上传后返回文件的访问URL，失败则返回错误信息。
     *
     * @return 包含文件URL或错误信息的JsonVO对象
     */
    @SneakyThrows
    @ResponseBody
    @GetMapping(value = "export-operlogtodfs")
    @ApiOperation(value = "导出操作日志到dfs")
    public JsonVO<String> exportToDfs() {
        List<SysOperLog> sysOperLogs = sysOperLogService.Operloginfo();
        // 构建一个输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        // 导出数据到输出流
        excel.export("测试", out, SysOperLog.class, sysOperLogs);
        // 获取字节数据
        byte[] bytes = out.toByteArray();
        out.close();

        // 上传文件到文件服务器
        FastDfsFileInfo result = dfs.uploadFile(bytes, ".xlsx");
        if (result != null) {
            return JsonVO.success(dfs.fetchUrl(result, "http://" + urlPrefix, true));
        }
        return JsonVO.fail(null);
    }


}
