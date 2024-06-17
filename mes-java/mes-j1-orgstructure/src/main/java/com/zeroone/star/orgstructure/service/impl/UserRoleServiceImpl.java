package com.zeroone.star.orgstructure.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.entity.UserRole;
import com.zeroone.star.orgstructure.mapper.UserRoleMapper;
import com.zeroone.star.orgstructure.service.IUserRoleService;
import org.springframework.stereotype.Service;

@Service
public class UserRoleServiceImpl extends ServiceImpl<UserRoleMapper, UserRole> implements IUserRoleService {
}
