package com.zeroone.star.productManagement.mapper;

import com.zeroone.star.productManagement.entity.MdProductBom;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j6.product_management.dto.BomDTO;
import org.apache.ibatis.annotations.*;

import java.util.List;

/**
 * <p>
 * 产品BOM关系表 Mapper 接口
 * </p>
 *
 * @author panda
 * @since 2024-05-27
 */
@Mapper
public interface MdProductBomMapper extends BaseMapper<MdProductBom> {

    // 插入数据
    @Insert("INSERT INTO md_product_bom (bom_item_id, bom_item_code, bom_item_name, bom_item_spec, create_by, create_time, enable_flag, item_id, item_or_product, quantity, remark, unit_of_measure, update_by, update_time) " +
            "VALUES (#{dto.bomItemId}, #{dto.bomItemCode}, #{dto.bomItemName}, #{dto.bomItemSpec}, #{dto.createBy}, #{dto.createTime}, #{dto.enableFlag}, #{dto.itemId}, #{dto.itemOrProduct}, #{dto.quantity}, #{dto.remark}, #{dto.unitOfMeasure}, #{dto.updateBy}, #{dto.updateTime})")
    int insertProductBom(@Param("dto") BomDTO dto);

    // 更新数据
    @Update("UPDATE md_product_bom SET bom_item_id = #{dto.bomItemId}, bom_item_code = #{dto.bomItemCode}, bom_item_name = #{dto.bomItemName}, bom_item_spec = #{dto.bomItemSpec}, create_by = #{dto.createBy}, create_time = #{dto.createTime}, enable_flag = #{dto.enableFlag}, item_id = #{dto.itemId}, item_or_product = #{dto.itemOrProduct}, quantity = #{dto.quantity}, remark = #{dto.remark}, unit_of_measure = #{dto.unitOfMeasure}, update_by = #{dto.updateBy}, update_time = #{dto.updateTime} " +
            "WHERE bom_id = #{dto.bomId}")
    int updateProductBom(@Param("dto") BomDTO dto);

    // 删除数据
    @Delete({
            "<script>",
            "DELETE FROM md_product_bom WHERE bom_id IN",
            "<foreach item='id' collection='bomIds' open='(' separator=',' close=')'>",
            "#{id}",
            "</foreach>",
            "</script>"
    })
    int deleteProductBom(@Param("bomIds") Long[] bomIds);
}