package com.zeroone.star.productManagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.productManagement.entity.ProductSop;
import com.zeroone.star.project.j6.product_management.dto.ProductSopDTO;
import com.zeroone.star.project.j6.product_management.query.ProductSopQuery;
import org.apache.ibatis.annotations.*;

import java.util.List;
@Mapper
public interface ProductSopMapper extends BaseMapper<ProductSop> {
    /**
     * 查询产品SOP列表
     * @param query 查询条件
     * @return 查询结果
     */
    List<ProductSopDTO> selectProductSopPage(ProductSopQuery query);
    @Select("SELECT * FROM md_product_sop WHERE sop_id = #{id}")
    ProductSopDTO selectProductSopById(Long id);

    @Insert("INSERT INTO md_product_sop (sop_id, item_id, ...) VALUES (#{sopId}, #{itemId}, ...)")
    void insertProductSop(ProductSopDTO dto);

    @Update("UPDATE md_product_sop SET item_id=#{itemId}, ... WHERE sop_id=#{sopId}")
    void updateProductSop(ProductSopDTO dto);


    @Delete({"<script>",
            "DELETE FROM md_product_sop WHERE sop_id IN",
            "<foreach item='sopId' index='index' collection='array' open='(' separator=',' close=')'>",
            "#{sopId}",
            "</foreach>",
            "</script>"})
    void deleteProductSopByIds(Long[] ids);


}
