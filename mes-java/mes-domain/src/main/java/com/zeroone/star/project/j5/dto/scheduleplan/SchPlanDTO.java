package com.zeroone.star.project.j5.dto.scheduleplan;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDate;

@Data
@ApiModel("排班计划数据传输对象")
public class SchPlanDTO {
    @ApiModelProperty(value = "计划id")
    private int planId;

    @ApiModelProperty(value = "计划编号",example = "PLAN1111")
    private int planCode;

    @ApiModelProperty(value = "计划名称",example = "工厂翻修1")
    private String planName;

    @ApiModelProperty(value = "班组类型",example = "注塑")
    private String calendarType;


    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "开始日期",example = "2024-5-02")
    private LocalDate startDate;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "结束日期",example = "2025-5-02")
    private LocalDate endDate;

    @ApiModelProperty(value = "轮班方式",example = "白班")
    private String shiftType;

    @ApiModelProperty(value = "倒班方式",example = "按月")
    private String shiftMethod;

    @ApiModelProperty(value = "计划状态",example = "确认")
    private String status;

    @ApiModelProperty(value = "注释",example = "一段备注")
    private String remark;

}
