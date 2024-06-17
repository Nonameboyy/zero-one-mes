package com.zeroone.star.project.j1.orgstructure.dto.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("所有角色数据模型")
public class SysRoleDTO {

    /**
     *角色编号
     */
    @ApiModelProperty(value = "角色编号",example = "1")
    private String roleId;
    /**
     *角色名称
     */
    @ApiModelProperty(value = "角色名字",example = "测试员")
    private String roleName;
    /**
     *权限字符
     */
    @ApiModelProperty(value = "权限字符",example = "tester")
    private String roleKey;
    /**
     *创建时间
     */
    @ApiModelProperty(value = "创建时间",example = "2022-05-04 17:57:40")
    private String createTime;
}
