package com.zeroone.star.orgstructure.service.impl;

import com.zeroone.star.orgstructure.entity.UserDO;
import com.zeroone.star.orgstructure.mapper.UserMapper;
import com.zeroone.star.orgstructure.service.UserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 用户信息表 服务实现类
 * </p>
 *
 * @author 爱吃猫的鱼
 * @since 2024-05-22
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, UserDO> implements UserService {

}
