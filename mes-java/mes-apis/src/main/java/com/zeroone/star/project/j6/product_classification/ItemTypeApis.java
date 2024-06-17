package com.zeroone.star.project.j6.product_classification;

import com.zeroone.star.project.j6.product_classification.dto.ItemTypeDTO;
import com.zeroone.star.project.j6.product_classification.query.ItemTypeQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface ItemTypeApis {
    JsonVO<List<ItemTypeDTO>> queryItemTypeList(ItemTypeQuery query);
    JsonVO<ItemTypeDTO> getItemType(Long itemTypeId);
    JsonVO<List<ItemTypeDTO>> treeSelect(ItemTypeQuery itemTypeQuery);
    JsonVO<String> addItemType(ItemTypeDTO itemTypeDTO);
    JsonVO<String> updateItemType(ItemTypeDTO itemTypeDTO);
    JsonVO<String> deleteItemType(Long itemTypeId);
}
