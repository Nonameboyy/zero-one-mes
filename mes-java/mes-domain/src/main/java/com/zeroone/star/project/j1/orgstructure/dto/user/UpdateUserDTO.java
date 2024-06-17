package com.zeroone.star.project.j1.orgstructure.dto.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * 更新用户数据模型
 */
@Data
@ApiModel("更新用户")
public class UpdateUserDTO {
    @ApiModelProperty(value = "用户ID", example = "1", required = true)
    private Long userId;
    @ApiModelProperty(value = "部门ID", example = "4")
    private Long deptId;
    @ApiModelProperty(value = "岗位ID", example = "[1,2,3]")
    private List<Long> postId;
    @ApiModelProperty(value = "角色ID", example = "[1,2]")
    private List<Long> roleId;
    @ApiModelProperty(value = "用户昵称", example = "管理员", required = true)
    private String nickName;
    @ApiModelProperty(value = "用户类型 00为系统用户", example = "00")
    private String userType;
    @ApiModelProperty(value = "用户邮箱", example = "admin@163.com")
    private String email;
    @ApiModelProperty(value = "手机号码", example = "13299106672")
    private String phonenumber;
    @ApiModelProperty(value = "用户性别 0男 1女 2未知", example = "'0'")
    private char sex;
    @ApiModelProperty(value = "账号状态 0正常 1停用", example = "'0'")
    private char status;
    @ApiModelProperty(value = "更新者", example = "admin")
    private String updateBy;
//    @ApiModelProperty(value = "更新时间", example = "2024-04-11 16:58:02")
//    private LocalDateTime updateTime;
    @ApiModelProperty(value = "备注", example = "管理员")
    private String remark;
}
