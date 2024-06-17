package com.zeroone.star.shopsettings.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.shopsettings.ShopSettingsDTO;
import com.zeroone.star.project.j5.query.shopsettings.ShopSettingsQuery;
import com.zeroone.star.shopsettings.entity.MdWorkshop;
import com.zeroone.star.shopsettings.mapper.MdWorkshopMapper;
import com.zeroone.star.shopsettings.service.IMdWorkshopService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 车间表 服务实现类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-29
 */
@Mapper(componentModel = "spring")
interface msMdWorkshopMapper{
    /**
     * 将车间do转车间dto
     * @param mdWorkshop 车间do
     * @return  车间dto
     */
    ShopSettingsDTO mdWorkshopToShopSettingsDTO(MdWorkshop mdWorkshop);

    MdWorkshop mdWorkshop(ShopSettingsDTO shopSettingsDTO);
}

@Service
public class MdWorkshopServiceImpl extends ServiceImpl<MdWorkshopMapper, MdWorkshop> implements IMdWorkshopService {
    @Resource
    msMdWorkshopMapper msMdWorkshopMapper;

    //获取车间数据列表
    @Override
    public PageDTO<ShopSettingsDTO> queryWorkshopList(ShopSettingsQuery shopSettingsQuery) {
        Page<MdWorkshop> mdWorkshopPage = new Page<>(shopSettingsQuery.getPageIndex(),shopSettingsQuery.getPageSize());
        QueryWrapper<MdWorkshop> wrapper = new QueryWrapper<>();
        if(shopSettingsQuery.getWorkshopCode() != null){
            wrapper.eq("workshop_code", shopSettingsQuery.getWorkshopCode());
        }
        if(shopSettingsQuery.getWorkshopName() != null){
            wrapper.eq("workshop_name", shopSettingsQuery.getWorkshopName());
        }
        //执行分页查询
        Page<MdWorkshop> result = baseMapper.selectPage(mdWorkshopPage, wrapper);
        //返回dto数据
        return PageDTO.create(result, msMdWorkshopMapper::mdWorkshopToShopSettingsDTO);
    }

    //获取车间详细信息
    @Override
    public ShopSettingsDTO queryWorkshopInfo(Long workShopId) {
        //根据workshopId查询车间信息
        MdWorkshop mdWorkshop = baseMapper.selectById(workShopId);
        if(mdWorkshop == null){
            throw new RuntimeException("查询结果为空");
        }
        //返回查询车间详细信息
        return msMdWorkshopMapper.mdWorkshopToShopSettingsDTO(mdWorkshop);
    }

    //获取车间名称列表
    @Override
    public List<String> queryWorkshopNameList() {
        //查询车间名称列表
        List<String> shopSettingNameList = baseMapper.queryMdWorkshopNameList();
        if(shopSettingNameList == null){
            throw new RuntimeException("查询车间名称列表为空");
        }
         //去重并返回车间名称列表
        return shopSettingNameList.stream().distinct().collect(Collectors.toList());
    }

    @Override
    public int removeWorkshop(List<Long> workshopIds) {
        int totalDeleted = 0;
        for(Long workshopId : workshopIds){
            int deleteRow = baseMapper.delete(new QueryWrapper<MdWorkshop>().eq("workshop_id", workshopId));
            if(deleteRow < 1){
                throw new RuntimeException("删除失败");
            }
            totalDeleted += deleteRow;
        }
        return totalDeleted;

    }
}
