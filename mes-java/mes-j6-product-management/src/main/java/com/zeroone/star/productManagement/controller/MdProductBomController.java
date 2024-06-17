package com.zeroone.star.productManagement.controller;


import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.productManagement.service.IMdProductBomService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.BomApis;
import com.zeroone.star.project.j6.product_management.dto.BomDTO;
import com.zeroone.star.project.j6.product_management.query.BomQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * <p>
 * 产品BOM关系表 前端控制器
 * </p>
 *
 * @author panda
 * @since 2024-05-27
 */
@RestController
@RequestMapping("md/product-management/bom")
@Api(tags = "BOM部分相关接口")
public class MdProductBomController implements BomApis {
    @Autowired
    IMdProductBomService iMdProductBomService;

    @GetMapping("/list")
    @ApiOperation(value = "查询bom列表")
    @Override
    public JsonVO<PageDTO<BomDTO>> queryBomList(BomQuery query){
        return JsonVO.success(iMdProductBomService.selectProductBomsPageByItemId(query));
    }
    @PostMapping("/add")
    @ApiOperation(value = "新增bom数据")
    @Override
    public JsonVO<String> addBom(BomDTO dto) {
        if(iMdProductBomService.insertProductBom(dto)){
            return JsonVO.success("添加成功");
        }
        return JsonVO.fail("添加失败");
    }
    @PutMapping("/update")
    @ApiOperation(value = "修改bom数据")
    @Override
    public JsonVO<String> updateBom(BomDTO dto) {
        if (iMdProductBomService.updateProductBom(dto)) {
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }
    @DeleteMapping("/delete")
    @ApiOperation(value = "删除bom数据")
    @Override
    public JsonVO<String> deleteBOM(Long[] bomIds) {
        if (iMdProductBomService.deleteProductBomByIds(bomIds)) {
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("删除失败");    }
}

