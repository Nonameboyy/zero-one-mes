package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.time.LocalDate;


/**
 * 为了将文件夹推送到远程仓库而创建的类，用于占位，无其他用途
 */
@Data
@ApiModel
public class SysUpdateMessageDTO {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "附件id")
    /** 附件ID */
    private Long messageId;

    /** 消息类型 */
    @ApiModelProperty(value = "消息类型",example = "公告")
    private String messageType;

    /** 消息级别 */
    @ApiModelProperty(value = "消息级别",example = "普通")
    private String messageLevel;

    /** 接收人昵称 */
    @ApiModelProperty(value = "接收人昵称",example = "这是接收人昵称")
    private String recipientNick;

    /** 标题 */
    @ApiModelProperty(value = "标题",example = "这是一个标题")
    private String messageTitle;

    /** 内容 */
    @ApiModelProperty(value = "内容",example = "这是一些内容")
    private String messageContent;

    /** 回调地址 */
    @ApiModelProperty(value = "回调地址",example = "随意写")
    private String callBack;


}
