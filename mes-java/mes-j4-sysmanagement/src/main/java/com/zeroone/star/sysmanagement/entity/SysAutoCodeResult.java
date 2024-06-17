package com.zeroone.star.sysmanagement.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 编码生成记录表
 * </p>
 *
 * @author jm
 * @since 2024-06-05
 */
@Getter
@Setter
@TableName("sys_auto_code_result")
public class SysAutoCodeResult implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 记录ID
     */
    @TableId(value = "code_id", type = IdType.AUTO)
    private Long codeId;

    /**
     * 规则ID
     */
    private Long ruleId;

    /**
     * 生成日期时间
     */
    private String genDate;

    /**
     * 最后产生的序号
     */
    private Integer genIndex;

    /**
     * 最后产生的值
     */
    private String lastResult;

    /**
     * 最后产生的流水号
     */
    private Integer lastSerialNo;

    /**
     * 最后传入的参数
     */
    private String lastInputChar;

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
