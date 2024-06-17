package com.zeroone.star.sysmanagement.service.impl;

import com.zeroone.star.sysmanagement.entity.SysAutoCodeResult;
import com.zeroone.star.sysmanagement.mapper.SysAutoCodeResultMapper;
import com.zeroone.star.sysmanagement.service.ISysAutoCodeResultService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 编码生成记录表 服务实现类
 * </p>
 *
 * @author jm
 * @since 2024-06-05
 */
@Service
public class SysAutoCodeResultServiceImpl extends ServiceImpl<SysAutoCodeResultMapper, SysAutoCodeResult> implements ISysAutoCodeResultService {
    @Autowired
    private SysAutoCodeResultMapper sysAutoCodeResultMapper;
    @Override
    public void saveAutoCodeResult(SysAutoCodeResult sysAutoCodeResult) {
        sysAutoCodeResultMapper.add(sysAutoCodeResult);
    }

    @Override
    public void updateAutoCodeResult(SysAutoCodeResult sysAutoCodeResult) {
        sysAutoCodeResultMapper.updateAutoCodeResult(sysAutoCodeResult);
    }

    @Override
    public List<SysAutoCodeResult> list(SysAutoCodeResult sysAutoCodeResult) {
        return sysAutoCodeResultMapper.selectSysAutoCodeResultList(sysAutoCodeResult);
    }
}
