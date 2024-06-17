package com.zeroone.star.syshome.service.impl;



import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j1.syshome.dto.quality.QualityDTO;
import com.zeroone.star.syshome.entity.Quality;
import com.zeroone.star.syshome.mapper.QualityMapper;
import com.zeroone.star.syshome.service.IQualityService;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 过程检验单缺陷记录表 服务实现类
 * </p>
 *
 * @author twelve
 * @since 2024-05-29
 */
@Service
public class QualityServiceImpl extends ServiceImpl<QualityMapper, Quality> implements IQualityService {

    @Override
    public List<QualityDTO> getQuality() {
        QueryWrapper<Quality> wrapper = new QueryWrapper<>();
        wrapper.select("defect_quantity", "defect_name"); // 指定查询字段
        List<Quality> qualities = baseMapper.selectList(wrapper);

        // 转换为DTO列表
        List<QualityDTO> qualityDTOs = new ArrayList<>();
        for (Quality quality : qualities) {
            QualityDTO dto = new QualityDTO();
            // 只复制defectQuantity和defectName属性
            dto.setDefectQuantity(quality.getDefectQuantity());
            dto.setDefectName(quality.getDefectName());
            qualityDTOs.add(dto);
        }
        return qualityDTOs;
    }
}
