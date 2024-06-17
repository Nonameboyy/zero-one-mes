package com.zeroone.star.project.j2.orgstructure.dto.role;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

/**
 * 描述：修改角色状态传输对象(角色管理页面中，状态开关）
 *
 * @author 0xu0
 * @version 1.0.0
 */
@Data
@ApiOperation("修改角色状态传输对象")
public class RoleStatusModifyDto {
    @ApiModelProperty(value = "角色编号",example = "1")
    @Min(value = 1, message = "角色编号必须是正整数")
    @NotNull(message = "角色编号不能为空")
    private Integer roleId;
    @ApiModelProperty(value = "角色状态(0正常，1停用）",example = "0")
    @Pattern(regexp = "0|1", message = "角色状态只能是0或1")
    @NotBlank(message = "角色状态不能为空")
    private String status;
}
