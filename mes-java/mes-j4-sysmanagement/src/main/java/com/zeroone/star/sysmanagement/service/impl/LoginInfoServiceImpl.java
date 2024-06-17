package com.zeroone.star.sysmanagement.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.sysmanagement.entity.LoginInfo;
import com.zeroone.star.sysmanagement.mapper.LoginInfoMapper;
import com.zeroone.star.sysmanagement.service.LoginInfoService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 系统访问记录 服务实现类
 * </p>
 *
 * @author jingzi
 * @since 2024-05-19
 */
@Service
public class LoginInfoServiceImpl extends ServiceImpl<LoginInfoMapper, LoginInfo> implements LoginInfoService {

    @Resource
    private LoginInfoMapper loginInfoMapper;


    @Override
    public List<LoginInfo> listLoginInfo() {
        return loginInfoMapper.selectLoginInfo();
    }

    @Override
    public Long removeLoginInfo(List<Long> ids) {
        return loginInfoMapper.deleteLoginInfo(ids);
    }

    @Override
    public void clearLoginInfo() {
        loginInfoMapper.cleanLoginInfo();
    }
}
