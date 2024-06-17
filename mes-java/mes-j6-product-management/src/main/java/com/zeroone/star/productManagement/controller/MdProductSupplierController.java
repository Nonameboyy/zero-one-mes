package com.zeroone.star.productManagement.controller;


import com.zeroone.star.productManagement.service.IMdProductSupplierService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.SupplierApis;
import com.zeroone.star.project.j6.product_management.dto.ProductSupplierListDTO;
import com.zeroone.star.project.j6.product_management.dto.SupplierDTO;
import com.zeroone.star.project.j6.product_management.dto.SupplierListDTO;
import com.zeroone.star.project.j6.product_management.query.SupplierListQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * <p>
 * 前端控制器
 * </p>
 *
 * @author smile
 * @since 2024-05-22
 */
@RestController
@RequestMapping("md/product-management/suppliers")
@Api(tags = "关联供应商相关接口")
public class MdProductSupplierController implements SupplierApis {
    @Autowired
    private IMdProductSupplierService mdProductSupplierService;

    @GetMapping("/list")
    @ApiOperation(value = "查询关联供应商列表")
    @Override
    public JsonVO<PageDTO<SupplierDTO>> querySupplierList(SupplierListQuery query) {
        Long productId = query.getProductId();
        if (productId != null && isUnvalid(productId)) {
            return JsonVO.fail(new PageDTO<>());
        }
        Long supplierId = query.getSupplierId();
        if (supplierId != null && isUnvalid(supplierId)) {
            return JsonVO.fail(new PageDTO<>());
        }

        return JsonVO.success(mdProductSupplierService.querySupplierList(query));
    }

    @PostMapping("/add")
    @ApiOperation(value = "添加关联供应商")
    @Override
    public JsonVO<String> addSupplierList(@RequestBody SupplierListDTO dto) {
        Long productId = dto.getProductId();
        if (productId != null && isUnvalid(productId)) {
            return JsonVO.fail("Invalid productId");
        }
        List<Long> supplierIds = dto.getSupplierIds();
        if (supplierIds != null && !supplierIds.isEmpty()) {
            for (Long supplierId : supplierIds) {
                if (supplierId != null && isUnvalid(supplierId)) {
                    return JsonVO.fail("Invalid supplierId");
                }
            }
        }

        return JsonVO.success(mdProductSupplierService.addSupplierList(dto));
    }

    @PutMapping("/update")
    @ApiOperation(value = "更新关联供应商")
    @Override
    public JsonVO<String> updateSupplier(SupplierDTO dto) {
        Long id = dto.getId();
        if (id != null) {
            if (isUnvalid(id)) {
                return JsonVO.fail("Invalid id");
            }
            if (mdProductSupplierService.getById(id) == null) {
                return JsonVO.fail("No record found for the given id");
            }
        }

        Long productId = dto.getProductId();
        if (productId != null && isUnvalid(productId)) {
            return JsonVO.fail("Invalid productId");
        }

        Long supplierId = dto.getSupplierId();
        if (supplierId != null && isUnvalid(supplierId)) {
            return JsonVO.fail("Invalid supplierId");
        }

        return JsonVO.success(mdProductSupplierService.updateSupplier(dto));
    }

    @DeleteMapping("/delete")
    @ApiOperation(value = "删除关联供应商")
    @Override
    public JsonVO<String> deleteBatchSupplier(ProductSupplierListDTO dto) {
        List<Long> productSupplierIds = dto.getProductSupplierIds();
        if (productSupplierIds != null && !productSupplierIds.isEmpty()) {
            for (Long productSupplierId : productSupplierIds) {
                if (productSupplierId != null && isUnvalid(productSupplierId)) {
                    return JsonVO.fail("Invalid productSupplierId");
                }
            }
        }

        return JsonVO.success(mdProductSupplierService.deleteBatchSupplier(dto));
    }

    private boolean isUnvalid(long id) {
        return id < 0;
    }
}