package com.zeroone.star.project.dto.mail;

import com.fasterxml.jackson.annotation.JsonIgnore;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 描述：书写一个邮件发送上传数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@ApiModel("邮件发送上传数据对象")
public class MailDTO {
    @ApiModelProperty(value = "邮件接收人（多个邮箱则用逗号\",\"隔开）", example = "xxx@qq.com,李明<xxxx@163.com>", required = true)
    private String to;
    @ApiModelProperty(value = "抄送（多个邮箱则用逗号\",\"隔开）", example = "xxx@qq.com,李明<xxxx@163.com>")
    private String cc;
    @ApiModelProperty(value = "密送（多个邮箱则用逗号\",\"隔开）", example = "xxx@qq.com,李明<xxxx@163.com>")
    private String bcc;
    @ApiModelProperty(value = "邮件主题", example = "测试邮件主题", required = true)
    private String subject;
    @ApiModelProperty(value = "邮件内容", example = "测试邮件内容", required = true)
    private String text;
    @JsonIgnore
    @ApiModelProperty(value = "邮件附件")
    private MultipartFile[] multipartFiles;
}