package com.zeroone.star.schedulecalendar.service;

import com.zeroone.star.project.j5.dto.schedulecalendar.ScheduleCalendarDTO;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleTeamQuery;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleTypeQuery;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleUserQuery;
import com.zeroone.star.schedulecalendar.entity.CalTeamshift;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 班组排班表 服务类
 * </p>
 *
 * @author nangua
 * @since 2024-05-28
 */
public interface ICalTeamshiftService extends IService<CalTeamshift> {

    public List<ScheduleCalendarDTO> listSchedule(ScheduleTypeQuery condition);
    public List<ScheduleCalendarDTO> listSchedule(ScheduleTeamQuery condition);
    public List<ScheduleCalendarDTO> listSchedule(ScheduleUserQuery condition);


}
