package com.zeroone.star.project.j1.orgstructure.query.user;

import com.zeroone.star.project.j1.orgstructure.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;
import java.util.List;

/**
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author
 * @version 1.0.0
 */
@Data
@ApiModel("用户列表查询对象")
public class UserRoleQuery extends PageQuery {
    @ApiModelProperty(value = "用户名称", example = "admin")
    private String userName;
    @ApiModelProperty(value = "手机号码", example = "18888888888")
    private String phonenumber;
    @ApiModelProperty(value = "用户账号状态(0:正常 1:停用)", example = "1")
    private String status;
    @ApiModelProperty(value = "创建时间：开始日期", example = "2024-05-20")
    private String beginDate;
    @ApiModelProperty(value = "创建时间：结束日期", example = "2024-05-21")
    private String endDate;

    @ApiModelProperty(value = "用户编号",example = "1")
    private Long userId;
    /**
     *角色ID
     */
    @ApiModelProperty(value = "角色编号",example = "[4,5]")
    private List<Long> roleId;
}
