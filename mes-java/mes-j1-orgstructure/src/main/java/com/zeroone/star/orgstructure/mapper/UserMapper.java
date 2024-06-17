package com.zeroone.star.orgstructure.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgstructure.entity.User;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Update;

@Mapper
public interface UserMapper extends BaseMapper<User> {
	// 修改用户状态
	@Update("update sys_user set status=#{status} where user_id=#{userId}")
	int updateUserStatusById(Integer userId, Integer status);

	// 修改用户密码
	@Update("update sys_user set password=#{number} where user_id=#{userId}")
	int updateUserPasswordById(Integer userId, String number);
}
