package com.zeroone.star.project.j2.orgstructure.query.role;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import javax.validation.constraints.Pattern;

/**
 * @author: 魏玉石
 * @data: 2024/5/24
 * @description: 数据权限回显
 */
@ApiOperation(value = "数据权限回显")
@Data
public class RolePermissionsQuery {
    //角色编号
    @ApiModelProperty(value = "角色编号", example = "1")
    private String roleId;

    @ApiModelProperty(value = "角色名称", example = "1")
    private String roleName;

    //角色权限字符串
    @ApiModelProperty(value = "角色权限字符串", example = "admin")
    private String roleKey;

    @ApiModelProperty(value = "数据范围", example = "1")
    @Pattern(regexp = "1|2|3|4|5" , message = "数据范围（1：全部数据权限 2：自定数据权限 3：本部门数据权限 4：本部门及以下数据权限 5:仅本人数据权限）")
    private String dataScope;

}
