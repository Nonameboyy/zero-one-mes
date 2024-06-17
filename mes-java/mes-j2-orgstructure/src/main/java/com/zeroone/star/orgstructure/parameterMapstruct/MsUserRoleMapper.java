package com.zeroone.star.orgstructure.parameterMapstruct;

import com.zeroone.star.orgstructure.entity.UserDO;

import com.zeroone.star.project.j2.orgstructure.dto.role.UserRoleDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsUserRoleMapper {

    UserRoleDTO userDOToUserDTO(UserDO userDO);
}
