package com.zeroone.star.scheduleplan.entity;

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
 * 计划班次表
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
@Getter
@Setter
@TableName("cal_shift")
public class CalShift implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 班次ID
     */
    @TableId(value = "shift_id", type = IdType.AUTO)
    private Long shiftId;

    /**
     * 计划ID
     */
    private Long planId;

    /**
     * 序号
     */
    private Integer orderNum;

    /**
     * 班次名称
     */
    private String shiftName;

    /**
     * 开始时间
     */
    private String startTime;

    /**
     * 结束时间
     */
    private String endTime;

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
