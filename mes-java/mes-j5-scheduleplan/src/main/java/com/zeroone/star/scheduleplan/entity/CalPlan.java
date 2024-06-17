package com.zeroone.star.scheduleplan.entity;

import com.alibaba.excel.annotation.ExcelProperty;
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
 * 排班计划表
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
@Getter
@Setter
@TableName("cal_plan")
public class CalPlan implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 计划ID
     */
    @TableId(value = "plan_id", type = IdType.AUTO)
    @ExcelProperty(value = "id",order = 0)
    private Long planId;

    /**
     * 计划编号
     */
    @ExcelProperty(value = "编号",order = 1)
    private String planCode;

    /**
     * 计划名称
     */
    @ExcelProperty(value = "名称",order = 2)
    private String planName;

    /**
     * 班组类型
     */
    @ExcelProperty(value = "类型",order = 3)
    private String calendarType;

    /**
     * 开始日期
     */
    @ExcelProperty(value = "开始日期",order =4)
    private LocalDateTime startDate;

    /**
     * 结束日期
     */
    @ExcelProperty(value = "结束日期",order = 5)
    private LocalDateTime endDate;

    /**
     * 轮班方式
     */
    @ExcelProperty(value = "轮班方式",order = 6)
    private String shiftType;

    /**
     * 倒班方式
     */
    @ExcelProperty(value = "倒班方式",order = 7)
    private String shiftMethod;

    /**
     * 数
     */
    @ExcelProperty(value = "数",order = 8)
    private Integer shiftCount;

    /**
     * 状态
     */
    @ExcelProperty(value = "状态",order = 9)
    private String status;

    /**
     * 备注
     */
    @ExcelProperty(value = "备注",order = 10)
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
