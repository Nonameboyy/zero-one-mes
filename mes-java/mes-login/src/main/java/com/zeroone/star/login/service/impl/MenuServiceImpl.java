package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.Menu;
import com.zeroone.star.login.entity.MenuDO;
import com.zeroone.star.login.mapper.MenuMapper;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：定义一个MenuDO数据到MenuTreeNode的属性映射配器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
class MenuTreeNodMapper implements TreeNodeMapper<MenuDO> {
    @Override
    public TreeNode objectMapper(MenuDO menuDO) {
        MenuTreeVO treeNode = new MenuTreeVO();
        // 首先设置TreeNode计算层数使用属性
        treeNode.setTnId(menuDO.getMenuId().toString());
        if (menuDO.getParentId() == null || menuDO.getParentId() == 0) {
            treeNode.setTnPid(null);
        } else {
            treeNode.setTnPid(menuDO.getParentId().toString());
        }
        // 设置扩展属性
        treeNode.setId(menuDO.getMenuId());
        treeNode.setIcon(menuDO.getIcon());
        treeNode.setText(menuDO.getMenuName());
        treeNode.setHref(menuDO.getPath());
        treeNode.setPid(menuDO.getParentId());

        return treeNode;
    }
}
/**
 * <p>
 * 菜单 服务实现类
 * </p>
 * @author 阿伟
 */
@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, MenuDO> implements IMenuService {
	@Resource
	MenuMapper menuMapper;

    @Override
    public List<MenuTreeVO> listMenuByRoleName(List<String> roleNames) {
        //1 定义一个存储数据库查询菜单数据的容器
        List<MenuDO> menus = new ArrayList<>();
        //2 遍历获取角色获取所有的菜单列表
        roleNames.forEach(roleName -> {
            //通过角色名获取菜单列表
            List<MenuDO> tMenus = menuMapper.selectByRoleName(roleName);
            if (tMenus != null && !tMenus.isEmpty()) {
                menus.addAll(tMenus);
            }
        });
        //3 转换树形结构并返回
        return TreeUtils.listToTree(menus, new MenuTreeNodMapper());
    }
}
