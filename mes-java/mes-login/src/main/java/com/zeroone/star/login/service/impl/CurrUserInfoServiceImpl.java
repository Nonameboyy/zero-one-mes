package com.zeroone.star.login.service.impl;

import com.zeroone.star.login.entity.DeptDO;
import com.zeroone.star.login.entity.PostDO;
import com.zeroone.star.login.entity.RoleDO;
import com.zeroone.star.login.entity.UserDO;
import com.zeroone.star.login.mapper.CurrUserMapper;
import com.zeroone.star.login.service.CurrUserInfoService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.j1.syslogin.vo.CurrentUserInfoVO;
import com.zeroone.star.project.j1.syslogin.vo.currUserInfovo.PostVO;
import com.zeroone.star.project.j1.syslogin.vo.currUserInfovo.RoleVO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class CurrUserInfoServiceImpl implements CurrUserInfoService {
	@Resource
	CurrUserMapper currUserMapper;
	@Override
	public CurrentUserInfoVO getCurrentUserInfo(UserDTO currentUser) {
		//提取用户ID
		int userId = currentUser.getId();
		//创建当前用户信息（封装当前用户信息用于返回给前端）
		CurrentUserInfoVO currentUserInfoVO = new CurrentUserInfoVO();
		//查询出各个表对应的信息
		UserDO user = currUserMapper.selectUser(userId);                            //用户信息
		DeptDO dept = currUserMapper.selectDept(userId);           				    //部门信息
		List<RoleDO> roleDOList = currUserMapper.selectRole(userId);				//角色信息
		List<PostDO> postDOList = currUserMapper.selectPost(userId);                //岗位信息
		//封装当前用户信息
		if (user != null) {
			currentUserInfoVO.setAvatar(user.getAvatar());
			currentUserInfoVO.setUser_name(user.getUserName());
			currentUserInfoVO.setPhonenumber(user.getPhoneNumber());
			currentUserInfoVO.setEmail(user.getEmail());
			currentUserInfoVO.setNickName(user.getNickName());
			currentUserInfoVO.setSex(user.getSex());
			currentUserInfoVO.setCreateTime(user.getCreateTime());
		}
		//封装部门信息
		if (dept != null) {
			currentUserInfoVO.setDept_name(dept.getDeptName());
		}
		//封装角色信息
		if (roleDOList.size() != 0) {
			for (RoleDO roleDO : roleDOList){
				RoleVO roleVO = new RoleVO();
				BeanUtils.copyProperties(roleDO,roleVO);
				currentUserInfoVO.setRoleInfo(roleVO);
			}
		}
		//封装岗位信息
		PostVO postVO = new PostVO();
		if (postDOList.size() != 0){
			for (PostDO postDO : postDOList){
				BeanUtils.copyProperties(postDO,postVO);
				currentUserInfoVO.setPost(postVO);
			}
		}

		return currentUserInfoVO;
	}
}
