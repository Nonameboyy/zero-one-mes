package com.zeroone.star.project.j5.query.scheduleplan;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDate;

/**
 * <p>
 * 描述：分页+条件查询排班计划数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author brickbreaker
 * @version 1.0.0
 */
@Data
@ApiModel("查询排班计划数据对象")
public class PlanPageQuery extends PageQuery {

    @ApiModelProperty(value = "班组类型",example = "ZS")
    private String calendarType;

    @ApiModelProperty(value = "计划编号",example = "PLAN20240511")
    private String planCode;

    @ApiModelProperty(value = "计划名称",example = "PlanA")
    private String planName;

    @ApiModelProperty(value = "开始日期",example = "2024-05-19")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDate startDate;

    @ApiModelProperty(value = "结束日期",example = "2024-05-31")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private  LocalDate endDate;

}


