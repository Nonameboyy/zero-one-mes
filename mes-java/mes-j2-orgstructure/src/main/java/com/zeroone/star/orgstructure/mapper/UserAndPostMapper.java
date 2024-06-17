package com.zeroone.star.orgstructure.mapper;

import com.zeroone.star.orgstructure.entity.UserAndPsotDO;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 用户与岗位关联表 Mapper 接口
 * </p>
 *
 * @author 爱吃猫的鱼
 * @since 2024-05-22
 */
@Mapper
public interface UserAndPostMapper extends BaseMapper<UserAndPsotDO> {

    @Select("select * from sys_user_post where post_id = #{id}")
    List<Long> selectBypostId(Long id);
}
