package com.zeroone.star.orgstructure.service.impl;

import com.zeroone.star.orgstructure.mapper.UserMapper;
import com.zeroone.star.orgstructure.service.IService;
import com.zeroone.star.project.j1.orgstructure.dto.user.UpdateUserStatusDTO;

import javax.annotation.Resource;

@org.springframework.stereotype.Service
public class ServiceImpl implements IService {
	@Resource
	private UserMapper userMapper;

	/**
	 * 根据用户id设置用户状态
	 * @param userIdStatus 封装了传递进来的用户id和用户状态
	 * @return 影响的行数
	 */
	@Override
	public int UpdateUserStatus(UpdateUserStatusDTO userIdStatus) {
		return userMapper.updateUserStatusById(userIdStatus.getUser_id(),userIdStatus.getStatus());
	}

	/**
	 * 根据用户id设置用户密码为123456
	 * @param userId 用户id
	 * @return 影响的行数
	 */
	@Override
	public int UpdateUserPassword(Integer userId) {
		return userMapper.updateUserPasswordById(userId,"123456");
	}
}
