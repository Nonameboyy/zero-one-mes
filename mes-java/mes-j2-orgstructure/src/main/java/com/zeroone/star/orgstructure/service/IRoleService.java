package com.zeroone.star.orgstructure.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgstructure.entity.RoleDO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.orgstructure.dto.role.RoleDTO;
import com.zeroone.star.project.j2.orgstructure.dto.role.RoleListDTO;
import com.zeroone.star.project.j2.orgstructure.dto.role.RolePermissionsDTO;
import com.zeroone.star.project.j2.orgstructure.query.role.RoleConditionQuery;
import com.zeroone.star.project.j2.orgstructure.query.role.RolePermissionsQuery;

import java.util.List;

/**
 * <p>
 * 角色信息表 服务类
 * </p>
 *
 * @author 天衍土豆
 * @since 2024-05-24
 */
public interface IRoleService extends IService<RoleDO> {
    List<RoleListDTO> listRoles();

    PageDTO<RoleListDTO> listPageRoles(RoleConditionQuery condition);

    RoleDTO getById(Integer id);

    RolePermissionsDTO getPermissions (Integer id);

    int updatePermissions (RolePermissionsQuery rolePermissionsQuery);


}
