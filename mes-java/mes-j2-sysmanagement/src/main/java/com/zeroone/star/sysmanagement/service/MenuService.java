package com.zeroone.star.sysmanagement.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j2.sysmanagement.dto.menu.MenuDTO;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceDetailsVO;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceTreeVO;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceVO;
import com.zeroone.star.sysmanagement.entity.MenuDO;

import java.util.List;


public interface MenuService extends IService<MenuDO> {

    // 新增菜单
    int addMenu(MenuDTO menuDTO);

    // 删除菜单
    int removeMenu(int menu_id);

    // 修改菜单
    int modifyMenu(MenuDTO menuDTO);

    List<ResourceTreeVO> getResourceNameTree();

    List<ResourceVO> getResourceListByCondition(String menuName, Integer status);

    ResourceDetailsVO getResourceDetailsByMenuId(Integer menu_id);
}
