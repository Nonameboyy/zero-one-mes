package com.zeroone.star.orgstructure.mapper;

import com.zeroone.star.orgstructure.entity.PostDO;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 岗位信息表 Mapper 接口
 * </p>
 *
 * @author 爱吃猫的鱼
 * @since 2024-05-22
 */
@Mapper
public interface JobMapper extends BaseMapper<PostDO> {

}
