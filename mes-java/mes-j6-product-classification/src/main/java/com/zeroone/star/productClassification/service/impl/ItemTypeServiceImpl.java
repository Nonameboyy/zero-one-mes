package com.zeroone.star.productClassification.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.productClassification.entity.ItemType;
import com.zeroone.star.productClassification.mapper.ItemTypeMapper;
import com.zeroone.star.productClassification.service.IItemTypeService;
import com.zeroone.star.project.j6.product_classification.dto.ItemTypeDTO;
import com.zeroone.star.project.j6.product_classification.query.ItemTypeQuery;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class ItemTypeServiceImpl extends ServiceImpl<ItemTypeMapper, ItemType> implements IItemTypeService {

    @Autowired
    private ItemTypeMapper itemTypeMapper;

    @Override
    public List<ItemTypeDTO> selectItemTypeList(ItemTypeQuery itemTypeQuery) {
        return itemTypeMapper.selectItemTypeList(itemTypeQuery).stream().map(itemType -> {
            ItemTypeDTO dto = new ItemTypeDTO();
            BeanUtils.copyProperties(itemType, dto);
            return dto;
        }).collect(Collectors.toList());
    }

    @Override
    public ItemTypeDTO selectItemTypeById(Long itemTypeId) {
        ItemType itemType = itemTypeMapper.selectItemTypeById(itemTypeId);
        ItemTypeDTO dto = new ItemTypeDTO();
        BeanUtils.copyProperties(itemType, dto);
        return dto;
    }

    @Override
    public List<ItemTypeDTO> buildTreeSelect(ItemTypeQuery itemTypeQuery) {
        List<ItemTypeDTO> itemTypeList = this.selectItemTypeList(itemTypeQuery);
        List<ItemType> itemTypes = itemTypeList.stream().map(dto -> {
            ItemType itemType = new ItemType();
            BeanUtils.copyProperties(dto, itemType);
            return itemType;
        }).collect(Collectors.toList());
        List<ItemType> tree = this.buildTree(itemTypes);
        return tree.stream().map(itemType -> {
            ItemTypeDTO dto = new ItemTypeDTO();
            BeanUtils.copyProperties(itemType, dto);
            return dto;
        }).collect(Collectors.toList());
    }

    private List<ItemType> buildTree(List<ItemType> itemTypes) {
        List<ItemType> returnList = new ArrayList<>();
        List<Long> tempList = new ArrayList<>();
        for (ItemType it : itemTypes) {
            tempList.add(it.getItemTypeId());
        }

        for (ItemType it : itemTypes) {
            if (!tempList.contains(it.getParentTypeId())) {
                recursionFn(itemTypes, it);
                returnList.add(it);
            }
        }
        if (returnList.isEmpty()) {
            returnList = itemTypes;
        }
        return returnList;
    }

    private void recursionFn(List<ItemType> list, ItemType t) {
        List<ItemType> childList = getChildList(list, t);
        t.setChildren(childList);
        for (ItemType tChild : childList) {
            if (hasChild(list, tChild)) {
                recursionFn(list, tChild);
            }
        }
    }

    private List<ItemType> getChildList(List<ItemType> list, ItemType t) {
        List<ItemType> tlist = new ArrayList<>();
        for (ItemType n : list) {
            if (n.getParentTypeId() != null && n.getParentTypeId().equals(t.getItemTypeId())) {
                tlist.add(n);
            }
        }
        return tlist;
    }

    private boolean hasChild(List<ItemType> list, ItemType t) {
        return getChildList(list, t).size() > 0;
    }

    @Override
    public String checkItemTypeCodeUnique(ItemTypeDTO itemTypeDTO) {
        ItemType itemType = itemTypeMapper.checkItemTypeCodeUnique(itemTypeDTO.getItemTypeCode(), itemTypeDTO.getParentTypeId());
        Long itemTypeId = itemTypeDTO.getItemTypeId() == null ? -1L : itemTypeDTO.getItemTypeId();
        if (itemType != null && !itemType.getItemTypeId().equals(itemTypeId)) {
            return "NOT_UNIQUE";
        }
        return "UNIQUE";
    }

    @Override
    public String checkItemTypeNameUnique(ItemTypeDTO itemTypeDTO) {
        ItemType itemType = itemTypeMapper.checkItemTypeNameUnique(itemTypeDTO.getItemTypeName(), itemTypeDTO.getParentTypeId());
        Long itemTypeId = itemTypeDTO.getItemTypeId() == null ? -1L : itemTypeDTO.getItemTypeId();
        if (itemType != null && !itemType.getItemTypeId().equals(itemTypeId)) {
            return "NOT_UNIQUE";
        }
        return "UNIQUE";
    }

    @Override
    public void insertItemType(ItemTypeDTO itemTypeDTO) {
        ItemType itemType = new ItemType();
        BeanUtils.copyProperties(itemTypeDTO, itemType);
        if (itemType.getParentTypeId() != null) {
            ItemType parent = itemTypeMapper.selectItemTypeById(itemType.getParentTypeId());
            if (parent != null) {
                itemType.setAncestors(parent.getAncestors() + "," + parent.getItemTypeId());
            }
        }
        itemTypeMapper.insertItemType(itemType);
    }

    @Override
    public void updateItemType(ItemTypeDTO itemTypeDTO) {
        ItemType itemType = new ItemType();
        BeanUtils.copyProperties(itemTypeDTO, itemType);
        itemTypeMapper.updateItemType(itemType);
    }

    @Override
    public void removeItemType(Long itemTypeId) {
        itemTypeMapper.deleteItemTypeById(itemTypeId);
    }

    @Override
    public boolean checkHasChild(Long itemTypeId) {
        int num = itemTypeMapper.hasChildByItemTypeId(itemTypeId);
        return num > 0;
    }

    @Override
    public boolean checkHasItem(Long itemTypeId) {
        int num = itemTypeMapper.hasItemByItemTypeId(itemTypeId);
        return num > 0;
    }
}