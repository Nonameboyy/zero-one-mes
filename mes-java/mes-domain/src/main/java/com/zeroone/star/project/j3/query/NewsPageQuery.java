package com.zeroone.star.project.j3.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.Getter;

import java.io.Serializable;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel(value = "消息分页查询对象")
@Getter
public class NewsPageQuery extends PageQuery implements Serializable  {

    @ApiModelProperty(value = "消息类型",example = "WARNING")
    private String messageType;

    @ApiModelProperty(value = "消息级别",example = "A")
    private String messageLevel;

    @ApiModelProperty(value = "发送人昵称",example = "若依")
    private String senderNick;

    @ApiModelProperty(value = "接收人昵称",example = "若依")
    private String receiverNick;

    @ApiModelProperty(value = "状态",example = "UNREAD")
    private String status;
}


