package com.zeroone.star.syshome.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j1.syshome.dto.repertory.RepertoryDTO;
import com.zeroone.star.syshome.entity.Repertory;

import java.util.List;

/**
 * <p>
 * 库存记录表 服务类
 * </p>
 *
 * @author twelve
 * @since 2024-05-27
 */
public interface IRepertoryService extends IService<Repertory> {

    /**
     * 通过Id查询数据
     * @param warehouseId 仓库ID
     * @return 查询结果
     */
    List<RepertoryDTO> getRepertory(Long warehouseId);
}
