package com.zeroone.star.orgstructure.mapper;

import com.zeroone.star.orgstructure.entity.UserDO;
import com.zeroone.star.project.j2.orgstructure.dto.role.UserRoleDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.factory.Mappers;

@Mapper(componentModel = "spring")
public interface UserConvertMapper {
    UserConvertMapper INSTANCE = Mappers.getMapper(UserConvertMapper.class);

    @Mapping(source = "userId", target = "userId")
    @Mapping(source = "userName", target = "userName")
    UserRoleDTO userDOToUserDTO(UserDO userDO);
}
