package com.zeroone.star.orgstructure.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableLogic;
import com.baomidou.mybatisplus.annotation.TableName;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

@Data
@TableName("sys_user")
public class User {
    @TableId(type = IdType.AUTO)
    @ApiModelProperty(value = "用户ID", example = "1", required = true)
    private Long userId;
    @ApiModelProperty(value = "部门ID", example = "4")
    private Long deptId;
    @ApiModelProperty(value = "用户账户", example = "admin", required = true)
    private String userName;
    @ApiModelProperty(value = "用户昵称", example = "管理员", required = true)
    private String nickName;
    @ApiModelProperty(value = "用户类型 00为系统用户", example = "00")
    private String userType;
    @ApiModelProperty(value = "用户邮箱", example = "admin@163.com")
    private String email;
    @ApiModelProperty(value = "手机号码", example = "13299106672")
    private String phonenumber;
    @ApiModelProperty(value = "用户性别 0男 1女 2未知", example = "0")
    private char sex;
    @ApiModelProperty(value = "头像地址", example = "/profile/avatar/2024/04/11/blob_20240411220241A003.jpeg")
    private String avatar;
    @ApiModelProperty(value = "密码", example = "123456")
    private String password;
    @ApiModelProperty(value = "账号状态 0正常 1停用", example = "0")
    private char status;
    @TableLogic(value = "0", delval = "2")
    @ApiModelProperty(value = "删除标志", example = "0")
    private String delFlag;
    @ApiModelProperty(value = "最后登陆ip", example = "127.0.0.1")
    private String loginIp;
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "最后登陆时间", example = "2024-04-11 16:58:02")
    private LocalDateTime loginDate;
    @ApiModelProperty(value = "创建者", example = "admin")
    private String createBy;
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建时间", example = "2022-04-07 00:29:31")
    private LocalDateTime createTime;
    @ApiModelProperty(value = "更新者", example = "admin")
    private String updateBy;
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "更新时间", example = "2024-04-11 16:58:02")
    private LocalDateTime updateTime;
    @ApiModelProperty(value = "备注", example = "管理员")
    private String remark;


}
