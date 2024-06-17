package com.zeroone.star.basicdata.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.basicdata.entity.MdUnitMeasure;
import com.zeroone.star.basicdata.entity.MdVendor;
import com.zeroone.star.project.dto.j4.basicdata.VendorExcelSelectDTO;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 供应商表 Mapper 接口
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-21
 */
@Mapper
public interface MdVendorMapper extends BaseMapper<MdVendor> {

    /*
    * 根据条件查询供应商数据
    * */
    List<MdVendor> listVendor(VendorExcelSelectDTO vendorExcelSelectDTO);

    @Select("select * from md_vendor where vendor_id = #{vendorId}")
    MdVendor getById(Long vendorId);

    @Delete("delete from md_vendor where vendor_id = #{vendorId}")
    void deleteVendor(Integer vendorId);
}
