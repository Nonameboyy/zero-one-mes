package com.zeroone.star.project.j6.product_management;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.ProductSupplierListDTO;
import com.zeroone.star.project.j6.product_management.dto.SupplierDTO;
import com.zeroone.star.project.j6.product_management.dto.SupplierListDTO;
import com.zeroone.star.project.j6.product_management.query.SupplierListQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：用户登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface SupplierApis {
    JsonVO<PageDTO<SupplierDTO>> querySupplierList(SupplierListQuery query);
    JsonVO<String> addSupplierList(SupplierListDTO dto);
    JsonVO<String> updateSupplier(SupplierDTO dto);
    JsonVO<String> deleteBatchSupplier(ProductSupplierListDTO dto);
}
