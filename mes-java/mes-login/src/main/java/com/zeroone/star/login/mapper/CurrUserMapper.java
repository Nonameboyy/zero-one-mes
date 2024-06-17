package com.zeroone.star.login.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.login.entity.*;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface CurrUserMapper extends BaseMapper {
	/**
	 * 当前用户信息
	 * @param userId
	 * @return
	 */
	//查询用户信息
	@Select("select avatar,user_name,phonenumber,email,nick_name,sex,create_time from sys_user where user_id=#{userId}")
	UserDO selectUser(Integer userId);
	//查询用户部门信息
	DeptDO selectDept(int userId);
	//查询用户角色信息
	List<RoleDO> selectRole(int userId);
	//查询用户岗位信息
	List<PostDO> selectPost(Integer userId);

}
