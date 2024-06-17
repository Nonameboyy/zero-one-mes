package com.zeroone.star.shopsettings.mapper;

import com.zeroone.star.shopsettings.entity.MdWorkshop;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 车间表 Mapper 接口
 * </p>
 *
 * @author interstellar
 * @since 2024-05-29
 */
@Mapper
public interface MdWorkshopMapper extends BaseMapper<MdWorkshop> {
    @Select("select workshop_name from md_workshop")
    List<String> queryMdWorkshopNameList();
}
