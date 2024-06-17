package com.zeroone.star.project.j1.mycenter.entity;

import com.fasterxml.jackson.annotation.JsonIgnore;
import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

import java.util.Date;

@Data
public class MailMessage {
    /**
     * 多个联系人分割字符
     */
    public static final String SR = ",";
    /**
     * 邮件发送人邮箱
     */
    private String from;
    /**
     * 邮件发送人名称
     */
    private String fromName;
    /**
     * 邮件接收人（多个邮箱则用逗号","隔开）,格式如：xxx@qq.com, xxxx@163.com
     */
    private String to;
    /**
     * 抄送（多个邮箱则用逗号","隔开）,格式如：xxx@qq.com, xxxx@163.com
     */
    private String cc;
    /**
     * 密送（多个邮箱则用逗号","隔开）,格式如：xxx@qq.com, xxxx@163.com
     */
    private String bcc;
    /**
     * 邮件主题
     */
    private String subject;
    /**
     * 邮件内容
     */
    private String text;
    /**
     * 邮件附件
     */
    @JsonIgnore
    private MultipartFile[] multipartFiles;
    /**
     * 发送时间
     */
    private Date sentDate;
    /**
     * 状态
     */
    private String status;
    /**
     * 报错信息
     */
    private String error;
}