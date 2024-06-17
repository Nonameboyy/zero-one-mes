package com.zeroone.star.project.j1.mycenter.dto.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.time.LocalDateTime;

@Data
@ApiModel("用户传输对象")
public class UserDTO {

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

    @ApiModelProperty(value = "创建时间",example = "2023-11-20 21:19:01")
    private LocalDateTime createTime;






}
