package com.zeroone.star.syshome.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j1.syshome.dto.facility.FacilityDTO;
import com.zeroone.star.syshome.entity.Facility;

/**
 * <p>
 * 设备表 服务类
 * </p>
 *
 * @author twelve
 * @since 2024-05-29
 */
public interface IFacilityService extends IService<Facility> {

    /**
     * 查询设备信息数据
     * @return 查询结果
     */
    FacilityDTO getFacility();
}
