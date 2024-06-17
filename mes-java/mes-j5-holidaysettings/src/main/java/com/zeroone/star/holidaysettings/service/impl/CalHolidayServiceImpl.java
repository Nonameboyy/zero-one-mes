package com.zeroone.star.holidaysettings.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.holidaysettings.entity.CalHoliday;
import com.zeroone.star.holidaysettings.mapper.CalHolidayMapper;
import com.zeroone.star.holidaysettings.service.HolidatDataTransfer;
import com.zeroone.star.holidaysettings.service.ICalHolidayService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j5.dto.holidaysetting.HolidayDTO;
import com.zeroone.star.project.j5.dto.holidaysetting.HolidaysListDTO;
import com.zeroone.star.project.j5.query.holidaysetting.ListHolidayQuery;
import com.zeroone.star.project.j5.query.holidaysetting.SettingHolidayQuery;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.time.Year;
import java.time.YearMonth;
import java.time.format.DateTimeFormatter;
import java.util.List;

/**
 * <p>
 * 节假日设置 服务实现类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
@Service
public class CalHolidayServiceImpl extends ServiceImpl<CalHolidayMapper, CalHoliday> implements ICalHolidayService {

    @Autowired
    CalHolidayMapper calHolidayMapper;

    @Autowired
    HolidatDataTransfer HolidatDataTransfer;
    @Override
    public List<HolidayDTO> getList(ListHolidayQuery condition) {

        if (condition.getDate() == null){
            condition.setDate(LocalDate.now());
        }
        LocalDate date = condition.getDate();
        YearMonth yearMonth = YearMonth.from(date);
        //获取月份的第一天和最后一天
        LocalDate firstDay = yearMonth.atDay(1);
        LocalDate lastDay = yearMonth.atEndOfMonth();

        //将日期转化为适合数据库的日期格式，如“yyyyy-MM-dd"
        String firstDayString = firstDay.format(DateTimeFormatter.ISO_LOCAL_DATE);
        String lastDayString = lastDay.format(DateTimeFormatter.ISO_LOCAL_DATE);

        //查询指定日期范围的数据
        QueryWrapper<CalHoliday> queryWrapper = new QueryWrapper<>();
        queryWrapper.between("the_day",firstDayString, lastDayString);
        List<CalHoliday> holidaysDO = calHolidayMapper.selectList(queryWrapper);

        //将holidaysDO数据封装成HolidaysListDTO
        List<HolidayDTO> holidayDTOS = HolidatDataTransfer.toHolidayDTO(holidaysDO);
        return holidayDTOS;
    }

    @Override
    public void setHoliday(SettingHolidayQuery condition) {
        if (condition.getTheDay() == null){
            throw new RuntimeException("请输入日期");
        }

        if (condition.getHolidayType() == null  || condition.getHolidayType() == ""){
            throw new RuntimeException("请输入假期类型");
        }

        LocalDate date = condition.getTheDay();
        QueryWrapper<CalHoliday> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("the_day",date);
        CalHoliday calHoliday = calHolidayMapper.selectOne(queryWrapper);

        if (calHoliday == null){
            CalHoliday calHoliday1 = new CalHoliday();
            calHoliday1.setHolidayType(condition.getHolidayType());
            calHoliday1.setTheDay(date);
            calHolidayMapper.insert(calHoliday1);
        }else {
            calHoliday.setHolidayType(condition.getHolidayType());
            calHolidayMapper.updateById(calHoliday);
        }
    }
}
