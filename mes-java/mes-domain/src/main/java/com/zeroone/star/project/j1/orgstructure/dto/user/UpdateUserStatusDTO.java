package com.zeroone.star.project.j1.orgstructure.dto.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("设置用户状态")
public class UpdateUserStatusDTO {
	/**
	 * 用户ID
	 */
	@ApiModelProperty(value = "用户ID", required = true)
	private Integer user_id;
	/**
	 * 用户状态(0正常，1停用)
	 */
	@ApiModelProperty(value = "用户状态(0正常，1停用)",required = true)
	private Integer status;
}
