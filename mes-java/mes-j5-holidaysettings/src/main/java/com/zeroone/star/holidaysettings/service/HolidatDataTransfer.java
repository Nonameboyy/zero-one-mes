package com.zeroone.star.holidaysettings.service;

import com.zeroone.star.holidaysettings.entity.CalHoliday;
import com.zeroone.star.project.j5.dto.holidaysetting.HolidayDTO;
import org.mapstruct.Mapper;
import org.mapstruct.factory.Mappers;

import java.util.List;

@Mapper(componentModel = "spring")
public interface HolidatDataTransfer {
    //
    HolidatDataTransfer INSTANCE = Mappers.getMapper(HolidatDataTransfer.class);

    List<HolidayDTO> toHolidayDTO(List<CalHoliday> calHoliday);


}
