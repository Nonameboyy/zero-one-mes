package com.zeroone.star.orgstructure.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.entity.SysRole;
import com.zeroone.star.orgstructure.entity.SysUserRole;
import com.zeroone.star.orgstructure.mapper.SysRoleMapper;
import com.zeroone.star.orgstructure.service.ISysRoleService;
import com.zeroone.star.project.j1.orgstructure.dto.PageDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.SysRoleDTO;
import com.zeroone.star.project.j1.orgstructure.query.user.UserQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Mapper(componentModel="spring")
interface MsSysRoleMapper{
    SysRoleDTO sysRoleToSysRoleDTO(SysRole sysRole);
}
/**
 * <p>
 * 角色信息表 服务实现类
 * </p>
 *
 * @author gimigimi
 * @since 2024-05-23
 */
@Service
public class SysRoleServiceImpl extends ServiceImpl<SysRoleMapper, SysRole> implements ISysRoleService {
    @Resource
    SysRoleMapper sysRoleMapper;
    @Resource
    MsSysRoleMapper msSysRoleMapper;
    @Override
    public PageDTO<SysRoleDTO> queryRoleList(UserQuery userQuery) {
//        构建分页查询对象
        Page<SysRole> page = new Page<>(userQuery.getPageIndex(), userQuery.getPageSize());
        LambdaQueryWrapper<SysRole> wrapper=new LambdaQueryWrapper<>();
        wrapper.select(SysRole::getRoleId,SysRole::getRoleName,SysRole::getRoleKey,SysRole::getCreateTime);
        Page<SysRole> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result,src -> msSysRoleMapper.sysRoleToSysRoleDTO(src));
    }
}
