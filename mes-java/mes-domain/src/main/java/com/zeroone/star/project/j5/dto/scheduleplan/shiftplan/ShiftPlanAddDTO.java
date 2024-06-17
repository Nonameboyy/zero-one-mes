package com.zeroone.star.project.j5.dto.scheduleplan.shiftplan;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

/**
 * <p>
 * 描述：班次计划新增Dto
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author qwert
 * @version 1.0.0
 */
@Data
@ApiModel("添加班次计划")
public class ShiftPlanAddDTO {
    @NotNull(message = "排班计划id不能为空")
    @Min(value = 1, message = "排班计划id最小值为1")
    @ApiModelProperty(value="计划id", example = "1")
    private Long planId;

    @NotNull(message = "班次序号不能为空")
    @ApiModelProperty(value="班次序号", example="2")
    private Integer orderNum;

    @NotBlank(message = "班次名称不能为空")
    @ApiModelProperty(value="班次名称", example="白班")
    private String shiftName;

    @NotBlank(message = "开始时间不能为空")
    @ApiModelProperty(value="开始时间", example="8:00")
    private String startTime;

    @NotBlank(message = "结束时间不能为空")
    @ApiModelProperty(value="结束时间", example="16:00")
    private String endTime;
}
