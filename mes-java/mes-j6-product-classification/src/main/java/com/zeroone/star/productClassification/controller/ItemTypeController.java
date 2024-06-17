package com.zeroone.star.productClassification.controller;

import com.zeroone.star.productClassification.service.IItemTypeService;
import com.zeroone.star.project.j6.product_classification.ItemTypeApis;
import com.zeroone.star.project.j6.product_classification.dto.ItemTypeDTO;
import com.zeroone.star.project.j6.product_classification.query.ItemTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Api(tags = "物料产品分类管理")
@RestController
@RequestMapping("md/item-type")
public class ItemTypeController implements ItemTypeApis {
    @Autowired
    private IItemTypeService iItemTypeService;

    @ApiOperation("查询分类列表")
    @GetMapping("/list")
    @Override
    public JsonVO<List<ItemTypeDTO>> queryItemTypeList(@ApiParam(value = "查询条件") ItemTypeQuery itemTypeQuery) {
        List<ItemTypeDTO> list = iItemTypeService.selectItemTypeList(itemTypeQuery);
        return JsonVO.success(list);
    }

    @ApiOperation("查询分类详情")
    @GetMapping(value = "/{itemTypeId}")
    @Override
    public JsonVO<ItemTypeDTO> getItemType(@ApiParam(value = "分类ID") @PathVariable Long itemTypeId) {
        ItemTypeDTO itemTypeDTO = iItemTypeService.selectItemTypeById(itemTypeId);
        return JsonVO.success(itemTypeDTO);
    }

    @ApiOperation("获取树形结构数据")
    @GetMapping("/treeselect")
    @Override
    public JsonVO<List<ItemTypeDTO>> treeSelect(@ApiParam(value = "查询条件") ItemTypeQuery itemTypeQuery) {
        List<ItemTypeDTO> list = iItemTypeService.buildTreeSelect(itemTypeQuery);
        return JsonVO.success(list);
    }

    @ApiOperation("新增物料产品分类")
    @PostMapping
    @Override
    public JsonVO<String> addItemType(@ApiParam(value = "物料分类信息") @Validated @RequestBody ItemTypeDTO itemTypeDTO) {
        if (iItemTypeService.checkItemTypeCodeUnique(itemTypeDTO).equals("NOT_UNIQUE")) {
            return JsonVO.fail("分类" + itemTypeDTO.getItemTypeCode() + "编码已存在");
        }
        if (iItemTypeService.checkItemTypeNameUnique(itemTypeDTO).equals("NOT_UNIQUE")) {
            return JsonVO.fail("分类" + itemTypeDTO.getItemTypeName() + "名称已存在");
        }
        iItemTypeService.insertItemType(itemTypeDTO);
        return JsonVO.success("新增成功");
    }

    @ApiOperation("更新物料产品分类")
    @PutMapping
    @Override
    public JsonVO<String> updateItemType(@ApiParam(value = "物料分类信息") @Validated @RequestBody ItemTypeDTO itemTypeDTO) {
        if (iItemTypeService.checkItemTypeCodeUnique(itemTypeDTO).equals("NOT_UNIQUE")) {
            return JsonVO.fail("分类" + itemTypeDTO.getItemTypeCode() + "编码已存在");
        }
        if (iItemTypeService.checkItemTypeNameUnique(itemTypeDTO).equals("NOT_UNIQUE")) {
            return JsonVO.fail("分类" + itemTypeDTO.getItemTypeName() + "名称已存在");
        }
        iItemTypeService.updateItemType(itemTypeDTO);
        return JsonVO.success("更新成功");
    }

    @ApiOperation("删除物料产品分类")
    @DeleteMapping("/{itemTypeId}")
    @Override
    public JsonVO<String> deleteItemType(@ApiParam(value = "分类ID") @PathVariable Long itemTypeId) {
        if (iItemTypeService.checkHasChild(itemTypeId)) {
            return JsonVO.fail("分类下有子分类，请先删除子分类");
        }
        if (iItemTypeService.checkHasItem(itemTypeId)) {
            return JsonVO.fail("分类下有物料，请先删除物料");
        }
        iItemTypeService.removeItemType(itemTypeId);
        return JsonVO.success("删除成功");
    }

}
