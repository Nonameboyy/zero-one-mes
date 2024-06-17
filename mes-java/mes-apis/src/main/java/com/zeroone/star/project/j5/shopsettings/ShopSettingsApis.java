package com.zeroone.star.project.j5.shopsettings;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.shopsettings.AddShopSettingsDTO;
import com.zeroone.star.project.j5.dto.shopsettings.ModifyShopSettingsDTO;
import com.zeroone.star.project.j5.dto.shopsettings.ShopSettingsDTO;
import com.zeroone.star.project.j5.query.shopsettings.ShopSettingsQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：车间设置接口
 * @author 翔君
 * @version 1.0.0
 */
public interface ShopSettingsApis {

    /**
     * 获取车间管理列表（条件+分页）
     * @param shopSettingsQuery 查询条件
     * @return  车间列表
     */
    JsonVO<PageDTO<ShopSettingsDTO>> queryWorkshopList(ShopSettingsQuery shopSettingsQuery);

    /**
     * 获取车间详情
     * @param workShopId 车间号
     * @return 车间详细信息
     */
    JsonVO<ShopSettingsDTO> queryWorkshopInfo(Long workShopId);

    /**
     * 获取车间名称列表
     * @return 名称列表
     */
    JsonVO<List<String>> queryWorkshopNameList();

    /**
     * 更新车间信息
     *
     * @param modifyShopSettingsDTO 更新数据
     * @return 更新行数
     */
    JsonVO<Boolean> modifyWorkshop(ModifyShopSettingsDTO modifyShopSettingsDTO);
    /**
     * 新增车间信息
     *
     * @param addShopSettingsDTO 新增车间数据
     * @return 修改行数
     */
    JsonVO<Boolean> addWorkshop(AddShopSettingsDTO addShopSettingsDTO);
    /**
     * 删除或批量删除车间信息
     * @param workshopIds 删除id序列
     * @return  删除的行数
     */
    JsonVO<Integer> removeWorkshop(List<Long> workshopIds);


}
