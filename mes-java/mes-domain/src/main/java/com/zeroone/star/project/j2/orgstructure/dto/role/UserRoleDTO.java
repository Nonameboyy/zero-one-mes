package com.zeroone.star.project.j2.orgstructure.dto.role;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
public class UserRoleDTO {
    @ApiModelProperty(value = "用户Id",example = "")
    private Integer userId;
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
    private LocalDateTime createTime;

}
