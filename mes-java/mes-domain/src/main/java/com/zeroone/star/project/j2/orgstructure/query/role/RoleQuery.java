package com.zeroone.star.project.j2.orgstructure.query.role;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import javax.validation.constraints.Pattern;

/**
 * @author: 天衍土豆 迷 0xu0
 * @data: 2024/5/17
 * @description:
 */
@Data
@ApiOperation(value = "角色查询详情")
public class RoleQuery {

    @ApiModelProperty(value = "角色ID（主键，可自增）", example = "")
    private long roleId;

    //角色名称
    @ApiModelProperty(value = "角色名称", example = "超级系统管理员")
    private String roleName;

    //角色权限字符串
    @ApiModelProperty(value = "角色权限字符串", example = "admin")
    private String roleKey;

    //显示顺序
    @ApiModelProperty(value = "显示顺序", example = "1")
    private Integer roleSort;

    //状态(0:正常,1:停用)
    @ApiModelProperty(value = "角色状态(0启动，1停用）", example = "0")
    @Pattern(regexp = "0|1", message = "角色状态只能是0或1")
    private String status;

    @ApiModelProperty(value = "数据范围", example = "1")
    @Pattern(regexp = "1|2|3|4" , message = "数据范围（1：全部数据权限 2：自定数据权限 3：本部门数据权限 4：本部门及以下数据权限）")
    private String dataScope;

    //菜单树选择项是否关联显示
    @ApiModelProperty(value = "菜单树选择项是否关联显示", example = "true")
    private Boolean menuCheckStrictly;

    @ApiModelProperty(value = "创建者", example = "")
    private String createBy;

    @ApiModelProperty(value = "创建时间", example = "2024-05-18 08:42:03")
    private String createTime;

    @ApiModelProperty(value = "更新者", example = "")
    private String updateBy;

    @ApiModelProperty(value = "更新时间", example = "2024-05-18 08:42:03")
    private String updateTime;

    @ApiModelProperty(value = "备注", example = "")
    private String remark;
}
