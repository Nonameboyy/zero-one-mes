package com.zeroone.star.project.j1.mycenter.DO;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

@Data
@ApiModel("数据对象")
@TableName("sys_user")
public class sysUserDO {
    //用户头像
    @ApiModelProperty(value = "头像url",example = "a/b/c/1.jpg")
    private String avatar;

    //用户昵称
    @ApiModelProperty(value = "昵称",example = "zhangsan")
    private String nick_name;

    //手机号码
    @ApiModelProperty(value = "手机号",example = "10086")
    private String phonenumber;

    //用户邮箱
    @ApiModelProperty(value = "邮箱",example = "1234@qq.com")
    private String email;

    //性别
    @ApiModelProperty(value = "性别",example = "男")
    private char sex;

    //更新时间
    @ApiModelProperty(value = "更新时间",example = "2023-11-20 21:19:01")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime update_time;

    //id
    @ApiModelProperty(value = "id",example = "1324")
    private int user_id;

    //密码
    @ApiModelProperty(value = "密码",example = "123456")
    private String password;
}
