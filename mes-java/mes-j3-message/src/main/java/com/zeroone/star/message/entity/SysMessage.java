package com.zeroone.star.message.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.sql.Blob;
import java.time.LocalDateTime;
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
@Getter
@Setter
@TableName("sys_message")
public class SysMessage implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 附件ID
     */
    @TableId(value = "message_id", type = IdType.AUTO)
    private Long messageId;

    /**
     * 消息类型
     */
    private String messageType;

    /**
     * 消息级别
     */
    private String messageLevel;

    /**
     * 标题
     */
    private String messageTitle;

    /**
     * 内容
     */
    private Blob messageContent;

    /**
     * 发送人ID
     */
    private Long senderId;

    /**
     * 发送人名称
     */
    private String senderName;

    /**
     * 发送人昵称
     */
    private String senderNick;

    /**
     * 接收人ID
     */
    private Long recipientId;

    /**
     * 接收人名称
     */
    private String recipientName;

    /**
     * 接收人昵称
     */
    private String recipientNick;

    /**
     * 处理时间
     */
    private LocalDateTime processTime;

    /**
     * 回调地址
     */
    private String callBack;

    /**
     * 状态
     */
    private String status;

    /**
     * 是否删除
     */
    private String deletedFlag;

    /**
     * 备注
     */
    private String remark;

    /**
     * 预留字段1
     */
    private String attr1;

    /**
     * 预留字段2
     */
    private String attr2;

    /**
     * 预留字段3
     */
    private Integer attr3;

    /**
     * 预留字段4
     */
    private Integer attr4;

    /**
     * 创建者
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 更新者
     */
    private String updateBy;

    /**
     * 更新时间
     */
    private LocalDateTime updateTime;


}
