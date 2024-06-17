package com.zeroone.star.project.j1.orgstructure.dto.user;

import com.alibaba.excel.annotation.ExcelProperty;
import com.alibaba.excel.annotation.write.style.ColumnWidth;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@NoArgsConstructor
@AllArgsConstructor
@Builder
@Data
@ApiModel("用户导出")
public class UserTemplateDTO {

    @ColumnWidth(20)
    @ApiModelProperty(value = "用户ID", example = "1")
    @ExcelProperty(value = "用户ID")
    private Long userId;

    @ColumnWidth(20)
    @ApiModelProperty(value = "用户账户", example = "admin")
    @ExcelProperty(value = "用户账户")
    private String userName;

    @ColumnWidth(20)
    @ExcelProperty(value = "用户昵称")
    @ApiModelProperty(value = "用户昵称", example = "若依")
    private String nickName;

//    @ApiModelProperty(value = "用户性别 0男 1女 2未知")
//    @ExcelProperty(value = "性别")
//    private char sex;

    @ColumnWidth(20)
    @ExcelProperty(value = "用户邮箱")
    @ApiModelProperty(value = "用户邮箱", example = "admin@163.com")
    private String email;

    @ColumnWidth(20)
    @ExcelProperty(value = "手机号码")
    @ApiModelProperty(value = "手机号码", example = "12345678")
    private String phonenumber;

    @ColumnWidth(20)
    @ExcelProperty(value = "最后登录ip")
    @ApiModelProperty(value = "最后登陆ip", example = "127.0.0.1")
    private String loginIp;

}

