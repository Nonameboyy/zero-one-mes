package com.zeroone.star.project.j2.orgstructure.dto.role;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import javax.validation.constraints.Pattern;

/**
 * @author: 天衍土豆、0xu0 、迷
 * @data: 2024/5/17
 * @description:
 */
@Data
@ApiOperation("部门传输数据对象")
public class RoleDTO {

    //角色名称
    @ApiModelProperty(value = "角色名称", example = "1")
    private String roleName;


    //角色权限字符串
    @ApiModelProperty(value = "角色权限字符串", example = "admin")
    private String roleKey;

    //显示顺序
    @ApiModelProperty(value = "显示顺序", example = "1")
    private Integer roleSort;


    @ApiModelProperty(value = "数据范围", example = "1")
    @Pattern(regexp = "1|2|3|4|5" , message = "数据范围（1：全部数据权限 2：自定数据权限 3：本部门数据权限 4：本部门及以下数据权限 5:仅本人数据权限）")
    private String dataScope;


    //菜单树选择项是否关联显示
    @ApiModelProperty(value = "菜单树选择项是否关联显示", example = "true")
    private Boolean menuCheckStrictly;

    @ApiModelProperty(value = "角色ID（主键，可自增）", example = "")
    @TableId(type =IdType.AUTO)
    private long roleId;
    @ApiModelProperty(value = "角色状态(0启动，1停用）", example = "0")
    @Pattern(regexp = "0|1", message = "角色状态只能是0或1")
    private String status;
    @ApiModelProperty(value = "部门树选择是否关联显示", example = "")
    private String deptCheckStrictly;
    @ApiModelProperty(value = "删除标志（0代表存在 2代表删除）", example = "0")
    @Pattern(regexp = "0|2", message = "删除标志只能是0或2")
    private String delFlag;
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
