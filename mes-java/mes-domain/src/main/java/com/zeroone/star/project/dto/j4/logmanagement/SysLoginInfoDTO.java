package com.zeroone.star.project.dto.j4.logmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @Description
 * @Author diwu
 * @Date 2024/5/19
 */
@Data
@ApiModel("操作登录日志的基本的数据传输信息对象")
public class SysLoginInfoDTO {
    /**
     * 访问ID
     */
    @ApiModelProperty(value = "用户的访问编号",example = "1")
    private Long infoId;

    /**
     * 用户账号
     */
    @ApiModelProperty(value = "用户的名称",example = "小明")
    private String userName;

    /**
     * 登录IP地址
     */
    @ApiModelProperty(value = "登录IP地址",example = "192.168.200.129")
    private String ipaddr;

    /**
     * 登录地点
     */
    @ApiModelProperty(value = "登录的地点",example = "上海")
    private String loginLocation;

    /**
     * 浏览器类型
     */
    @ApiModelProperty(value = "浏览器的类型",example = "Chrome 12")
    private String browser;

    /**
     * 操作系统
     */
    @ApiModelProperty(value = "操作系统",example = "OS")
    private String os;

    /**
     * 登录状态（0成功 1失败）
     */
    @ApiModelProperty(value = "登录的状态",example = "0 代表成功， 1 代表失败")
    private String status;

    /**
     * 提示消息
     */
    @ApiModelProperty(value = "登录的状态",example = "登录成功")
    private String msg;

    /**
     * 访问时间
     */
    @ApiModelProperty(value = "登录的访问时间",example = "2024-05-19 00:08:59")
    private Date loginTime;
}
