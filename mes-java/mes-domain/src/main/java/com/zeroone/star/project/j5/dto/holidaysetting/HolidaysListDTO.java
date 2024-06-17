package com.zeroone.star.project.j5.dto.holidaysetting;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

/**
 * <p>
 * 描述：单日假期数据列表
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author nangua
 * @version 1.0.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class HolidaysListDTO {
    List<HolidayDTO> holidaysList;
}
