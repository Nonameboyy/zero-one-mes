package com.zeroone.star.project.j2.orgstructure.query.role;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import javax.validation.constraints.Pattern;

/**
 * @author: 魏玉石
 * @data: 2024/5/24
 * @description: 条件查询
 */
@ApiOperation("角色查询条件")
@Data
public class RoleConditionQuery extends PageQuery {
    @ApiModelProperty(value = "角色ID（主键，可自增）", example = "")
    private long roleId;

    //角色名称
    @ApiModelProperty(value = "角色名称",example = "超级系统管理员")
    private String roleName;


    //角色权限字符串
    @ApiModelProperty(value = "角色权限字符串",example = "admin")
    private String roleKey;


    //状态(0:正常,1:停用)
    @ApiModelProperty(value = "状态",example = "1")
    @Pattern(regexp = "0|1", message = "角色状态只能是0或1")
    private String status;

    //数据范围（1：全部数据权限 2：自定数据权限 3：本部门数据权限 4：本部门及以下数据权限）
    @ApiModelProperty(value = "起始时间",example = "2022-04-07")
    @JsonFormat(pattern = "yyyy-MM-dd")
    private String startTime;

    @ApiModelProperty(value = "结束时间",example = "2022-04-07")
    @JsonFormat(pattern = "yyyy-MM-dd")
    private String endTime;

    @ApiModelProperty(value = "数据范围", example = "1")
    @Pattern(regexp = "1|2|3|4|5" , message = "数据范围（1：全部数据权限 2：自定数据权限 3：本部门数据权限 4：本部门及以下数据权限 5:仅本人数据权限）")
    private String dataScope;
}
