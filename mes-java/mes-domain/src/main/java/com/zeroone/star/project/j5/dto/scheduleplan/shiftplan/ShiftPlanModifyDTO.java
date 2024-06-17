package com.zeroone.star.project.j5.dto.scheduleplan.shiftplan;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.*;

/**
 * <p>
 * 描述：班次计划更新Dto
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author qwert
 * @version 1.0.0
 */
@Data
public class ShiftPlanModifyDTO {
    @NotNull(message = "排班计划id不能为空")
    @Min(value = 1, message = "班次计划最小值为1")
    @ApiModelProperty(value="排班计划id", example = "1")
    private Long planId;

    @NotNull(message = "班次计划id不能为空")
    @Min(value = 1, message = "班次计划最小值为1")
    @ApiModelProperty(value="班次id", example="2")
    private Long shiftId;

    @NotNull(message = "班次序号不能为空")
    @Min(value = 1, message = "班次序号最小值为1")
    @ApiModelProperty(value="班次序号", example="2")
    private Integer orderNum;

    @NotBlank(message = "班次名称不能为空")
    @ApiModelProperty(value="班次名称", example="白班")
    private String shiftName;

    @NotBlank(message = "开始时间不能为空")
//    @Pattern(regexp = "^([01]?\\d|2[0-3]):([0-5]?\\d)$", message = "开始时间格式不正确，应为HH:mm")
    @ApiModelProperty(value="开始时间", example="8:00")
    private String startTime;

    @NotBlank(message = "结束不能为空")
    @ApiModelProperty(value="结束时间", example="16:00")
    private String endTime;
}
