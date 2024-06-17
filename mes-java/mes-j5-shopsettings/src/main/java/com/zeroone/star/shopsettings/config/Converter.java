package com.zeroone.star.shopsettings.config;

import com.zeroone.star.project.j5.dto.shopsettings.AddShopSettingsDTO;
import com.zeroone.star.project.j5.dto.shopsettings.ModifyShopSettingsDTO;
import com.zeroone.star.shopsettings.entity.MdWorkshop;

public class Converter {
    /**
     * 将ModifyShopSettingsDTO转换成实体层
     * @param dto ModifyShopSettingsDTO
     * @return workshop 实体层
     */
    public static MdWorkshop toModifyMdWorkshop(ModifyShopSettingsDTO dto) {
        if (dto == null) {
            return null;
        }

        MdWorkshop workshop = new MdWorkshop();
        workshop.setWorkshopId(dto.getWorkshopId());
        workshop.setWorkshopCode(dto.getWorkshopCode());
        workshop.setWorkshopName(dto.getWorkshopName());
        workshop.setArea(dto.getArea());
        workshop.setCharge(dto.getCharge());
        workshop.setEnableFlag(dto.getEnableFlag());
        workshop.setRemark(dto.getRemark());

        // 设置默认值或根据业务逻辑设置的其他字段
        // workshop.setAttr1(...);
        // workshop.setAttr2(...);
        // workshop.setAttr3(...);
        // workshop.setAttr4(...);
        // workshop.setCreateBy(...);
        // workshop.setCreateTime(...);
        // workshop.setUpdateBy(...);
        // workshop.setUpdateTime(...);

        return workshop;
    }

    public static MdWorkshop toAddMdWorkshop(AddShopSettingsDTO dto) {
        if (dto == null) {
            return null;
        }

        MdWorkshop workshop = new MdWorkshop();
        workshop.setWorkshopId(dto.getWorkshopId());
        workshop.setWorkshopCode(dto.getWorkshopCode());
        workshop.setWorkshopName(dto.getWorkshopName());
        workshop.setArea(dto.getArea());
        workshop.setCharge(dto.getCharge());
        workshop.setEnableFlag(dto.getEnableFlag());
        workshop.setRemark(dto.getRemark());

        // 设置默认值或根据业务逻辑设置的其他字段
        // workshop.setAttr1(...);
        // workshop.setAttr2(...);
        // workshop.setAttr3(...);
        // workshop.setAttr4(...);
        // workshop.setCreateBy(...);
        // workshop.setCreateTime(...);
        // workshop.setUpdateBy(...);
        // workshop.setUpdateTime(...);

        return workshop;
    }
}
