package com.zeroone.star.project.j3.vo;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * 获取消息详情
 * 页面回显数据
 */

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("消息列表")
@TableName(value = "sys_message")
public class NewsPageVO implements Serializable {

    @TableId(value = "message_id")
    @ApiModelProperty(value = "附件ID")
    private Long id;

    @ApiModelProperty(value = "消息类型")
    private String messageType;

    @ApiModelProperty(value = "消息级别")
    private String messageLevel;

    @ApiModelProperty(value = "发送人",example = "若依")
    private String senderNick;

    @ApiModelProperty(value = "接收人",example = "若依")
    private String recipientNick;

    @ApiModelProperty(value = "标题")
    private String messageTitle;

    @ApiModelProperty(value = "内容")
    private String messageContent;

    @ApiModelProperty(value = "状态")
    private String status;

    @ApiModelProperty(value = "处理时间")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime processTime;

    @ApiModelProperty(value = "回调地址")
    private String callBack;









}
