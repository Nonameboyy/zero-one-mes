package com.zeroone.star.project.j5.query.schedulecalendar;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import java.time.LocalDate;

/**
 * @description: 根据人员id获取指定班组排班计划
 * @program: mes-java
 * @ClassName ScheduleQueryUser
 * @author: nangua
 * @create: 2024-05-22 21:50
 * @Version 1.0
 **/

@Data
@ApiModel("获取指定人员排班计划")
public class ScheduleUserQuery{
    @NotBlank(message = "人员id不能为空")
    @ApiModelProperty(value = "人员id", example = "104")
    private String userId;

    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "日期", example = "2022-09-26")
    private LocalDate theDay;

}