package com.zeroone.star.schedulecalendar.service;


import com.zeroone.star.project.j5.dto.schedulecalendar.TeamShifts;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleTeamQuery;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleTypeQuery;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleUserQuery;
import com.zeroone.star.schedulecalendar.entity.CalTeamshift;
import org.mapstruct.Mapper;
import org.mapstruct.factory.Mappers;
import org.springframework.stereotype.Service;

import java.util.List;


@Mapper(componentModel = "spring")
@Service
public interface TeamShiftTransfer {
    TeamShiftTransfer INSTANCE = Mappers.getMapper(TeamShiftTransfer.class);

    CalTeamshift queryTeamToTeamshiftDO(ScheduleTeamQuery condition);
    CalTeamshift queryTypeToTeamshiftDO(ScheduleTypeQuery condition);
    CalTeamshift queryUserToTeamshiftDO(ScheduleUserQuery condition);

    List<TeamShifts> teamshiftDOToShiftDTO(List<CalTeamshift> calTeamshift);

}
