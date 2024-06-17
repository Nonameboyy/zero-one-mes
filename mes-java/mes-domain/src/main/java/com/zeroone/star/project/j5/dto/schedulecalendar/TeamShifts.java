package com.zeroone.star.project.j5.dto.schedulecalendar;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;

/**
 * @description:  团队班次信息
 * @program: mes-java
 * @ClassName TeamShifts
 * @author: nangua
 * @create: 2024-05-22 19:12
 * @Version 1.0
 **/
@Data
@AllArgsConstructor
@NoArgsConstructor
public class TeamShifts {
    @ApiModelProperty(value = "流水号", example = "5934")
    private int recordId;
    @ApiModelProperty(value = "日期", example = "2024-05-22")
    private LocalDate theDay;
    @ApiModelProperty(value = "班组ID", example = "225")
    private int teamId;
    @ApiModelProperty(value = "班组名称", example = "预加工1班")
    private String teamName;
    @ApiModelProperty(value = "班次ID", example = "374")
    private int shiftId;
    @ApiModelProperty(value = "班次名称", example = "白班")
    private String shiftName;
    @ApiModelProperty(value = "序号", example = "1")
    private String orderNum;
    @ApiModelProperty(value = "计划ID", example = "72")
    private int planId;
    @ApiModelProperty(value = "班组类型", example = "ZZ")
    private String calendarType;
    @ApiModelProperty(value = "轮班方式", example = "HSIFT_TWO")
    private String shiftType;
}