package com.zeroone.star.orgstructure.service;

import com.zeroone.star.orgstructure.entity.SysRole;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j1.orgstructure.dto.PageDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.SysRoleDTO;
import com.zeroone.star.project.j1.orgstructure.query.user.UserQuery;

/**
 * <p>
 * 角色信息表 服务类
 * </p>
 *
 * @author gimigimi
 * @since 2024-05-23
 */
public interface ISysRoleService extends IService<SysRole> {
    /**
     * 获取角色列表
     * @param userQuery
     * @return
     */
    PageDTO<SysRoleDTO> queryRoleList(UserQuery userQuery);


}
