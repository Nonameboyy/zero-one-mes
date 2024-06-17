package com.zeroone.star.project.j5.vo.teamsettings;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;
import java.util.List;

/**
 * @Author: Liang
 * @Date: 2024/05/21/19:05
 * @Description:班组成员的数图对象
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class MemberVO {
    @ApiModelProperty(value = "参数", example = "1")
    private Object params;
    @ApiModelProperty(value = "用户编号", example = "1")
    private Integer userId;
    @ApiModelProperty(value = "部门编号", example = "210")
    private Integer teamId;
    @ApiModelProperty(value = "用户名称", example = "demo")
    private String userName;
    @ApiModelProperty(value = "用户昵称", example = "test")
    private String nickName;
    @ApiModelProperty(value = "手机号码", example = "17565656565")
    private String phonenumber;
    @ApiModelProperty(value = "状态", example = "0")//0表示正常 1表示停用
    private String status;
    @ApiModelProperty(value = "创建时间", example = "2022-08-19 09:03:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;
}
