package com.zeroone.star.project.j5.query.scheduleplan.planteam;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;


/**
 * <p>
 * 描述：查询关联班组
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("查询关联班组对象")
public class PlanTeamQuery extends PageQuery {
    @NotNull(message = "计划ID不能为空")
    @Min(value = 1, message = "计划ID不能小于1")
    @ApiModelProperty(value = "计划ID", example = "0", required = true)
    private Long planId;
}
