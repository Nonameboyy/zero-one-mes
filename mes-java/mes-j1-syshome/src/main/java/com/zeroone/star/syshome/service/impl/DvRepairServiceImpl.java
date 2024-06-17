package com.zeroone.star.syshome.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.syshome.dto.toDoEvent.ToDoEventDTO;
import com.zeroone.star.project.j1.syshome.vo.toDoEvent.ToDoEventVO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.syshome.entity.DvRepair;

import com.zeroone.star.syshome.mapper.DvRepairMapper;
import com.zeroone.star.syshome.service.IDvRepairService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 设备维修单 服务实现类
 * </p>
 *
 * @author lxh
 * @since 2024-05-29
 */
@Service
public class DvRepairServiceImpl extends ServiceImpl<DvRepairMapper, DvRepair> implements IDvRepairService {

    @Resource
    MsSysHomeMapper msSysHomeMapper;
    @Resource
    DvRepairMapper dvRepairMapper;
    @Override
    public PageDTO<ToDoEventDTO> selectToDoEvent(PageQuery pageQuery, String userName) {

        // 构建分页查询对象
        Page<ToDoEventDTO> page = new Page<>(pageQuery.getPageIndex(), pageQuery.getPageSize());
        // 执行分页查询
        Page<ToDoEventVO> result = dvRepairMapper.selectToDoEvent(pageQuery, userName);
        // 结果转换成DTO
        return PageDTO.create(result, src -> msSysHomeMapper.toDoEventVOTotoDoEventDTO(src));
    }
}
