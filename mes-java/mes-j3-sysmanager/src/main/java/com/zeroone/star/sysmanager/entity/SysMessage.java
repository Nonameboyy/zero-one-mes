package com.zeroone.star.sysmanager.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.sql.Blob;
import java.time.LocalDate;
import java.time.LocalDateTime;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 消息表
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
@Data
@ApiModel
@TableName("sys_message")
public class SysMessage implements Serializable{

    private static final long serialVersionUID = 1L;

    /**
     * 附件ID
     */
    @ApiModelProperty(value = "附件id")
    @ExcelProperty(value = "附件id",index = 0)
    @TableId(value = "message_id", type = IdType.AUTO)
    private Long messageId;

    /** 消息类型 */
    @ApiModelProperty(value = "消息类型",example = "公告、提示、告警、聊天信息")
    @ExcelProperty(value = "消息类型",index = 1)
    private String messageType;

    /** 消息级别 */
    @ApiModelProperty(value = "消息级别",example = "普通、警告、紧急")
    @ExcelProperty(value = "消息级别",index = 2)
    private String messageLevel;

    /** 标题 */
    @ApiModelProperty(value = "标题",example = "这是一个标题")
    @ExcelProperty(value = "标题",index = 3)
    private String messageTitle;

    /** 内容 */
    @ApiModelProperty(value = "内容",example = "这是一些内容")
    @ExcelProperty(value = "内容",index = 4)
    private String messageContent;

    /** 发送人ID */
    @ApiModelProperty(value = "发送人ID",example = "12345678")
    @ExcelProperty(value = "发送人ID",index = 5)
    private Long senderId;

    /** 发送人名称 */
    @ApiModelProperty(value = "发送人名称",example = "张三")
    @ExcelProperty(value = "发送人名称",index = 6)
    private String senderName;

    /** 发送人昵称 */
    @ApiModelProperty(value = "发送人昵称",example = "不法少年张三")
    @ExcelProperty(value = "发送人昵称",index = 7)
    private String senderNick;

    /** 接收人ID */
    @ApiModelProperty(value = "接收人ID",example = "87654321")
    @ExcelProperty(value = "接收人ID",index = 8)
    private Long recipientId;

    /** 接收人名称 */
    @ApiModelProperty(value = "接收人名称",example = "李四")
    @ExcelProperty(value = "接收人名称",index = 9)
    private String recipientName;

    /** 接收人昵称 */
    @ApiModelProperty(value = "接收人昵称",example = "妇女之友李四")
    @ExcelProperty(value = "接收人昵称",index = 10)
    private String recipientNick;

    /** 处理时间 */
    @ApiModelProperty(value = "处理时间",dataType = "yyyy-MM-dd",example = "2002-12-30")
    @ExcelProperty(value = "处理时间",index = 11)
    private LocalDate processTime;

    /** 回调地址 */
    @ApiModelProperty(value = "回调地址",example = "随意写")
    @ExcelProperty(value = "回调地址",index = 12)
    private String callBack;

    /** 状态 */
    @ApiModelProperty(value = "状态",example = "未读")
    @ExcelProperty(value = "状态",index = 13)
    private String status;

    /** 是否删除 */
    @ApiModelProperty(value = "是否删除",example = "N")
    @ExcelProperty(value = "是否删除",index = 14)
    private String deletedFlag;
    /* 备注 */
    @ApiModelProperty(value = "备注")
    @ExcelProperty(value = "备注",index = 15)
    private String remark;


    /** 预留字段1 */
    @ApiModelProperty(value = "预留字段1")
    @ExcelProperty(value = "预留字段1",index = 16)
    private String attr1;

    /** 预留字段2 */
    @ApiModelProperty(value = "预留字段2")
    @ExcelProperty(value = "预留字段2",index = 17)
    private String attr2;

    /** 预留字段3 */
    @ApiModelProperty(value = "预留字段3")
    @ExcelProperty(value = "预留字段3",index = 18)
    private Long attr3;

    /** 预留字段4 */
    @ApiModelProperty(value = "预留字段4")
    @ExcelProperty(value = "预留字段4",index = 19)
    private Long attr4;

    /**
     * 创建者
     */
    @ApiModelProperty(value = "创建者")
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

    /**
     * 更新者
     */
    @ApiModelProperty(value = "更新者")
    private String updateBy;

    /**
     * 更新时间
     */
    @ApiModelProperty(value = "更新时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime updateTime;

}
