package com.zeroone.star.wmoutsourcerecpt.mapper;

import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt.OutsourceRecptTxBean;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecpt;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 外协入库单表 Mapper 接口
 * </p>
 *
 * @author jingzi
 * @since 2024-05-29
 */
@Mapper
public interface WmOutsourceRecptMapper extends BaseMapper<WmOutsourceRecpt> {

    List<OutsourceRecptTxBean> selectTxBeans(Long recptId);
}
