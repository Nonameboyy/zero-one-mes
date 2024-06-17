package com.zeroone.star.syshome.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j1.syshome.dto.workshop.WorkshopDTO;
import com.zeroone.star.project.j1.syshome.vo.workshop.WorkshopVO;
import com.zeroone.star.syshome.entity.MdWorkshop;
import com.zeroone.star.syshome.mapper.MdWorkshopMapper;
import com.zeroone.star.syshome.service.IMdWorkshopService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;




/**
 * <p>
 * 车间表 服务实现类
 * </p>
 *
 * @author lxh
 * @since 2024-05-29
 */
@Service
public class MdWorkshopServiceImpl extends ServiceImpl<MdWorkshopMapper, MdWorkshop> implements IMdWorkshopService {
    @Resource
    MsSysHomeMapper msSysHomeMapper;
    @Resource
    MdWorkshopMapper mdWorkshopMapper;

    @Override
    public List<WorkshopDTO> listWorkshop() {
        List<WorkshopVO> workshopDOList = mdWorkshopMapper.selectWorkshop();
        return workshopDOList.stream().map(workshopDO -> msSysHomeMapper.workshopVOToworkshopDTO(workshopDO))
                .collect(Collectors.toList());
    }

}
