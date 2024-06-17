package com.zeroone.star.productClassification.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.productClassification.entity.ItemType;
import com.zeroone.star.project.j6.product_classification.query.ItemTypeQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface ItemTypeMapper extends BaseMapper<ItemType> {
    List<ItemType> selectItemTypeList(ItemTypeQuery itemTypeQuery);
    ItemType selectItemTypeById(Long itemTypeId);
    ItemType checkItemTypeCodeUnique(@Param("itemTypeCode") String itemTypeCode, @Param("parentTypeId") Long parentTypeId);
    ItemType checkItemTypeNameUnique(@Param("itemTypeName") String itemTypeName, @Param("parentTypeId") Long parentTypeId);
    int hasChildByItemTypeId(Long parentTypeId);
    int hasItemByItemTypeId(Long itemTypeId);
    void insertItemType(ItemType itemType);
    void updateItemType(ItemType itemType);
    void deleteItemTypeById(Long itemTypeId);

}
