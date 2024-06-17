package com.zeroone.star.mycenter.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j1.mycenter.dto.user.UserDTO;
import com.zeroone.star.project.j1.mycenter.entity.User;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

@Mapper
public interface UserMapper extends BaseMapper<User> {

    @Select("select  user_name, nick_name, user_type, email, phonenumber, sex, avatar,create_time from ktgmes.sys_user where user_id = #{userId}")
    UserDTO selectUserById(Long userId);
}
