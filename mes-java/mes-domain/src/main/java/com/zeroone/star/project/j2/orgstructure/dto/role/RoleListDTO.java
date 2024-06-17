package com.zeroone.star.project.j2.orgstructure.dto.role;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import javax.validation.constraints.Pattern;

/**
 * @author: 魏玉石
 * @data: 2024/5/24
 * @description:
 */
@Data
@ApiOperation(value = "角色查询列表")
public class RoleListDTO {



    //角色编号
    @ApiModelProperty(value = "角色编号", example = "1")
    private String roleId;

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
    @ApiModelProperty(value = "状态", example = "1")
    @Pattern(regexp = "0|1", message = "角色状态只能是0或1")
    private String status;

    //创建时间
    @ApiModelProperty(value = "创建时间", example = "2022-04-07 00:29:31")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private String createTime;


}
