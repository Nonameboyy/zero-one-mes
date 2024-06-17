package com.zeroone.star.project.j5.dto.schedulecalendar;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;
import java.util.List;

/**
 * @description: 排班的日历数据传输对象
 * @program: mes-java
 * @ClassName ScheduleCalendarDTO
 * @author: nangua
 * @create: 2024-05-22 19:07
 * @Version 1.0
 **/

@Data
@AllArgsConstructor
@NoArgsConstructor
public class ScheduleCalendarDTO {
        @ApiModelProperty(value = "日期", example = "2024-05-22")
        private LocalDate theDay;
//        @ApiModelProperty(value = "班次名称", example = "SINGLE")
//        private String shiftType;
        @ApiModelProperty(value = "排班情况 列表")
        private List<TeamShifts> teamShifts;
}
