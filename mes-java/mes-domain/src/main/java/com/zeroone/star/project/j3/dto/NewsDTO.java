package com.zeroone.star.project.j3.dto;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
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
 *
 * 页面展示消息对象
 */

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@TableName(value = "sys_message")
public class NewsDTO implements Serializable {

    @TableId(value = "message_id")
    @ApiModelProperty(value = "附件ID")
    private Long messageId;

    @ApiModelProperty(value = "消息类型")
    private String messageType;

    @ApiModelProperty(value = "消息级别")
    private String messageLevel;

    @ApiModelProperty(value = "接收人")
    private String receiver;

    @ApiModelProperty(value = "标题")
    private String messageTitle;

    @ApiModelProperty(value = "内容")
    private String messageContent;

    @ApiModelProperty(value = "回调地址")
    private String callBack;

    @ApiModelProperty(value = "发送人ID")
    private Integer senderTId;

    @ApiModelProperty(value = "发送人名称",example = "admin")
    private String senderName;

    @ApiModelProperty(value = "发送人昵称",example = "若依")
    private String senderNick;

    @ApiModelProperty(value = "接收人ID")
    private Integer receiverTId;

    @ApiModelProperty(value = "接收人名称",example = "admin")
    private String receiverName;

    @ApiModelProperty(value = "接收人昵称",example = "若依")
    private String receiverNick;

    @ApiModelProperty(value = "处理时间")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime processTime;

    @ApiModelProperty(value = "状态")
    private String status;

    @ApiModelProperty(value = "是否删除")
    private String deletedFlag;

    @ApiModelProperty(value = "备注")
    private String remark;

    @ApiModelProperty(value = "创建者",example = "admin")
    private String createBy;

    @ApiModelProperty(value = "创建时间")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "更新者",example = "admin")
    private String updateBy;

    @ApiModelProperty(value = "更新时间")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime updateTime;

}
