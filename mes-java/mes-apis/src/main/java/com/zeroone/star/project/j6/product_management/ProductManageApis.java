package com.zeroone.star.project.j6.product_management;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.ProductDTO;
import com.zeroone.star.project.dto.ProductListDTO;
import com.zeroone.star.project.j6.product_management.query.ProductQuery;
import com.zeroone.star.project.vo.JsonVO;


public interface ProductManageApis {


    //条件查询产品列表
    JsonVO<PageDTO<ProductDTO>> queryAll(ProductQuery query);

    //批量删除产品
    JsonVO<String> deleteBatchProducts(ProductListDTO dto);

    //修改产品
    JsonVO<String> updateProduct(ProductDTO dto);

    //新增产品
    JsonVO<String> addProduct(ProductDTO dto);

    //根据id查询产品
    JsonVO<ProductDTO> queryByID(Long id);

}
