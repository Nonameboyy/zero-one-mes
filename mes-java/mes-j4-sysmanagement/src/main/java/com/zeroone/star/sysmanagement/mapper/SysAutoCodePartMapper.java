package com.zeroone.star.sysmanagement.mapper;

import com.zeroone.star.sysmanagement.entity.SysAutoCodePart;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 编码生成规则组成表 Mapper 接口
 * </p>
 *
 * @author jm
 * @since 2024-05-21
 */
@Mapper
public interface SysAutoCodePartMapper extends BaseMapper<SysAutoCodePart> {

    List<SysAutoCodePart> selectSysAutoCodePartList(SysAutoCodePart sysAutoCodePart);
}
