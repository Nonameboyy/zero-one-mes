package com.zeroone.star.orgstructure.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.orgstructure.dto.role.*;
import com.zeroone.star.project.j2.orgstructure.query.role.RoleConditionQuery;
import com.zeroone.star.project.j2.orgstructure.query.role.RolePermissionsQuery;
import com.zeroone.star.project.j2.orgstructure.query.role.UserRoleQuery;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

/**
 * 描述：Role 角色服务接口
 *
 * @author 0xu0
 * @version 1.0.0
 */

public interface RoleService {
    /**
     * 添加角色
     * @author 0xu0
     * @param roleDTO
     * @return
     */

    @ApiOperation("添加角色")
    public Long addRole(RoleAddDto roleDTO);

    /***
     * 修改角色状态（角色页面，有个开关符号，控制停用和启用）
     * @author 0xu0
     * @param roleStatusModifyDto
     * @return
     */

    @ApiOperation("修改角色状态")
    public Integer modifyRoleStatus(RoleStatusModifyDto roleStatusModifyDto) throws Exception;

    /**
     * 删除角色，支持批量删除
     * @author 0xu0
     * @param ids
     * @return
     */

    @ApiOperation("删除角色")
    public Integer deleteRoles(@RequestParam List<String> ids);

    /**
     * 修改角色信息
     * @param roleDTO
     * @return
     */

    @ApiOperation("修改角色信息")
    public Integer modifyRoleInfo(RoleModifyDto roleDTO) throws Exception;



    /*
     * 查找该角色所分配的用户
     * */
    //public List<UserRoleDTO> getUsersByRoleId(Long roleId, int offset, int limit);
    public PageDTO<UserRoleDTO> getUsersByRole(UserRoleQuery query);
    /**
     * 批量取消授权用户角色
     *
     * @param roleId  角色ID
     * @param userIds 需要取消授权的用户数据ID
     * @return 结果
     */
    public int deleteAuthUsers(Long roleId, Long[] userIds);

    /*
     * 批量选择授权用户角色
     * */
    public int insertAuthUsers(Long roleId, Long[] userIds);


    /*
     * 导出角色
     * */
    public ResponseEntity<byte[]> downloadExcel();


    List<RoleListDTO> listRoles();

    PageDTO<RoleListDTO> listPageRoles(RoleConditionQuery condition);

    RoleDTO getById(Integer id);

    RolePermissionsDTO getPermissions (Integer id);

    int updatePermissions (RolePermissionsQuery rolePermissionsQuery);
}
