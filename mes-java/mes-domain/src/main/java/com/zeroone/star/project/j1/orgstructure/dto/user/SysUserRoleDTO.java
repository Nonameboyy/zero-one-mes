package com.zeroone.star.project.j1.orgstructure.dto.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@ApiModel("用户角色数据模型")
@AllArgsConstructor
@NoArgsConstructor
public class SysUserRoleDTO {
    /**
     *用户id
     */
    @ApiModelProperty(value = "用户id",example = "1")
    private Long userId;
    /**
     *角色id
     */
    @ApiModelProperty(value = "角色id",example = "1")
    private Long roleId;
}
