package com.zeroone.star.schedulecalendar.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.j5.dto.schedulecalendar.ScheduleCalendarDTO;
import com.zeroone.star.project.j5.dto.schedulecalendar.TeamShifts;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleTeamQuery;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleTypeQuery;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleUserQuery;
import com.zeroone.star.schedulecalendar.entity.CalTeamMember;
import com.zeroone.star.schedulecalendar.entity.CalTeamshift;
import com.zeroone.star.schedulecalendar.mapper.CalTeamMemberMapper;
import com.zeroone.star.schedulecalendar.mapper.CalTeamshiftMapper;
import com.zeroone.star.schedulecalendar.service.ICalTeamshiftService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.schedulecalendar.service.TeamShiftTransfer;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.time.YearMonth;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * <p>
 * 班组排班表 服务实现类
 * </p>
 *
 * @author nangua
 * @since 2024-05-28
 */
@Service
public class CalTeamshiftServiceImpl extends ServiceImpl<CalTeamshiftMapper, CalTeamshift> implements ICalTeamshiftService {



    @Autowired
    CalTeamshiftMapper calTeamshiftMapper;
    @Autowired
    TeamShiftTransfer teamShiftTransfer;

    @Autowired
    CalTeamMemberMapper calTeamMemberMapper;
    @Override
    public List<ScheduleCalendarDTO> listSchedule(ScheduleTypeQuery condition) {

        if (condition.getCalendarType() == null){
            throw new RuntimeException("请输入排班类型");
        }

        String[] fristAndLastDay = getFristAndLastDay(condition.getTheDay());

        //查询指定日期范围的数据
        QueryWrapper<CalTeamshift> queryWrapper = new QueryWrapper();
        CalTeamshift calTeamshift = teamShiftTransfer.queryTypeToTeamshiftDO(condition);



        queryWrapper.between("the_day",fristAndLastDay[0], fristAndLastDay[1]);


        queryWrapper.eq("calendar_type", calTeamshift.getCalendarType());
        //查询
        List<CalTeamshift> calTeamshifts = calTeamshiftMapper.selectList(queryWrapper);
        //DO转DTO
        List<TeamShifts> teamShiftsList = teamShiftTransfer.teamshiftDOToShiftDTO(calTeamshifts);

        return groupByDate(teamShiftsList);
    }

    @Override
    public List<ScheduleCalendarDTO> listSchedule(ScheduleTeamQuery condition) {
        if (condition.getTeamId() == null){
            throw new RuntimeException("请输入班组id");
        }


        String[] fristAndLastDay = getFristAndLastDay(condition.getTheDay());

        //查询指定日期范围的数据
        QueryWrapper<CalTeamshift> queryWrapper = new QueryWrapper();
        CalTeamshift calTeamshift = teamShiftTransfer.queryTeamToTeamshiftDO(condition);

        queryWrapper.between("the_day",fristAndLastDay[0], fristAndLastDay[1]);



        queryWrapper.eq("team_id", calTeamshift.getTeamId());

        //查询
        List<CalTeamshift> calTeamshifts = calTeamshiftMapper.selectList(queryWrapper);
        //DO转DTO
        List<TeamShifts> teamShiftsList = teamShiftTransfer.teamshiftDOToShiftDTO(calTeamshifts);

        return groupByDate(teamShiftsList);
    }

    @Override
    public List<ScheduleCalendarDTO> listSchedule(ScheduleUserQuery condition) {
        if (condition.getUserId() == null){
            throw new RuntimeException("请输入人员id");
        }
        QueryWrapper<CalTeamMember> queryWrapper = new QueryWrapper();
        queryWrapper.eq("user_id",condition.getUserId());

        List<CalTeamMember> calTeamMembers = calTeamMemberMapper.selectList(queryWrapper);
        if (calTeamMembers.size() == 0){
            throw new RuntimeException("该用户未加入任何班组");
        }
        Long teamId = calTeamMembers.get(0).getTeamId();
        ScheduleTeamQuery scheduleTeamQuery = new ScheduleTeamQuery();
        scheduleTeamQuery.setTeamId(teamId.toString());
        scheduleTeamQuery.setTheDay(condition.getTheDay());
        return listSchedule(scheduleTeamQuery);

    }

//    public List<ScheduleCalendarDTO> selectTheTable(){
//
//    }

    public String[] getFristAndLastDay(LocalDate date){
        if (date == null){
            //设置为当天日期
            date = LocalDate.now();
        }
        YearMonth yearMonth = YearMonth.from(date);
        //获取月份的第一天和最后一天
        LocalDate firstDay = yearMonth.atDay(1);
        LocalDate lastDay = yearMonth.atEndOfMonth();

        //将日期转化为适合数据库的日期格式，如“yyyyy-MM-dd"
        String firstDayString = firstDay.format(DateTimeFormatter.ISO_LOCAL_DATE);
        String lastDayString = lastDay.format(DateTimeFormatter.ISO_LOCAL_DATE);
        String[] fristAndLastDay ={firstDayString,lastDayString};

        return fristAndLastDay;
    }


    public List<ScheduleCalendarDTO> groupByDate(List<TeamShifts> teamShiftsList){
        List<ScheduleCalendarDTO> scheduleCalendarDTOList = new ArrayList<>();
        //把集合中的数据按照日期分组

        // 按照日期分组
        Map <LocalDate,List<TeamShifts>> groupedByDate = teamShiftsList.stream()
                .filter(teamShifts -> teamShifts.getTheDay() != null)
                .collect(Collectors.groupingBy(TeamShifts::getTheDay));
        // 遍历分组结果，进行处理
        for (Map.Entry<LocalDate, List<TeamShifts>> entry : groupedByDate.entrySet()) {
            LocalDate dateEntry = entry.getKey();
            List<TeamShifts> shiftsForDate = entry.getValue();

            // 创建并填充 ScheduleCalendarDTO 对象
            ScheduleCalendarDTO scheduleCalendarDTO = new ScheduleCalendarDTO();
            scheduleCalendarDTO.setTheDay(dateEntry);
            scheduleCalendarDTO.setTeamShifts(shiftsForDate);

            scheduleCalendarDTOList.add(scheduleCalendarDTO);
        }
        return scheduleCalendarDTOList;
    }
}
