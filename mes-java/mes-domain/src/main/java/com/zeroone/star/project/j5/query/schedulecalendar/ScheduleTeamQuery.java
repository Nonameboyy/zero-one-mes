package com.zeroone.star.project.j5.query.schedulecalendar;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import java.time.LocalDate;

/**
 * @description: 根据分类类型获取指定班组排班计划
 * @program: mes-java
 * @ClassName ScheduleQueryTeam
 * @author: nangua
 * @create: 2024-05-22 21:49
 * @Version 1.0
 **/

@Data
@ApiModel("获取指定班组类型排班计划")
public class ScheduleTeamQuery{
    @NotBlank(message = "班组类型不能为空")
    @ApiModelProperty(value = "班组类型", example = "201")
    private String teamId;

    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "日期", example = "2022-06-12")
    private LocalDate theDay;



}