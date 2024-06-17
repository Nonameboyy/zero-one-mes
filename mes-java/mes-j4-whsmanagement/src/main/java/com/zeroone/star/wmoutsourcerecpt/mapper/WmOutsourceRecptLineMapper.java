package com.zeroone.star.wmoutsourcerecpt.mapper;

import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecptLine;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 外协入库单行表 Mapper 接口
 * </p>
 *
 * @author jingzi
 * @since 2024-05-29
 */
@Mapper
public interface WmOutsourceRecptLineMapper extends BaseMapper<WmOutsourceRecptLine> {

    List<WmOutsourceRecptLine> selectWmOutsourceRecptLineByRecptId(Long recptId);

}
