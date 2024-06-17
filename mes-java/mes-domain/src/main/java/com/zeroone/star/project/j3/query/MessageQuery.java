package com.zeroone.star.project.j3.query;

import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

import java.util.Date;

@Data
@Builder
public class MessageQuery {

    @ApiModelProperty(value = "消息ID")
    private Long messageId;

    @ApiModelProperty(value = "消息类型")
    private String messageType;

    @ApiModelProperty(value = "消息级别")
    private String messageLevel;

    @ApiModelProperty(value = "发送人昵称")
    private String senderNick;

    @ApiModelProperty(value = "接收人昵称")
    private String recipientNick;

    @ApiModelProperty(value = "状态")
    private String status;

}
