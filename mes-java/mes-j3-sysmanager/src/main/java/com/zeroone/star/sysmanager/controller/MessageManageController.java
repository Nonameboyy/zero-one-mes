package com.zeroone.star.sysmanager.controller;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.util.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.j3.dto.PageDTO;
import com.zeroone.star.project.j3.query.NewsPageQuery;
import com.zeroone.star.project.j3.dto.ExportConditionMessageDTO;
import com.zeroone.star.project.j3.dto.ExportMessageDTO;
import com.zeroone.star.project.j3.dto.SysAddMessageDTO;
import com.zeroone.star.project.j3.dto.SysUpdateMessageDTO;
import com.zeroone.star.project.j3.sysmanager.MessageManageApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.ISysMessageService;
import com.zeroone.star.sysmanager.entity.SysMessage;
import com.zeroone.star.sysmanager.service.ISysMessageService;
import io.swagger.annotations.Api;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import com.zeroone.star.project.j3.vo.NewsPageVO;
import com.zeroone.star.project.j3.vo.NewsVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import lombok.SneakyThrows;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Api(tags = "消息管理")
@RestController
@RequestMapping("sys-manager/message-manager")
@ResponseBody
public class MessageManageController implements MessageManageApis {

    @Resource
    EasyExcelComponent excel;

    @Resource
    FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    String urlPrefix;

    @Resource
    ISysMessageService ISysMessageService;


    /**
     * 获取消息详情
     * @param id
     * @return
     */
    @GetMapping("/news/{id}")
    @ApiOperation(value = "消息详情")
    public JsonVO<NewsVO> getNewsById(@PathVariable Long id) {
        NewsVO newsVO =ISysMessageService.getNewsById(id);
        return JsonVO.success(newsVO);
    }

    /**
     * 获取消息列表（分页+查询）
     * @param newsPageQuery
     * @return
     */
    @GetMapping("/news/list")
    @ApiOperation(value = "消息列表")
    public JsonVO<PageDTO<NewsPageVO>> queryNewsList(@RequestBody NewsPageQuery newsPageQuery) {
        PageDTO<NewsPageVO> page= ISysMessageService.queryNewsList(newsPageQuery);
        return JsonVO.success(page);
    }


    /**
     * 添加消息
     * @param sysAddMessageDTO 消息实体
     * @return
     */
    @PostMapping("add-message")
    @Override
    @ApiOperation(value = "添加消息")
    public JsonVO<String> addMessage(@RequestBody SysAddMessageDTO sysAddMessageDTO) {
        return ISysMessageService.saveMessage(sysAddMessageDTO);

    }

    /**
     * 更改消息
     * @param sysUpdateMessageDTO 消息
     * @return
     */
    @PutMapping("modify-message")
    @Override
    @ApiOperation(value = "修改消息")
    public JsonVO<String> modifyMessage(@RequestBody SysUpdateMessageDTO sysUpdateMessageDTO) {
        return ISysMessageService.updateMessageById(sysUpdateMessageDTO);
    }

    /**
     * 批量删除消息(假删除)
     * @param messageIds 需要删除的消息主键集合
     * @return
     */
    @DeleteMapping("remove-by-messageIds")
    @Override
    @ApiOperation(value = "删除消息根据id(单独删除和批量都支持)")
    public JsonVO<String> removeMessageByMessageIds(@RequestParam String messageIds) {

        //转换字符串id 为集合
        List<Long> messageIdsList = StringIdToList(messageIds);

        return ISysMessageService.removeMessageByIds(messageIdsList);
    }

    /**
     * 方法封装-转换@param 字符串id 为集合
     * @param messageIds 前端传入的param字符串id
     * @return 消息id 集合
     */
    public List<Long> StringIdToList(String messageIds){

        List<Long> messageIdsList = new ArrayList<>();

        String[] strs = messageIds.split(",");
        for (String str:strs){
            messageIdsList.add(Long.parseLong(str));
        }

        return messageIdsList;
    }

