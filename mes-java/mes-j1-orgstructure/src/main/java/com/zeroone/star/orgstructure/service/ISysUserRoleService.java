package com.zeroone.star.orgstructure.service;

import com.zeroone.star.orgstructure.entity.SysRole;
import com.zeroone.star.orgstructure.entity.SysUserRole;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j1.orgstructure.dto.PageDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.SysRoleDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.SysUserRoleDTO;
import com.zeroone.star.project.j1.orgstructure.query.user.UserRoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.mapstruct.Mapper;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;

/**
 * <p>
 * 用户和角色关联表 服务类
 * </p>
 *
 * @author gimigimi
 * @since 2024-05-23
 */
public interface ISysUserRoleService extends IService<SysUserRole> {
     /**
      * 获取角色分配用户列表
      * @param userQuery
      * @return
      */
     PageDTO<SysUserRoleDTO> queryUserRoleList(UserRoleQuery userQuery) ;

     /**
      * 添加角色
      * @param userQuery
      * @return
      */
     Boolean saveRole(UserRoleQuery userQuery);

     /**
      * 删除角色
      * @param userQuery
      * @return
      */
     Boolean deleteRole(UserRoleQuery userQuery);


}
