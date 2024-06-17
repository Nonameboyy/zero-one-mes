package com.zeroone.star.project.j1.mycenter.dto;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.annotation.JsonCreator;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.zeroone.star.project.j1.mycenter.DO.sysUserDO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;
import org.springframework.web.multipart.MultipartFile;

import java.time.LocalDateTime;

@Data
@ApiModel("用户传输对象")
public class MyCenterDTO {
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

    //错误原因
    @ApiModelProperty(value = "错误信息",example = "格式不正确")
    private String fail_msg;

    @ApiModelProperty(value = "头像文件",example = "111.jpg")
    private MultipartFile image;


}
