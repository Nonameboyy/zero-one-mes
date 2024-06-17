package com.zeroone.star.syshome.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j1.syshome.dto.quality.QualityDTO;
import com.zeroone.star.syshome.entity.Quality;

import java.util.List;

/**
 * <p>
 * 过程检验单缺陷记录表 服务类
 * </p>
 *
 * @author twelve
 * @since 2024-05-29
 */
public interface IQualityService extends IService<Quality> {

    /**
     * 查询质量数据
     * @return 查询结果
     */
    List<QualityDTO> getQuality();

}
