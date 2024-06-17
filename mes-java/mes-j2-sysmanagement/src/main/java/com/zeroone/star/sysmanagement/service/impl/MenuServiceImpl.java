package com.zeroone.star.sysmanagement.service.impl;


import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceDetailsVO;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceTreeVO;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceVO;
import com.zeroone.star.sysmanagement.entity.MenuDO;
import com.zeroone.star.sysmanagement.mapper.MenuMapper;
import com.zeroone.star.sysmanagement.service.MenuService;
import com.zeroone.star.project.j2.sysmanagement.dto.menu.MenuDTO;
import org.springframework.stereotype.Service;


import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;


@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, MenuDO> implements MenuService {

    @Resource
    MsMenuMapper msMenuMapper;

    @Resource
    MenuMapper menuMapper;

    @Override
    public int addMenu(MenuDTO menuDTO) {
        MenuDO menu = msMenuMapper.menuToMenuDTO(menuDTO);
        menu.setCreateTime(LocalDateTime.now());
        return baseMapper.insert(menu);
    }
    @Override
    public int modifyMenu(MenuDTO menuDTO) {
        MenuDO menu = msMenuMapper.menuToMenuDTO(menuDTO);
        menu.setUpdateTime(LocalDateTime.now());
        return baseMapper.updateById(menu);
    }

    @Override
    public int removeMenu(int menu_id) {
        MenuDO menu = baseMapper.selectById(menu_id);
        menu.setUpdateTime(LocalDateTime.now());
        return menu_id;
    }

    @Override
    public List<ResourceTreeVO> getResourceNameTree() {
        return menuMapper.getResourceNameTree();
    }

    @Override
    public List<ResourceVO> getResourceListByCondition(String menuName, Integer status) {
        return menuMapper.getResourceListByCondition(menuName, status);
    }

    @Override
    public ResourceDetailsVO getResourceDetailsByMenuId(Integer menu_id) {
        return menuMapper.getResourceDetailsByMenuId(menu_id);
    }
}
