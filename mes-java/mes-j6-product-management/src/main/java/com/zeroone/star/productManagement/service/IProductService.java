package com.zeroone.star.productManagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.productManagement.entity.MdItem;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.ProductDTO;
import com.zeroone.star.project.j6.product_management.query.ProductQuery;

import java.util.List;

public interface IProductService extends IService<MdItem> {
    ProductDTO myGetById(Long id);

    
    void myDelete(List<Long> productIds);

    void myUpdate(ProductDTO dto);

    void myAdd(ProductDTO dto);

    PageDTO<ProductDTO> myList(ProductQuery query);
}
