package com.zeroone.star.project.j1.syslogin.vo.currUserInfovo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("角色信息-role")
public class RoleVO {

	@ApiModelProperty(value = "所属角色")
	public String roleName;

	/*@ApiModelProperty(value = "角色创建时间")
	public String createTime;*/
}
