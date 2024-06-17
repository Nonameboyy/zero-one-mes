package com.zeroone.star.syshome.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j1.syshome.dto.facility.FacilityDTO;
import com.zeroone.star.syshome.entity.Facility;
import com.zeroone.star.syshome.mapper.FacilityMapper;
import com.zeroone.star.syshome.service.IFacilityService;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 设备表 服务实现类
 * </p>
 *
 * @author twelve
 * @since 2024-05-29
 */
@Service
public class FacilityServiceImpl extends ServiceImpl<FacilityMapper, Facility> implements IFacilityService {

    @Override
    public FacilityDTO getFacility() {
        FacilityDTO facilityDTO = new FacilityDTO();

        // 查询status为stop的数量
        QueryWrapper<Facility> stopWrapper = new QueryWrapper<>();
        stopWrapper.eq("status", "STOP");
        facilityDTO.setFacilityStop(baseMapper.selectCount(stopWrapper));

        // 查询status为run的数量
        QueryWrapper<Facility> runWrapper = new QueryWrapper<>();
        runWrapper.eq("status", "RUN");
        facilityDTO.setFacilityRun(baseMapper.selectCount(runWrapper));

        // 查询status为wait的数量
        QueryWrapper<Facility> waitWrapper = new QueryWrapper<>();
        waitWrapper.eq("status", "WAIT");
        facilityDTO.setFacilityWait(baseMapper.selectCount(waitWrapper));

        // 查询总数据的数量
        QueryWrapper<Facility> totalWrapper = new QueryWrapper<>();
        facilityDTO.setFacilitySum(baseMapper.selectCount(totalWrapper));

        return facilityDTO;
    }
}
