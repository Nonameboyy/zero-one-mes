package com.zeroone.star.project.j3.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

/**
 * 获取消息详情
 * 页面回显数据
 */

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("消息详情")
public class NewsVO implements Serializable {


    @ApiModelProperty(value = "消息类型")
    private String messageType;

    @ApiModelProperty(value = "消息级别")
    private String messageLevel;

    @ApiModelProperty(value = "接收人",example = "若依")
    private String recipientNick;

    @ApiModelProperty(value = "标题")
    private String messageTitle;

    @ApiModelProperty(value = "内容")
    private String messageContent;

    @ApiModelProperty(value = "回调地址")
    private String callBack;







}
