package com.zeroone.star.mycenter.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.mycenter.mapper.UserMapper;
import com.zeroone.star.project.j1.mycenter.dto.user.UserDTO;
import com.zeroone.star.project.j1.mycenter.entity.User;

public interface UserService extends IService<User> {
    UserDTO selectUser(Long userId);
}
