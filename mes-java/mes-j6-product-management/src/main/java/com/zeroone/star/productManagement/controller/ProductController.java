package com.zeroone.star.productManagement.controller;

import com.zeroone.star.productManagement.service.IProductService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.ProductListDTO;
import com.zeroone.star.project.j6.product_management.ProductManageApis;
import com.zeroone.star.project.j6.product_management.dto.ProductDTO;
import com.zeroone.star.project.j6.product_management.query.ProductQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("md/product-management/products")
@Api(tags = "产品物料相关接口")
public class ProductController implements ProductManageApis {


    @Autowired
    private IProductService productService;

    @GetMapping("/list")
    @ApiOperation(value = "分页查询产品（可以添加条件")
    @Override
    public JsonVO<PageDTO<ProductDTO>> queryAll(ProductQuery query) {

        return JsonVO.success(productService.myList(query));
    }

    @DeleteMapping("/delete")
    @ApiOperation(value = "删除产品（可以批量删除）")
    @Override
    public JsonVO<String> deleteBatchProducts(ProductListDTO dto) {
        //获取ids
        List<Long> productIds = dto.getProductIds();
        //判断ids合法
        if (productIds == null || productIds.isEmpty()) {
            return JsonVO.fail("Id为空");
        }
        productService.myDelete(productIds);
        return JsonVO.success("删除成功");
    }

    @PostMapping("/update")
    @ApiOperation(value = "修改一个产品的信息")
    @Override
    public JsonVO<String> updateProduct(ProductDTO dto) {
        productService.myUpdate(dto);
        return JsonVO.success("修改成功");
    }

    @PostMapping("/add")
    @ApiOperation(value = "添加一个新的产品")
    @Override
    public JsonVO<String> addProduct(@RequestBody ProductDTO dto) {
        productService.myAdd(dto);
        return JsonVO.success("添加成功");
    }


    @GetMapping("/{id}")
    @ApiOperation(value = "根据id获得一个产品信息")
    @Override
    public JsonVO<ProductDTO> queryByID(@PathVariable Long id) {
        ProductDTO dto = productService.myGetById(id);
        return JsonVO.success(dto);
    }

}
