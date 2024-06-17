package com.zeroone.star.sysmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceDetailsVO;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceTreeVO;
import com.zeroone.star.project.j2.sysmanagement.vo.ResourceVO;
import com.zeroone.star.sysmanagement.entity.MenuDO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 菜单权限表 Mapper 接口
 * </p>
 *
 * @author yi
 * @since 2024-05-25
 */
@Mapper
public interface MenuMapper extends BaseMapper<MenuDO> {

    @Select("select menu_id,menu_name,parent_id from sys_menu")
    List<ResourceTreeVO> getResourceNameTree();

    @Select("select menu_id,menu_name,parent_id,icon,order_num,perms,component,status,create_time from sys_menu " +
            "where status = #{status} and " +
            "menu_name like concat('%', #{menuName}, '%')")
    List<ResourceVO> getResourceListByCondition(@Param("menuName") String menuName,@Param("status") Integer status);

    @Select("select menu_id,menu_name,parent_id,order_num,path,is_frame,menu_type,visible,status,icon from sys_menu " +
            "where menu_id = #{menu_id}")
    ResourceDetailsVO getResourceDetailsByMenuId(@Param("menu_id") Integer menu_id);
}
