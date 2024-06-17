package com.zeroone.star.sysmanagement.controller;


import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.j4.sysmanagement.logmanagement.LoginLogApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanagement.entity.LoginInfo;
import com.zeroone.star.sysmanagement.service.LoginInfoService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * <p>
 * 系统访问记录 登录日志管理
 * </p>
 *
 * @author jingzi
 * @since 2024-05-19
 */
@Api(tags = "登录日志控制器")
@RestController
@RequestMapping("LoginInfo")
public class LoginInfoController {

    @Resource
    private LoginInfoService loginInfoService;

    @Resource
    private EasyExcelComponent excel;


    /**
     * 删除登录日志列表
     */
    @ApiOperation("删除登录日志")
    @DeleteMapping("remove-LoginLog/{ids}")
    public JsonVO<Long> removeLoginLog(@PathVariable List<Long> ids) {
        Long result = loginInfoService.removeLoginInfo(ids);
        if (result > 0)
            return JsonVO.success(result);
        else
            return JsonVO.fail(result);
    }

    /**
     * 清空登录日志列表
     */
    @ApiOperation("清空登录日志")
    @DeleteMapping("clean-LoginLog")
    public JsonVO<String> clearLoginLog() {
        loginInfoService.clearLoginInfo();
        return JsonVO.success("清空成功");
    }


    /**
     * 导出登录日志列表
     */
    @ApiOperation("导出登录日志")
    @GetMapping(value = "export-LoginLog", produces = "application/octet-stream")
    @SneakyThrows
    public ResponseEntity<byte[]> exportLoginLog() {


        List<LoginInfo> logList = loginInfoService.listLoginInfo();

        //创建输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        //导出数据到输出流
        excel.export("导出登录日志", out, LoginInfo.class, logList);

        //获取字节数据
        byte[] bytes = out.toByteArray();
        out.close();

        //构建响应头
        HttpHeaders headers = new HttpHeaders();
        String filename = "report" + DateTime.now().toString("yyyyMMddHHmmss") + ".xlsx";
//        headers.setContentDispositionFormData("attachment", filename);
        headers.add("Content-Disposition", "attachment;filename=" + filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);

        //响应文件给客户端
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }
}

