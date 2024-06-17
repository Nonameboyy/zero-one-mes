package com.zeroone.star.sysmanager.mapper;

import com.zeroone.star.sysmanager.entity.SysDictType;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 * 字典类型表 Mapper 接口
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
@Mapper
public interface SysDictTypeMapper extends BaseMapper<SysDictType> {

    SysDictType selectByType(@Param("dictType") String dictType);

    int deleteDictTypeById(@Param("dictId") Long dictId);
}
