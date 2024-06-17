package com.zeroone.star.project.j5.query.teamsettings;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Author: Liang
 * @Date: 2024/05/21/19:06
 * @Description:班组成员的查询
 */
@Data
@ApiModel("查询人员")
public class MemberQuery extends PageQuery {
    @ApiModelProperty(value = "部门名称id", example = "210")
    private String teamId;
    @ApiModelProperty(value = "手机号码", example = "17565656565")
    private String phonenumber;
    @ApiModelProperty(value = "用户名称", example = "demo")
    private String username;
}
