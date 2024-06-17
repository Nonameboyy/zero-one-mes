package com.zeroone.star.syshome.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.syshome.dto.production.ProductionDTO;
import com.zeroone.star.project.j1.syshome.query.EPageQuery;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.syshome.entity.Production;

/**
 * <p>
 * 生产任务表 服务类
 * </p>
 *
 * @author twelve
 * @since 2024-05-26
 */
public interface IProductionService extends IService<Production> {

    /**
     * 分页查询生产数据
     * @param condition 查询条件
     * @return 查询结果
     */
    PageDTO<ProductionDTO> listProduction(EPageQuery condition);
}
