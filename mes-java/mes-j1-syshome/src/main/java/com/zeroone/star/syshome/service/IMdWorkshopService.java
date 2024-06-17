package com.zeroone.star.syshome.service;

import com.zeroone.star.project.j1.syshome.dto.workshop.WorkshopDTO;
import com.zeroone.star.syshome.entity.MdWorkshop;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 车间表 服务类
 * </p>
 *
 * @author lxh
 * @since 2024-05-29
 */
public interface IMdWorkshopService extends IService<MdWorkshop> {

    List<WorkshopDTO> listWorkshop();

}
