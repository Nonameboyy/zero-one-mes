package com.zeroone.star.oauth2.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oauth2.entity.Menu;
import com.zeroone.star.oauth2.entity.MenuDO;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 菜单 Mapper 接口
 * </p>
 *
 * @author 阿伟
 */
@Mapper
public interface MenuMapper extends BaseMapper<MenuDO> {
}
