package com.zeroone.star.project.j5.vo.schedulecalendar;

import lombok.Data;

import java.util.Date;
import java.util.List;

/**
 * @projectName: mes-java
 * @package: com.zeroone.star.project.j5.query.schedulecalendar.j5.vo.schedulecalendar
 * @className: ScheduleCalendarVo
 * @author: junhan Zhao
 * @description: TODO
 * @date: 2024/5/20 10:55
 * @version: 1.0
 */
@Data
public class CalCalendarVO extends BaseEntity {

    private static final long serialVersionUID = 1L;

    /**
     * 查询参数部分
     */
    private String queryType;

    private Date date;

    private String calendarType;

    private Long teamId;

    private Long userId;


    /**
     * 返回值部分
     */
    private String theDay;

    private String shiftType;

    private List<CalTeamshift> teamShifts;
}
