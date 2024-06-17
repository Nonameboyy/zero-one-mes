package com.zeroone.star.sysmanagement.service;

import com.zeroone.star.sysmanagement.entity.SysAutoCodeResult;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 编码生成记录表 服务类
 * </p>
 *
 * @author jm
 * @since 2024-06-05
 */
public interface ISysAutoCodeResultService extends IService<SysAutoCodeResult> {

    void saveAutoCodeResult(SysAutoCodeResult sysAutoCodeResult);

    void updateAutoCodeResult(SysAutoCodeResult sysAutoCodeResult);

    public List<SysAutoCodeResult> list(SysAutoCodeResult sysAutoCodeResult);
}
