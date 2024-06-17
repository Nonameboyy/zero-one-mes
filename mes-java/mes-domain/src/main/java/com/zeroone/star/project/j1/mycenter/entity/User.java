package com.zeroone.star.project.j1.mycenter.entity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("用户传输对象")
public class User {

    @ApiModelProperty(value = "用户ID",example = "1")
    private Long userId;

    @ApiModelProperty(value = "部门ID",example = "3")
    private Long deptId;

    @ApiModelProperty(value = "所属部门",example = "1")
    private String deptName;

    @ApiModelProperty(value = "用户名",example = "张三")
    private String userName;

    @ApiModelProperty(value = "昵称",example = "法外狂徒")
    private String nickName;

    @ApiModelProperty(value = "用户类型",example = "经理")
    private String userType;

    @ApiModelProperty(value = "邮箱",example = "xxxxxx@qq.com")
    private String email;

    @ApiModelProperty(value = "电话",example = "张三")
    private String phonenumber;

    @ApiModelProperty(value = "性别",example = "男")
    private String sex;

    @ApiModelProperty(value = "头像",example = "xxxx.jpg")
    private String avatar;

    @ApiModelProperty(value = "密码",example = "xxxxxx")
    private String password;

    //  账号状态 (0正常 1停用)
    @ApiModelProperty(value = "状态",example = "1")
    private String status;

    //删除标志（0代表存在 2代表删除）
    @ApiModelProperty(value = "删除状态",example = "2")
    private String delFlag;

    @ApiModelProperty(value = "最后登录Ip",example = "192.168.88.130")
    private String loginIp;

    @ApiModelProperty(value = "更新时间",example = "2024-2-22 10:19:01")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "最后登录时间",example = "2023-12-22 22:19:01")
    private LocalDateTime loginDate;

    @ApiModelProperty(value = "创建者",example = "张三")
    private String createBy;

    @ApiModelProperty(value = "更新者",example = "李四")
    private String updateBy;

    @ApiModelProperty(value = "备注",example = "注意xxx事项")
    private String remark;

    @ApiModelProperty(value = "创建时间",example = "2023-11-20 21:19:01")
    private LocalDateTime createTime;
}