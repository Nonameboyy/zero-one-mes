package com.zeroone.star.schedulecalendar.controller;

import com.zeroone.star.project.j5.dto.schedulecalendar.ScheduleCalendarDTO;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleTeamQuery;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleTypeQuery;
import com.zeroone.star.project.j5.query.schedulecalendar.ScheduleUserQuery;
import com.zeroone.star.project.j5.schedulecalendar.ScheduleCalendarApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.schedulecalendar.service.impl.CalTeamshiftServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * @description: 排班日历 查询
 * @program: mes-java
 * @ClassName ScheduleCalendarIMP
 * @author: nangua
 * @create: 2024-05-22 19:45
 * @Version 1.0
 **/

@RestController
@RequestMapping("calendar")
@Api(tags = "排班日历")
public class ScheduleCalendarController implements ScheduleCalendarApis {

    @Resource
    CalTeamshiftServiceImpl calTeamshiftService;


    @GetMapping("/list-by-type")
    @ApiOperation("获取指定班组类型排班计划")
    @Override
    public JsonVO<List<ScheduleCalendarDTO>> listScheduleByType(ScheduleTypeQuery condition) {

        List<ScheduleCalendarDTO> scheduleCalendarDTOList = calTeamshiftService.listSchedule(condition);
        return  JsonVO.success(scheduleCalendarDTOList);
    }
    @GetMapping("/list-by-team")
    @ApiOperation("获取指定班组排班计划")
    @Override
    public JsonVO<List<ScheduleCalendarDTO>> listScheduleByTeam(ScheduleTeamQuery condition) {

        List<ScheduleCalendarDTO> scheduleCalendarDTOList = calTeamshiftService.listSchedule(condition);
        return JsonVO.success(scheduleCalendarDTOList);
    }
    @GetMapping("/list-by-user")
    @ApiOperation("获取指定人员排班计划")
    @Override
    public JsonVO<List<ScheduleCalendarDTO>> listScheduleByTeam(ScheduleUserQuery condition) {

        List<ScheduleCalendarDTO> scheduleCalendarDTOList = calTeamshiftService.listSchedule(condition);
        return JsonVO.success(scheduleCalendarDTOList);
    }




}
