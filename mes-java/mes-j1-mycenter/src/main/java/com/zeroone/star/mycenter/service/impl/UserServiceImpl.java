package com.zeroone.star.mycenter.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.mycenter.mapper.UserMapper;
import com.zeroone.star.mycenter.service.UserService;
import com.zeroone.star.project.j1.mycenter.dto.user.UserDTO;
import com.zeroone.star.project.j1.mycenter.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserServiceImpl extends ServiceImpl<UserMapper,User> implements UserService {

    @Autowired
    private UserMapper userMapper;

    @Override
    public UserDTO selectUser(Long userId) {
        return userMapper.selectUserById(userId);
    }
}
