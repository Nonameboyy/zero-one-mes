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
 * 编码生成规则组成表
 * </p>
 *
 * @author jm
 * @since 2024-05-21
 */
@Getter
@Setter
@TableName("sys_auto_code_part")
public class SysAutoCodePart implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 分段ID
     */
    @TableId(value = "part_id", type = IdType.AUTO)
    private Long partId;

    /**
     * 规则ID
     */
    private Long ruleId;

    /**
     * 分段序号
     */
    private Integer partIndex;

    /**
     * 分段类型，INPUTCHAR：输入字符，NOWDATE：当前日期时间，FIXCHAR：固定字符，SERIALNO：流水号
     */
    private String partType;

    /**
     * 分段编号
     */
    private String partCode;

    /**
     * 分段名称
     */
    private String partName;

    /**
     * 分段长度
     */
    private Integer partLength;

    private String dateFormat;

    /**
     * 输入字符
     */
    private String inputCharacter;

    /**
     * 固定字符
     */
    private String fixCharacter;

    /**
     * 流水号起始值
     */
    private Integer seriaStartNo;

    /**
     * 流水号步长
     */
    private Integer seriaStep;

    /**
     * 流水号当前值
     */
    private Integer seriaNowNo;

    /**
     * 流水号是否循环
     */
    private String cycleFlag;

    /**
     * 循环方式，YEAR：按年，MONTH：按月，DAY：按天，HOUR：按小时，MINITE：按分钟，OTHER：按传入字符变
     */
    private String cycleMethod;

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
    @TableField(fill = FieldFill.INSERT)
    private String createBy;

    /**
     * 创建时间
     */

    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 更新者
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private String updateBy;

    /**
     * 更新时间
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateTime;


}
