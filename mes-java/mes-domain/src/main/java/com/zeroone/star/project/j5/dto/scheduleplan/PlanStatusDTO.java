package com.zeroone.star.project.j5.dto.scheduleplan;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.sql.Timestamp;
import java.time.LocalDate;

@Data
@ApiModel("排班计划数据传输对象")
public class PlanStatusDTO {
    @ApiModelProperty(value = "计划id")
    private int planId;
    @ApiModelProperty(value = "计划状态",example = "确认")
    private String status;
}
