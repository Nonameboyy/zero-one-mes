package com.zeroone.star.project.j2.orgstructure.dto.role;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

/**
 * 描述：
 *
 * @author 0xu0
 * @version 1.0.0
 */
@Data
@ApiOperation("新增角色信息传输对象")
public class RoleAddDto {
    @ApiModelProperty(value = "角色名称",example = "经理")
    @Pattern(regexp = "^[\\u4e00-\\u9fa5a-zA-Z0-9]+$",message = "只能输入汉字英文数字")
    @NotBlank(message = "角色名称不能为空")
    private String roleName;
    @ApiModelProperty(value = "角色权限字符串",example = "common")
    @NotBlank(message = "权限字符不能为空")
    private String roleKey;
    @ApiModelProperty(value = "角色顺序(角色排列顺序)",example = "1")
    @Min(value = 1, message = "角色顺序必须是正整数")
    @NotNull(message = "角色顺序不能为空")
    private Integer roleSort;
    @ApiModelProperty(value = "角色状态(0正常，1停用）",example = "0")
    @Pattern(regexp = "0|1",message = "角色状态(0正常，1停用）")
    @NotBlank(message = "角色状态不能为空")
    private String status;
    @ApiModelProperty(value = "是否父子联动(0停用，1启用)",example = "1")
    @Pattern(regexp = "0|1",message = "是否父子联动(0停用，1启用)")
    @NotBlank(message = "父子联动选项不能为空")
    private String menuCheckStrictly;
    @ApiModelProperty(value = "菜单树选项是否关联显示（0是，1否）",example = "0")
    @Pattern(regexp = "0|1",message = "菜单树选项是否关联显示（0是，1否）")
    @NotBlank(message = "菜单树选项不能为空")
    private String deptCheckStrictly;
    @ApiModelProperty(value = "备注",example = "")
    private String remark;
}
