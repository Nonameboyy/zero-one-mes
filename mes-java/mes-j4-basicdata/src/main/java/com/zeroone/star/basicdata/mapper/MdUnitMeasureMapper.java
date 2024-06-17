package com.zeroone.star.basicdata.mapper;

import com.zeroone.star.basicdata.entity.MdUnitMeasure;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j4.basicdata.UnitMeasureDTO;
import org.apache.ibatis.annotations.Mapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.basicdata.entity.MdUnitMeasure;
import com.zeroone.star.project.dto.j4.basicdata.UnitExcelSelectDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.io.Serializable;
import java.util.Collection;
import java.util.List;

/**
 * <p>
 * 单位表 Mapper 接口
 * </p>
 *
 * @author zjx
 * @since 2024-05-20
 */
@Mapper
public interface MdUnitMeasureMapper extends BaseMapper<MdUnitMeasure> {

    /*
    * 批量删除单位
    * */
    Long deleteByIds(List<Long> idList);

    /*
    * 根据条件查询单位数据
    * */
    List<MdUnitMeasure> listUnitMeasure(UnitExcelSelectDTO unitExcelSelectDTO);

    /**
     * 查询单位列表
     * @param unitMeasureDTO
     * @return
     */
    List<UnitMeasureDTO> selectMdUnitMeasureList(UnitMeasureDTO unitMeasureDTO);
}
