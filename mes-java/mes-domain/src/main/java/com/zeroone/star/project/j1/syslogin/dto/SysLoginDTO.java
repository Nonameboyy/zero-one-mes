package com.zeroone.star.project.j1.syslogin.dto;

import io.swagger.annotations.ApiModelProperty;

public class SysLoginDTO {
        /**
         * 用户名
         */
        @ApiModelProperty(value = "用户名", example = "admin", required = true)
        private String username;

        /**
         * 密码
         */
        @ApiModelProperty(value = "密码", example = "123456", required = true)
        private String password;

        /**
         * 验证码
         */
        @ApiModelProperty(value = "验证码", example = "999818")
        private String code;
}
