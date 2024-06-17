package com.zeroone.star.project.j5.holidaysettings;

import com.zeroone.star.project.j5.dto.holidaysetting.HolidayDTO;
import com.zeroone.star.project.j5.dto.holidaysetting.HolidaysListDTO;
import com.zeroone.star.project.j5.query.holidaysetting.ListHolidayQuery;
import com.zeroone.star.project.j5.query.holidaysetting.SettingHolidayQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

import java.util.List;

/**
 * <p>
 * 描述：节假日设置接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author interstellar
 * @version 1.0.0
 */
public interface HolidaySettingsApis {
    /**
     * 获取节假日配置
     * @return 返回节假日配置列表
     */
    public JsonVO<List<HolidayDTO>> listHoliday(ListHolidayQuery condition);

    /**
     * 设置节假日配置
     * @param condition
     * @return 返回状态码
     */
    public JsonVO<Boolean> setHoliday(SettingHolidayQuery condition);

}
