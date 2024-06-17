package com.zeroone.star.project.dto.j4.sysmanagement.logmanagement.LoginLog;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.Date;

/**
 * @Author: jingzi
 * @createTime: 2024-05-19
 * @description: 登录日志的基本传输数据对象
 */
@Data
@ApiModel("登录日志传输数据对象")
public class LoginLogAddDTO {
    /**
     * 用户访问编号
     */
    @ApiModelProperty(value = "用户访问编号",example = "1")
    private Long infoId;

    /**
     * 用户名称
     */
    @ApiModelProperty(value = "用户名称",example = "admin")
    private String userName;

    /**
     * 登录地址
     */
    @ApiModelProperty(value = "登录地址",example = "127.0.0.1")
    private String ipaddr;

    /**
     * 登录地点
     */
    @ApiModelProperty(value = "登录地点",example = "内网IP")
    private String loginLocation;

    /**
     * 浏览器类型
     */
    @ApiModelProperty(value = "浏览器类型",example = "Chrome 12")
    private String browser;

    /**
     * 操作系统
     */
    @ApiModelProperty(value = "操作系统",example = "OS")
    private String os;

    /**
     * 登录状态（0成功 1失败）
     */
    @ApiModelProperty(value = "登录状态",example = "0 代表成功， 1 代表失败")
    private String status;

    /**
     * 提示消息
     */
    @ApiModelProperty(value = "提示消息",example = "登录成功")
    private String msg;

    /**
     * 访问时间
     */
    @ApiModelProperty(value = "访问时间",example = "2024-05-19 10:00:00")
    private LocalDateTime loginTime;
}
