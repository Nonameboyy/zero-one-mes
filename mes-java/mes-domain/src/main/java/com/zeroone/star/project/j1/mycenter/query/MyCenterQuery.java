package com.zeroone.star.project.j1.mycenter.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * @author 柱
 * @version 1.0.0
 *
 */
@Data
@ApiModel("用户传输对象")
public class MyCenterQuery {

    @ApiModelProperty(value = "头像url",example = "111.jpg")
    private String ParttenUrl;

    //用户名称
    @ApiModelProperty(value = "用户名",example = "zhangsan")
    private String UserName;

    //用户昵称
    @ApiModelProperty(value = "昵称",example = "zhangsan")
    private String NickName;

    //手机号码
    @ApiModelProperty(value = "手机号",example = "10086")
    private String Phone;

    //用户邮箱
    @ApiModelProperty(value = "邮箱",example = "1234@qq.com")
    private String Email;

    //所属部门
    @ApiModelProperty(value = "部门",example = "生产部")
    private String Dept;

    //所属角色
    @ApiModelProperty(value = "角色",example = "牛马")
    private String Role;

    //创建日期
    @ApiModelProperty(value = "创建日期",example = "2023-11-20 21:19:01")
    private LocalDateTime CreateTime;

    //性别
    @ApiModelProperty(value = "性别",example = "男")
    private String Sex;

}
