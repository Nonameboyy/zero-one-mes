package com.zeroone.star.sysmanager.mapper;

import com.zeroone.star.sysmanager.entity.SysDictData;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * <p>
 * 字典数据表 Mapper 接口
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
@Mapper
public interface SysDictDataMapper extends BaseMapper<SysDictData> {

    List<SysDictData> selectDictDataByType(@Param("dictType") String dictType);

    ArrayList<SysDictData> selectDictDataList(SysDictData dictData);

    int countDictDataByType(String dictType);

    int updateDictDataType(@Param("oldType") String oldType, @Param("dictType") String dictType);
}
