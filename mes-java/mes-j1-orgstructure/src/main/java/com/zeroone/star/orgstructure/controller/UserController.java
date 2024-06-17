package com.zeroone.star.orgstructure.controller;

import com.zeroone.star.orgstructure.service.*;
import com.zeroone.star.project.j1.orgstructure.dto.PageDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.*;
import com.zeroone.star.project.j1.orgstructure.query.user.UserQuery;
import com.zeroone.star.project.j1.orgstructure.query.user.UserRoleQuery;
import com.zeroone.star.project.j1.orgstructure.user.UserApis;
import com.zeroone.star.project.vo.JsonVO;
import io.seata.common.util.StringUtils;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;
import java.io.IOException;
import java.util.List;

/**
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Tme
 * @version 1.0.0
 */
@Slf4j
@RestController
@RequestMapping("/user")
@Api(tags = "用户管理")
public class UserController implements UserApis {
    @Autowired
    private IUserQueryService userQueryService;

    @Override
    @GetMapping("/query-user-table")
    @ApiOperation("查询用户列表")
    public JsonVO<List<UserDTO>> queryUserList(@Valid UserQuery userQuery) {
        List<UserDTO> userDTOS = userQueryService.queryUserList(userQuery);
        return JsonVO.success(userDTOS);
    }

    @Override
    @GetMapping("/query-complete-user")
    @ApiOperation("获取用户详情")
    public JsonVO<CompleteUserDTO> queryUser(@Valid UserDTO userDTO) {

        CompleteUserDTO completeUserDTO = userQueryService.queryUser(userDTO);
        return JsonVO.success(completeUserDTO);
    }


    @Resource
    private IUserService userService;


    @PostMapping("add-user")
    @ApiOperation(value = "新增用户")
    @Override
    public JsonVO<String> addUser(@RequestBody AddUserDTO addUserDTO) {
        if (userService.checkUserNameUnique(null, addUserDTO.getUserName()) > 0)
        {
            return JsonVO.fail("新增用户失败，登录账号已存在");
        }
        else if (StringUtils.isNotEmpty(addUserDTO.getPhonenumber())
                && userService.checkPhoneUnique(null, addUserDTO.getPhonenumber()) > 0)
        {
            return JsonVO.fail("新增用户失败，手机号码已存在");
        }
        else if (StringUtils.isNotEmpty(addUserDTO.getEmail())
                && userService.checkEmailUnique(null, addUserDTO.getEmail()) > 0)
        {
            return JsonVO.fail("新增用户失败，邮箱账号已存在");
        }
//        addUserDTO.setCreateBy(getUsername());
//        addUserDTO.setPassword(SecurityUtils.encryptPassword(addUserDTO.getPassword()));
        userService.saveUser(addUserDTO);
        return JsonVO.success("新增用户成功");
    }

    @PutMapping("modify-user")
    @ApiOperation(value = "修改用户")
    @Override
    public JsonVO<String> modifyUser(@RequestBody UpdateUserDTO updateUserDTO) {
        if(!userService.checkUser(updateUserDTO.getUserId())){
            return JsonVO.fail("修改用户失败，该用户不存在");
        }
        else if (StringUtils.isNotEmpty(updateUserDTO.getPhonenumber())
                && userService.checkPhoneUnique(updateUserDTO.getUserId(), updateUserDTO.getPhonenumber()) > 0)
        {
            return JsonVO.fail("修改用户失败，手机号码已存在");
        }
        else if (StringUtils.isNotEmpty(updateUserDTO.getEmail())
                && userService.checkEmailUnique(updateUserDTO.getUserId(), updateUserDTO.getEmail()) > 0)
        {
            return JsonVO.fail("修改用户失败，邮箱账号已存在");
        }
        userService.updateUser(updateUserDTO);
        return JsonVO.success("修改用户信息成功");
    }

    @DeleteMapping("remove-user")
    @ApiOperation(value = "删除用户")
    @Override
    public JsonVO<String> removeUser(@RequestParam List<Long> userIds) {
        userService.removeUser(userIds);
        return JsonVO.success("删除成功");
    }


    @Resource
    IService service;

    @PutMapping("setUserStatus")
    @ApiOperation("设置用户状态")
    @Override
    public JsonVO setUserStatus(UpdateUserStatusDTO userIdStatus) {
        int flag = service.UpdateUserStatus(userIdStatus);
        if (flag == 1) {
            return JsonVO.success("恭喜！设置用户状态成功！");
        }
        return JsonVO.fail("抱歉！设置用户状态失败！");
    }
    @PutMapping("resetUserPassword")
    @ApiOperation("重置用户密码")
    @Override
    public JsonVO resetUserPassword(Integer userId) {
        int flag = service.UpdateUserPassword(userId);
        if (flag == 1) {
            return JsonVO.success("恭喜！重置用户密码成功！");
        }
        return JsonVO.fail("抱歉！重置用户密码失败！");
    }



    @Resource
    ISysRoleService sysRoleService;


    @GetMapping("query-role-table")
    @ApiOperation(value = "查询角色列表")
    @Override
    public JsonVO<PageDTO<SysRoleDTO>> queryRoleList(@Validated UserQuery userQuery){
        return JsonVO.success(sysRoleService.queryRoleList(userQuery));
    }



    @Resource
    ISysUserRoleService sysUserRoleService;


    @GetMapping("query-user-role-table")
    @ApiOperation(value = "查询用户分配角色列表")
    @Override
    public JsonVO<PageDTO<SysUserRoleDTO>> queryUserRoleList(@Validated UserRoleQuery userQuery) {
        return JsonVO.success(sysUserRoleService.queryUserRoleList(userQuery));
    }
    @PutMapping("modify-add-role")
    @ApiOperation(value = "添加角色")
    @Override
    public JsonVO<Boolean> saveRole(@Validated UserRoleQuery userQuery) {
        return JsonVO.success(sysUserRoleService.saveRole(userQuery));
    }
    @PutMapping("modify-delete-role")
    @ApiOperation(value = "取消角色")
    @Override
    public JsonVO<Boolean> deleteRole(@Validated UserRoleQuery userQuery) {
        return JsonVO.success(sysUserRoleService.deleteRole(userQuery));
    }


    @GetMapping("/user-export")
    @ApiOperation(value = "用户导出")
    @Override
    public JsonVO<String> userExport(HttpServletResponse response) throws IOException {

        //写入Excel文件
        userService.userExport(response);
        return JsonVO.success("用户导出成功");
    }


    @PostMapping("/user-import")
    @ApiOperation(value = "用户导入")
    @Override
    public JsonVO<String> userImport(MultipartFile file) throws IOException {
        userService.userImport(file);
        return JsonVO.success("用户导入成功");
    }

    @GetMapping("/user-template")
    @ApiOperation(value = "下载用户导入模版")
    @Override
    public JsonVO<String> downloadUserTemplate(HttpServletResponse response) throws IOException {
        userService.downloadUserTemplate(response);
        return JsonVO.success("用户导出模版下载成功");
    }
}
