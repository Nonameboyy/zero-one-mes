package com.zeroone.star.orgstructure.controller;


import com.zeroone.star.orgstructure.service.RoleService;
import com.zeroone.star.project.j2.orgstructure.dto.role.UserRoleDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.orgstructure.dto.role.RoleDTO;
import com.zeroone.star.project.j2.orgstructure.dto.role.*;
import com.zeroone.star.project.j2.orgstructure.query.role.RoleConditionQuery;
import com.zeroone.star.project.j2.orgstructure.query.role.RolePermissionsQuery;
import com.zeroone.star.project.j2.orgstructure.query.role.UserRoleQuery;
import com.zeroone.star.project.j2.orgstructure.role.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.List;

/**
 * <p>
 * 角色信息表 前端控制器
 * </p>
 *
 * @author 0xu0、天衍土豆 迷
 * @since 2024-05-17
 */
@RestController
@RequestMapping("/orgstructure/role")
@Api(tags = "角色控制器")
public class RoleController implements RoleApis {



    @Resource
    private RoleService roleService;
    /**
     *
     * 获取角色名称列表
     * @author 天衍土豆
     * @return
     */
    @Override
    @GetMapping("query-roles")
    @ApiOperation("获取角色名称列表")
    public JsonVO<List<RoleListDTO>> queryRoles() {
        List<RoleListDTO> result = roleService.listRoles();
        return JsonVO.success(result);
    }

    /**
     * 获取角色列表(条件+分页)
     * @author 天衍土豆
     * @return
     */
    @Override
    @GetMapping ("/query-page")
    @ApiOperation("获取角色列表(条件+分页)")
    public JsonVO<PageDTO<RoleListDTO>> queryRolePage(RoleConditionQuery condition) {
        PageDTO<RoleListDTO> result = roleService.listPageRoles(condition);
        return JsonVO.success(result);
    }

    /**
     * 获取角色详情
     * @author 天衍土豆
     * @return
     */
    @Override
    @GetMapping("query-role")
    @ApiOperation("获取角色详情")
    public JsonVO<RoleDTO> queryRole(@RequestParam Integer id) {
        RoleDTO result = roleService.getById(id);
        return JsonVO.success(result);
    }




    /**
     * 设置数据权限
     * @author 天衍土豆
     * @return
     */
    @Override
    @PutMapping("modify-role")
    @ApiOperation("设置数据权限")
    public JsonVO<String> modifyRole(@RequestBody RolePermissionsQuery rolePermissionsQuery) {
        int i = roleService.updatePermissions(rolePermissionsQuery);
        if (i<0){
            return JsonVO.fail("修改失败");
        }
        return JsonVO.success("修改成功");
    }
    /**
     * 添加角色
     *
     * @param roleDTO
     * @return
     * @author 0xu0
     */
    @Override
    @PostMapping("add-Role")
    @ApiOperation("添加角色")
    public JsonVO<Long> addRole(@RequestBody @Valid RoleAddDto roleDTO) {
        Long add = roleService.addRole(roleDTO);
        if (add > 0) {
            return JsonVO.success(add);
        }
        return JsonVO.fail(-1L);
    }
    /***
     * 修改角色状态（角色页面，有个开关符号，控制停用和启用）
     * @author 0xu0
     * @param roleStatusModifyDto
     * @return
     */
    @Override
    @PostMapping("modify-RoleStatus")
    @ApiOperation("修改角色状态")
    public JsonVO<Integer> modifyRoleStatus(@RequestBody @Valid RoleStatusModifyDto roleStatusModifyDto){
        Integer modify = null;
        try {
            modify = roleService.modifyRoleStatus(roleStatusModifyDto);
            return JsonVO.success(modify);
        } catch (Exception e) {
            return JsonVO.fail(-1);
        }
//        if(modify>0){
//            return JsonVO.success(modify);
//        }
//        return JsonVO.fail(modify);
    }


    /**
     * 删除角色，支持批量删除
     * @author 0xu0
     * @param ids
     * @return
     */
    @Override
    @DeleteMapping("delete-Roles")
    @ApiOperation("删除角色")
    public JsonVO<List<String>> deleteRoles(@RequestParam List<String> ids){
        if(roleService.deleteRoles(ids)>0){
            return JsonVO.success(ids);
        }
        return JsonVO.fail(ids);
    }

    /**
     * 修改角色信息
     * @param roleDTO
     * @return
     */
    @Override
    @PostMapping("modify-RoleInfo")
    @ApiOperation("修改角色信息")
    public JsonVO<Integer> modifyRoleInfo(@RequestBody @Valid RoleModifyDto roleDTO){
        Integer info = null;
        try {
            info = roleService.modifyRoleInfo(roleDTO);
            return JsonVO.success(info);
        } catch (Exception e) {
            return JsonVO.fail(-1);
        }
//        if(info>0){
//            return JsonVO.success(info);
//        }
//        return JsonVO.fail(info);
    }
    /*
     * 获取角色分配用户列表（条件+分页）
     * */
    @GetMapping("query-allocate-role")
    @ApiOperation("获取角色分配用户列表（条件+分页）")
    public JsonVO<PageDTO<UserRoleDTO>> queryAllocatedList(@Validated UserRoleQuery query) {
        PageDTO<UserRoleDTO> result = roleService.getUsersByRole(query);
        return JsonVO.success(result);
    }


    /*
     * 添加授权
     * */
    @Override
    @PutMapping("addAuth")
    @ApiOperation("添加授权")
    public JsonVO<RoleDTO> addAuth(@RequestParam Long roleId, @RequestParam Long[] userIds) {
        Integer result = roleService.insertAuthUsers(roleId, userIds);
        return result > 0 ? JsonVO.success(null) : JsonVO.fail(null);
    }

    /*
     * 取消授权（支持批量）
     * */
    @Override
    @DeleteMapping("cancel")
    @ApiOperation("批量取消授权")
    public JsonVO<Integer> cancelAuthUsers(@RequestParam Long roleId, @RequestParam Long[] userIds) {
        Integer result = roleService.deleteAuthUsers(roleId, userIds);
        return result > 0 ? JsonVO.success(result) : JsonVO.fail(result);
    }

    /*
     * 导出角色
     * */
    @Override
    @GetMapping(value = "export")
    @ApiOperation("导出角色")
    public ResponseEntity<byte[]> export() {
        return roleService.downloadExcel();
    }

}

