package com.zeroone.star.project.j2.sysmanagement.menu;

import com.zeroone.star.project.j2.sysmanagement.dto.menu.MenuDTO;
import com.zeroone.star.project.j2.sysmanagement.query.menu.MenuConditionQuery;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceDetailsVO;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceTreeVO;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @author 熠 Di
 * @version 1.0.0
 * @Description: TODO
 */

public interface MenuApis {
    //添加菜单
    JsonVO<MenuDTO> addMenu(MenuDTO menuDTO);

    //删除菜单
    JsonVO<String> removeMenu(int menu_id);

    //修改菜单
    JsonVO<String> modifyMenu(MenuDTO menuDTO);



    //获取资源名称树
    JsonVO<List<ResourceTreeVO>> getResourceNameTree();

    //根据条件获取资源列表
    JsonVO<List<ResourceVO>> getResourceListByCondition(MenuConditionQuery menuConditionQuery);

    //根据资源ID获取资源详情
    JsonVO<ResourceDetailsVO> getResourceDetails(Integer menu_id);
}
