package com.zeroone.star.messageservice.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;

import com.zeroone.star.messageservice.entity.User;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

@Mapper
public interface UserMapper extends BaseMapper<User> {
    @Select("SELECT * FROM sys_user WHERE user_name = #{username}")
    User findByUsername(@Param("username") String username);
}
