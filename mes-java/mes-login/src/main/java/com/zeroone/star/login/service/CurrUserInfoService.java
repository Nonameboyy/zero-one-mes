package com.zeroone.star.login.service;

import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.j1.syslogin.vo.CurrentUserInfoVO;

/**
 * 创建者：j1-照
 */
public interface CurrUserInfoService {
	/**
	 * 获取当前用户信息
	 * @param currentUser 当前用户
	 * @return  当前用户的用于展示到前端的信息
	 */
	CurrentUserInfoVO getCurrentUserInfo(UserDTO currentUser);
}
