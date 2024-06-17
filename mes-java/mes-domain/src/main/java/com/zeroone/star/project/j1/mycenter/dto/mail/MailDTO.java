package com.zeroone.star.project.j1.mycenter.dto.mail;

import com.fasterxml.jackson.annotation.JsonIgnore;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

@Data
@ApiModel("邮箱传输对象")
public class MailDTO {

    @ApiModelProperty(value = "分隔符常量")
    public static final String SR = ",";

    @ApiModelProperty(value = "发件人邮箱（多个邮箱则用逗号\",\"隔开）",example = "xxxxx@qq.com",required = true)
    private String to;

    @ApiModelProperty(value = "抄送人邮箱（多个邮箱则用逗号\",\"隔开）",example = "xxxxx@qq.com")
    private String cc;

    @ApiModelProperty(value = "密送人邮箱（多个邮箱则用逗号\",\"隔开）",example = "xxxxx@qq.com")
    private String bcc;

    @ApiModelProperty(value = "邮箱主题",example = "01测试邮箱" ,required = true)
    private String subject;

    @ApiModelProperty(value = "正文",example = "测试邮箱正文" ,required = true)
    private String text;

    /**
     * 邮件附件
     */
    @JsonIgnore
    @ApiModelProperty(value = "多文件上传(附件)",example = "xxxxxx.docx")
    private MultipartFile[] multipartFiles;

}
