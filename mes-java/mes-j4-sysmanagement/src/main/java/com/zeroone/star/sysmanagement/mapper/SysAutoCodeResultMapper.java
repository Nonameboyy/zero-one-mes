package com.zeroone.star.sysmanagement.mapper;

import com.zeroone.star.sysmanagement.entity.SysAutoCodeResult;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 编码生成记录表 Mapper 接口
 * </p>
 *
 * @author jm
 * @since 2024-06-05
 */
@Mapper
public interface SysAutoCodeResultMapper extends BaseMapper<SysAutoCodeResult> {

    void add(SysAutoCodeResult sysAutoCodeResult);

    void updateAutoCodeResult(SysAutoCodeResult sysAutoCodeResult);

    List<SysAutoCodeResult> selectSysAutoCodeResultList(SysAutoCodeResult sysAutoCodeResult);
}
