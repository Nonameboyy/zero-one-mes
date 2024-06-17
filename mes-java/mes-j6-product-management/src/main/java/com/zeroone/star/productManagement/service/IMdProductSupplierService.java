package com.zeroone.star.productManagement.service;

import com.zeroone.star.productManagement.entity.MdProductSupplier;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.ProductSupplierListDTO;
import com.zeroone.star.project.j6.product_management.dto.SupplierDTO;
import com.zeroone.star.project.j6.product_management.dto.SupplierListDTO;
import com.zeroone.star.project.j6.product_management.query.SupplierListQuery;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author smile
 * @since 2024-05-22
 */
public interface IMdProductSupplierService extends IService<MdProductSupplier> {

    PageDTO<SupplierDTO> querySupplierList(SupplierListQuery query);

    String addSupplierList(SupplierListDTO dto);

    String updateSupplier(SupplierDTO dto);

    String deleteBatchSupplier(ProductSupplierListDTO dto);
}
