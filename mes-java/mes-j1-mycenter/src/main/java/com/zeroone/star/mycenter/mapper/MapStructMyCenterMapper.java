package com.zeroone.star.mycenter.mapper;

import com.zeroone.star.project.j1.mycenter.DO.sysUserDO;
import com.zeroone.star.project.j1.mycenter.dto.MyCenterDTO;
import org.mapstruct.Mapper;
import org.mapstruct.factory.Mappers;
import org.springframework.stereotype.Component;

@Mapper
public interface MapStructMyCenterMapper {
    MapStructMyCenterMapper INSTANCE = Mappers.getMapper(MapStructMyCenterMapper.class);

    MyCenterDTO SysUserDOToMyCenterDTO(sysUserDO DO);
}
