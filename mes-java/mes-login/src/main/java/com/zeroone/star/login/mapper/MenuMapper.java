package com.zeroone.star.login.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.login.entity.Menu;
import com.zeroone.star.login.entity.MenuDO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 菜单 Mapper 接口
 * </p>
 * @author 阿伟
 */
@Mapper
public interface MenuMapper extends BaseMapper<MenuDO> {
    /**
     * 通过角色名获取对应的菜单资源
     * @param roleName 角色名
     * @return 返回菜单列表
     */
    //List<Menu> selectByRoleName(String roleName);
    List<MenuDO> selectByRoleName(String roleName);
}
