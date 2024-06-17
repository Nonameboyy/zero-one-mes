package com.zeroone.star.project.j2.orgstructure.query.role;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;

@Data
public class UserRoleQuery {
    //页码
    @Min(value = 1,message = "页码不能小于1")
    @ApiModelProperty(value = "查询页码",example = "1")
    private long pageIndex;
    //数据条数
    @Min(value = 1,message = "数据条数不能小于1")
    @ApiModelProperty(value = "查询数据条数",example = "10")
    private long pageSize;

    @ApiModelProperty(value = "角色id", example = "1")
    private String roleId;

    @ApiModelProperty(value = "用户名称", example = "1")
    private String userName;

    @ApiModelProperty(value = "用户昵称", example = "1")
    private String nickName;

    @ApiModelProperty(value = "用户邮箱", example = "1")
    private String email;

    @ApiModelProperty(value = "用户手机号", example = "13400000000")
    private String phoneNumber;

    @ApiModelProperty(value = "用户状态(0正常，1停用）",example = "0")
    private String status;

    @ApiModelProperty(value = "更新时间", example = "2024-05-18 08:42:03")
    private Data createTime;
}
