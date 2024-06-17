package com.zeroone.star.oauth2.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oauth2.entity.Menu;
import com.zeroone.star.oauth2.entity.MenuDO;

import java.util.List;

/**
 * <p>
 * 菜单 服务类
 * </p>
 *
 * @author 阿伟
 */
public interface IMenuService extends IService<MenuDO> {
    /**
     * 获取菜单中的链接地址
     * @return 查询结果
     */
    List<MenuDO> listAllLinkUrl();
}
