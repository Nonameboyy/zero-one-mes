package com.zeroone.star.orgstructure.service;

import com.zeroone.star.project.j1.orgstructure.dto.user.UpdateUserStatusDTO;

public interface IService {
	/**
	 * 根据用户id设置用户状态
	 * @param userIdStatus 封装了传递进来的用户id和用户状态
	 * @return 影响的行数
	 */
	int UpdateUserStatus(UpdateUserStatusDTO userIdStatus);
	/**
	 * 根据用户id设置用户密码为123456
	 * @param userId 用户id
	 * @return 影响的行数
	 */
	int UpdateUserPassword(Integer userId);
}
