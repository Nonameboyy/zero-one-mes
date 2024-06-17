package com.zeroone.star.productManagement.service;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.productManagement.entity.MdProductBom;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.BomDTO;
import com.zeroone.star.project.j6.product_management.query.BomQuery;

import java.util.List;

/**
 * <p>
 * 产品BOM关系表 服务类
 * </p>
 *
 * @author panda
 * @since 2024-05-27
 */
public interface IMdProductBomService extends IService<MdProductBom> {
    /**
     * 新增bom项
     * @param dto 新增条件
     * @return 新增是否成功
     */
    boolean insertProductBom(BomDTO dto);

    /**
     * 更新bom项
     * @param dto 更新后的结果
     * @return 更新是否成功
     */
    boolean updateProductBom(BomDTO dto);

    /**
     * 根据 bomIds 来批量删除
     * @param ids bomId列表
     * @return 是否全部删除成功
     */
    boolean deleteProductBomByIds(Long[] ids);

    /**
     * 根据 ItemId 进行分页查询
     * @param query 查询体
     * @return 所有查询到的BomDTO列表
     */
    PageDTO<BomDTO> selectProductBomsPageByItemId(BomQuery query);
}
