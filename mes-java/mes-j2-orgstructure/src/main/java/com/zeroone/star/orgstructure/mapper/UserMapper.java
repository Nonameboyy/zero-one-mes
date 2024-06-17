package com.zeroone.star.orgstructure.mapper;

import com.zeroone.star.orgstructure.entity.UserDO;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j2.orgstructure.dto.role.RoleDTO;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 用户信息表 Mapper 接口
 * </p>
 *
 * @author 爱吃猫的鱼
 * @since 2024-05-22
 */
@Mapper
public interface UserMapper extends BaseMapper<UserDO> {

}
