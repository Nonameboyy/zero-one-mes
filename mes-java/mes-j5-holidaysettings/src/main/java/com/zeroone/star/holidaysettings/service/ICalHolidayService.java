package com.zeroone.star.holidaysettings.service;

import com.zeroone.star.holidaysettings.entity.CalHoliday;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j5.dto.holidaysetting.HolidayDTO;
import com.zeroone.star.project.j5.dto.holidaysetting.HolidaysListDTO;
import com.zeroone.star.project.j5.query.holidaysetting.ListHolidayQuery;
import com.zeroone.star.project.j5.query.holidaysetting.SettingHolidayQuery;

import java.util.List;

/**
 * <p>
 * 节假日设置 服务类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
public interface ICalHolidayService extends IService<CalHoliday> {
    public List<HolidayDTO> getList(ListHolidayQuery condition);

    public void setHoliday(SettingHolidayQuery condition);

}