    /**
     * 方法封装-转换数据到DTO
     * @param exportConditionMessageDTO 根据发送参数筛选 获取数据
     * @return 导出类型消息DTO集合
     */
    public List<ExportMessageDTO> dataConversion(ExportConditionMessageDTO exportConditionMessageDTO){

        LambdaQueryWrapper<SysMessage> queryWrapper = new LambdaQueryWrapper<>();
        //根据传递参数判断是否要进行数据库查询操作
        if (exportConditionMessageDTO.getMessageType() != null && !StringUtils.isBlank(exportConditionMessageDTO.getMessageType())) {
            StringUtils.isBlank(null);
        }
        if (exportConditionMessageDTO.getMessageLevel() !=null  && !StringUtils.isBlank(exportConditionMessageDTO.getMessageLevel())){
            queryWrapper.eq(SysMessage::getMessageLevel,exportConditionMessageDTO.getMessageLevel());
        }
        if (exportConditionMessageDTO.getSenderNick() !=null  && !StringUtils.isBlank(exportConditionMessageDTO.getSenderNick())){
            queryWrapper.eq(SysMessage::getSenderName,exportConditionMessageDTO.getSenderNick());
        }
        if (exportConditionMessageDTO.getRecipientNick() !=null  && !StringUtils.isBlank(exportConditionMessageDTO.getRecipientNick())){
            queryWrapper.eq(SysMessage::getRecipientNick,exportConditionMessageDTO.getRecipientNick());
        }
        if (exportConditionMessageDTO.getStatus() !=null  && !StringUtils.isBlank(exportConditionMessageDTO.getStatus())){
            queryWrapper.eq(SysMessage::getStatus,exportConditionMessageDTO.getStatus());
        }

        List<SysMessage> messages = ISysMessageService.getBaseMapper().selectList(queryWrapper);


        // 转换数据到 DTO

        List<ExportMessageDTO> exportList = messages.stream().map(message -> {
            ExportMessageDTO dto = new ExportMessageDTO();
            dto.setMessageType(message.getMessageType());
            dto.setMessageLevel(message.getMessageLevel());
            dto.setMessageTitle(message.getMessageTitle());
            dto.setMessageContent(message.getMessageContent());
            dto.setSenderId(message.getSenderId());
            dto.setSenderName(message.getSenderName());
            dto.setSenderNick(message.getSenderNick());
            dto.setRecipientId(message.getRecipientId());
            dto.setRecipientName(message.getRecipientName());
            dto.setRecipientNick(message.getRecipientNick());
            dto.setProcessTime(message.getProcessTime());
            dto.setCallBack(message.getCallBack());
            dto.setStatus(message.getStatus());
            dto.setDeletedFlag(message.getDeletedFlag());
            return dto;
        }).collect(Collectors.toList());

        return exportList;
    }

    /**
     * 全部数据导出报表
     * @return 报表
     */
    @SneakyThrows
    @GetMapping(value = "download-messageAll", produces = "application/octet-stream")
    @ApiOperation(value = "下载全部数据到Excel")
    public ResponseEntity<byte[]> downloadMessageExcelALL() {
        // 构建一个输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        // 导出数据到输出流 这块转换了数据到DTO
        EasyExcel.write(out, ExportMessageDTO.class).sheet("导出").doWrite(dataConversion(new ExportConditionMessageDTO()));
        // 获取字节数据
        byte[] bytes = out.toByteArray();
        out.close();

        // 构建响应头
        HttpHeaders headers = new HttpHeaders();
        String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        // 响应文件给客户端
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }

    /**
     * 所有数据导出到dfs
     * @return 下载地址
     */
    @SneakyThrows
    @ResponseBody
    @GetMapping(value = "export-messageAll-dfs")
    @ApiOperation(value = "导出全部数据到dfs")
    public JsonVO<String> exportMessageToDfsALL() {
        // 构建一个输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        // 导出数据到输出流
        EasyExcel.write(out, ExportMessageDTO.class).sheet("导出").doWrite(dataConversion(new ExportConditionMessageDTO()));

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


    /**
     * 根据指定id数据导出报表
     * @return 报表
     */
    @SneakyThrows
    @PostMapping(value = "download-message", produces = "application/octet-stream")
    @ApiOperation(value = "根据指定信息筛选下载Excel")
    public ResponseEntity<byte[]> downloadMessageExcel(@RequestBody ExportConditionMessageDTO exportConditionMessageDTO) {

        // 构建一个输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();


        // 导出数据到输出流
        EasyExcel.write(out, ExportMessageDTO.class).sheet("导出").doWrite(dataConversion(exportConditionMessageDTO));
        // 获取字节数据
        byte[] bytes = out.toByteArray();
        out.close();

        // 构建响应头
        HttpHeaders headers = new HttpHeaders();
        String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        // 响应文件给客户端
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }

    /**
     * 根据指定id导出到 dfs
     * @return 下载地址
     */
    @SneakyThrows
    @ResponseBody
    @PostMapping(value = "export-message-dfs")
    @ApiOperation(value = "根据指定信息筛选导出到dfs")
    public JsonVO<String> exportMessageToDfs(@RequestBody ExportConditionMessageDTO exportConditionMessageDTO) {


        // 构建一个输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        // 导出数据到输出流
        EasyExcel.write(out, ExportMessageDTO.class).sheet("导出").doWrite(dataConversion(exportConditionMessageDTO));

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
