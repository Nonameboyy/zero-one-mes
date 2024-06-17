package com.zeroone.star.project.j2.orgstructure.role;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.orgstructure.dto.role.RoleAddDto;
import com.zeroone.star.project.j2.orgstructure.dto.role.RoleModifyDto;
import com.zeroone.star.project.j2.orgstructure.dto.role.RoleStatusModifyDto;
import com.zeroone.star.project.j2.orgstructure.dto.role.RoleDTO;
import com.zeroone.star.project.j2.orgstructure.query.role.RoleConditionQuery;
import com.zeroone.star.project.j2.orgstructure.dto.role.RoleListDTO;
import com.zeroone.star.project.j2.orgstructure.dto.role.RolePermissionsDTO;
import com.zeroone.star.project.j2.orgstructure.query.role.RolePermissionsQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.RequestBody;

import javax.validation.Valid;
import java.util.List;

/**
 * 描述：角色模块接口
 *
 * @author 0xu0、天衍土豆 迷
 * @version 1.0.0
 */
@Validated
public interface RoleApis {

    /**
     * 查询角色列表
     * @author 天衍土豆
     *
     */
    public JsonVO<List<RoleListDTO>> queryRoles();

    /**
     * 获取角色列表(条件+分页)
     * @author 天衍土豆
     */

    public JsonVO<PageDTO<RoleListDTO>> queryRolePage(RoleConditionQuery condition);
    /**
     * 获取角色详情
     * @author 天衍土豆
     */
    public JsonVO<RoleDTO> queryRole(Integer id);


    /**
     * 设置数据权限
     * @author 天衍土豆
     */
    public JsonVO<String> modifyRole(RolePermissionsQuery rolePermissionsQuery);

    /**
     * 添加角色
     *
     * @param roleDTO
     * @return
     * @author 0xu0
     * @author 0xu0
     */

    public JsonVO<Long> addRole(@RequestBody @Valid RoleAddDto roleDTO);
    /***
     * 修改角色状态（角色页面，有个开关符号，控制停用和启用）
     * @author 0xu0
     * @param roleStatusModifyDto
     * @return
     */

    public JsonVO<Integer> modifyRoleStatus( @RequestBody @Valid RoleStatusModifyDto roleStatusModifyDto);


    /**
     * 删除角色，支持批量删除
     * @author 0xu0
     * @param ids
     * @return
     */

    public JsonVO<List<String>> deleteRoles(List<String> ids);
    /**
     * 修改角色信息
     * @param roleDTO
     * @return
     */

    public JsonVO<Integer> modifyRoleInfo(@RequestBody @Valid RoleModifyDto roleDTO);

    /*
     * 获取角色分配用户列表（条件+分页）
     * */
/*
    public JsonVO<List<RoleDTO>> queryAllocatedList(Long roleId, int page, int size);
*/

    /*
     * 添加授权
     * */
    public JsonVO<RoleDTO> addAuth(Long roleId, Long[] userIds);


    /*
     * 取消授权
     * */
    //public JsonVO<Integer> cancelAuthUser(RoleDTO roleDTO);

    /*
     * 批量取消授权（支持批量）
     * */
    public JsonVO<Integer> cancelAuthUsers(Long roleId, Long[] userIds);

    /*
     * 导出角色
     * */
    public ResponseEntity<byte[]> export();

}
