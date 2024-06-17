package com.zeroone.star.syshome.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.syshome.dto.production.ProductionDTO;
import com.zeroone.star.project.j1.syshome.query.EPageQuery;
import com.zeroone.star.syshome.entity.Production;
import com.zeroone.star.syshome.mapper.ProductionMapper;
import com.zeroone.star.syshome.service.IProductionService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;


/**
 * <p>
 * 描述：Sample对应MapStructMapper接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
interface MsProductionMapper {
    /**
     * 将 ProductionDO 转换成 ProductionDTO
     * @param production do对象
     * @return 转换后的结果
     */
    ProductionDTO ProductionToProductionDTO(Production production);
}

/**
 * <p>
 * 生产任务表 服务实现类
 * </p>
 *
 * @author twelve
 * @since 2024-05-26
 */
@Service
public class ProductionServiceImpl extends ServiceImpl<ProductionMapper, Production> implements IProductionService {

    @Resource
    MsProductionMapper msProductionMapper;

    @Override
    public PageDTO<ProductionDTO> listProduction(EPageQuery condition) {
        // 构建分页查询对象
        Page<Production> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        // 构建查询条件
        QueryWrapper<Production> wrapper = new QueryWrapper<>();
        // 执行分页查询
        Page<Production> result = baseMapper.selectPage(page, wrapper);
        // 结果转换成DTO
        return PageDTO.create(result, src -> msProductionMapper.ProductionToProductionDTO(src));
    }
}
