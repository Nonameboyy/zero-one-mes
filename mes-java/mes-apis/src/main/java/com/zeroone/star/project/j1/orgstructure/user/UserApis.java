package com.zeroone.star.project.j1.orgstructure.user;

import com.zeroone.star.project.j1.orgstructure.dto.PageDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.*;
import com.zeroone.star.project.j1.orgstructure.query.user.UserQuery;
import com.zeroone.star.project.j1.orgstructure.query.user.UserRoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

/**
 * <p>
 *     描述：用户管理接口
 * </p>
 * @author Tme
 * @version 1.0.0
 */
public interface UserApis {
    /**
     * 获取用户列表
     * @param userQuery 查询条件对象
     * @return 查询结果列表
     */
    JsonVO<List<UserDTO>> queryUserList(UserQuery userQuery);
    /**
     * 获取用户详情
     * @param userDTO 查询条件对象
     * @return 查询结果
     */
    JsonVO<CompleteUserDTO> queryUser(UserDTO userDTO);


	/**
	 * 设置用户状态
	 */
	public JsonVO setUserStatus(UpdateUserStatusDTO userIdStatus);

	/**
	 * 重置用户密码
	 */
	public JsonVO resetUserPassword(Integer userId);


    /**
     * 查询角色列表
     * @param userQuery
     * @return
     */
    JsonVO<PageDTO<SysRoleDTO>> queryRoleList(UserQuery userQuery);
    /**
     * 查询用户分配角色列表
     * @param userQuery
     * @return
     */

    JsonVO<PageDTO<SysUserRoleDTO>> queryUserRoleList(UserRoleQuery userQuery);
    /**
     * 添加角色
     * @param  userQuery
     * @return
     */
    JsonVO<Boolean> saveRole(UserRoleQuery userQuery);
    /**
     * 取消角色
     * @param  userQuery
     * @return
     */
    JsonVO<Boolean> deleteRole(UserRoleQuery userQuery);


    /**
     * 新增用户
     * @param addUserDTO 新增用户信息
     * @return 返回信息
     */
    JsonVO<String> addUser(AddUserDTO addUserDTO);

    /**
     * 更新用户信息
     * @param updateUserDTO 更新用户信息
     * @return 返回信息
     */
    JsonVO<String> modifyUser(UpdateUserDTO updateUserDTO);

    /**
     * 删除用户
     * @param userIds 用户ID
     * @return 返回信息
     */
    JsonVO<String> removeUser(List<Long> userIds);

    /**
     * 用户导出
     * @param
     * @return 返回excel文件
     */
    JsonVO<String> userExport(HttpServletResponse response) throws IOException;

    /**
     * 用户导入
     * @param
     * @return
     */
    JsonVO<String> userImport(MultipartFile file) throws IOException;

    /**
     * 用户导出
     * @param
     * @return 返回excel文件
     */
    JsonVO<String> downloadUserTemplate(HttpServletResponse response) throws IOException;

}
