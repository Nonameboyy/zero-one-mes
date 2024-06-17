package com.zeroone.star.orgstructure.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.entity.UserPost;
import com.zeroone.star.orgstructure.mapper.UserPostMapper;
import com.zeroone.star.orgstructure.service.IUserPostService;
import org.springframework.stereotype.Service;

@Service
public class UserPostServiceImpl extends ServiceImpl<UserPostMapper, UserPost> implements IUserPostService {
}
