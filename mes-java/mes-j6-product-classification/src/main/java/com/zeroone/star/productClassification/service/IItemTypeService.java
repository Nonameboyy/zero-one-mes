package com.zeroone.star.productClassification.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.productClassification.entity.ItemType;
import com.zeroone.star.project.j6.product_classification.dto.ItemTypeDTO;
import com.zeroone.star.project.j6.product_classification.query.ItemTypeQuery;

import java.util.List;

public interface IItemTypeService extends IService<ItemType> {
    List<ItemTypeDTO> selectItemTypeList(ItemTypeQuery itemTypeQuery);
    ItemTypeDTO selectItemTypeById(Long itemTypeId);
    List<ItemTypeDTO> buildTreeSelect(ItemTypeQuery itemTypeQuery);
    String checkItemTypeCodeUnique(ItemTypeDTO itemTypeDTO);
    String checkItemTypeNameUnique(ItemTypeDTO itemTypeDTO);
    void insertItemType(ItemTypeDTO itemTypeDTO);
    void updateItemType(ItemTypeDTO itemTypeDTO);
    void removeItemType(Long itemTypeId);
    boolean checkHasChild(Long itemTypeId);
    boolean checkHasItem(Long itemTypeId);
}