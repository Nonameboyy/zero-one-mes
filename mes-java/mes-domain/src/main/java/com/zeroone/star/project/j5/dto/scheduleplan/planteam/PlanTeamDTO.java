package com.zeroone.star.project.j5.dto.scheduleplan.planteam;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;


/**
 * <p>
 * 描述：关联班组模型
 * </p>
 *
 * @author linglan
 * @version 1.0.0
 */
@Data
@ApiModel("关联班组模型")
public class PlanTeamDTO  {
    @ApiModelProperty(value = "流水号", example = "1")
    private Long recordId;
    @ApiModelProperty(value = "计划ID", example = "0")
    private Long planId;
    @ApiModelProperty(value = "班组ID", example = "1")
    private Long teamId;
    @ApiModelProperty(value = "班组编号", example = "T004")
    private String teamCode;
    @ApiModelProperty(value = "班组名称", example = "风塔2组")
    private String teamName;
    @ApiModelProperty(value = "创建时间", example = "2022-08-21 15:59:35")
    private LocalDateTime createTime;
    @ApiModelProperty(value = "备注")
    private String remark;
}

