package com.zeroone.star.syshome.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j1.syshome.dto.repertory.RepertoryDTO;
import com.zeroone.star.syshome.entity.Repertory;
import com.zeroone.star.syshome.mapper.RepertoryMapper;
import com.zeroone.star.syshome.service.IRepertoryService;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;


/**
 * <p>
 * 演示示例表 服务实现类
 * </p>
 * @author awei
 * @since 2024-05-10
 */
@Service
public class RepertoryServiceImpl extends ServiceImpl<RepertoryMapper, Repertory> implements IRepertoryService {
    @Override
    public List<RepertoryDTO> getRepertory(Long warehouseId) {
        // 构建查询条件
        QueryWrapper<Repertory> wrapper = new QueryWrapper<>();
        wrapper.like("warehouse_id", warehouseId);
        List<Repertory> repertories = baseMapper.selectList(wrapper);
        // 转换为DTO列表
        List<RepertoryDTO> repertoryDTOs = new ArrayList<>();
        for (Repertory repertory : repertories) {
            RepertoryDTO dto = new RepertoryDTO();
            BeanUtils.copyProperties(repertory, dto);
            repertoryDTOs.add(dto);
        }
        return repertoryDTOs;
    }

}
