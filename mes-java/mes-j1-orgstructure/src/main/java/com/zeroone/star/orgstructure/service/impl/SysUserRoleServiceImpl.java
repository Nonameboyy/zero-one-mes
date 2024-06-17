package com.zeroone.star.orgstructure.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.entity.SysUserRole;
import com.zeroone.star.orgstructure.mapper.SysUserRoleMapper;
import com.zeroone.star.orgstructure.service.ISysUserRoleService;
import com.zeroone.star.project.j1.orgstructure.dto.PageDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.SysUserRoleDTO;
import com.zeroone.star.project.j1.orgstructure.query.user.UserRoleQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;

import java.util.Collections;
import java.util.List;

@Mapper(componentModel="spring")
interface MsSysUserRoleMapper{
    SysUserRoleDTO sysUserRoleToSysRoleDTO(SysUserRole sysUserRole);
}

/**
 * <p>
 * 用户和角色关联表 服务实现类
 * </p>
 *
 * @author gimigimi
 * @since 2024-05-23
 */
@Service
public class SysUserRoleServiceImpl extends ServiceImpl<SysUserRoleMapper, SysUserRole> implements ISysUserRoleService {
@Resource
MsSysUserRoleMapper msSysUserRoleMapper;
@Resource
SysUserRoleMapper sysUserRoleMapper;
    @Override
    public PageDTO<SysUserRoleDTO> queryUserRoleList(UserRoleQuery userQuery) {
        //        构建分页查询对象
        Page<SysUserRole> page=new Page<>(userQuery.getPageIndex(),userQuery.getPageSize());
//        构建查询条件
        LambdaQueryWrapper<SysUserRole> wrapper=new LambdaQueryWrapper<>();
        wrapper.eq(SysUserRole::getUserId,userQuery.getUserId());
//        执行查询
        Page<SysUserRole> result=baseMapper.selectPage(page,wrapper);
        return PageDTO.create(result,src -> msSysUserRoleMapper.sysUserRoleToSysRoleDTO(src));
    }

    @Override
    public Boolean saveRole(UserRoleQuery userQuery) {
        List<SysUserRole> sysUserRoleList = new ArrayList<>();

// 根据请求的userId和roleId添加数据
        for (Long roleId : userQuery.getRoleId()) {
            SysUserRole sysUserRole = new SysUserRole();
            sysUserRole.setUserId(userQuery.getUserId());
            sysUserRole.setRoleId(roleId);
            sysUserRoleList.add(sysUserRole);
        }
        int result=sysUserRoleMapper.saveBatchByUserIdAndRoleIds(sysUserRoleList);
        if(result>0) return true;
        return false;
    }

    @Override
    public Boolean deleteRole(UserRoleQuery userQuery) {
        List<SysUserRole> sysUserRoleList = new ArrayList<>();

// 根据请求的userId和roleId删除数据
        for (Long roleId : userQuery.getRoleId()) {
            SysUserRole sysUserRole = new SysUserRole();
            sysUserRole.setUserId(userQuery.getUserId());
            sysUserRole.setRoleId(roleId);
            sysUserRoleList.add(sysUserRole);
        }
        int result=sysUserRoleMapper.deleteBatchByUserIdAndRoleIds(sysUserRoleList);
        if(result>0) return true;
        return false;
    }
}
