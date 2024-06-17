package com.zeroone.star.project.j5.vo.scheduleplan;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDate;

/**
 * <p>
 * 描述：排班计划列表显示数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author brickbreaker
 * @version 1.0.0
 */
@Data
@ApiModel("查询返回排班计划列表数据对象")
public class PlanListVO {

    @ApiModelProperty(value = "计划ID", example = "1")
    private Long planId;

    @ApiModelProperty(value = "计划编号", example = "PL12345")
    private String planCode;

    @ApiModelProperty(value = "计划名称", example = "年度计划")
    private String planName;

    @ApiModelProperty(value = "班组类型", example = "机加工")
    private String calendarType;

    @ApiModelProperty(value = "开始日期", example = "2023-01-01")
    private LocalDate startDate;

    @ApiModelProperty(value = "结束日期", example = "2023-12-31")
    private LocalDate endDate;

    @ApiModelProperty(value = "轮班方式", example = "白班")
    private String shiftType;

    @ApiModelProperty(value = "倒班方式", example = "按月")
    private String shiftMethod;

    @ApiModelProperty(value = "单据状态", example = "已确认")
    private String status;

}


