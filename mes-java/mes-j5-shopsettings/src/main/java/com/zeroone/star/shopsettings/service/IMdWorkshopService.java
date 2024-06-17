package com.zeroone.star.shopsettings.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.shopsettings.ShopSettingsDTO;
import com.zeroone.star.project.j5.query.shopsettings.ShopSettingsQuery;
import com.zeroone.star.shopsettings.entity.MdWorkshop;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 车间表 服务类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-29
 */
public interface IMdWorkshopService extends IService<MdWorkshop> {

    PageDTO<ShopSettingsDTO> queryWorkshopList(ShopSettingsQuery shopSettingsQuery);

    ShopSettingsDTO queryWorkshopInfo(Long workShopId);

    List<String> queryWorkshopNameList();

    int removeWorkshop(List<Long> workshopIds);
}
