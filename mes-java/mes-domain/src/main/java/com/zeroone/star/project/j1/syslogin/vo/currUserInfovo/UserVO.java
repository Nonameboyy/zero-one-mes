package com.zeroone.star.project.j1.syslogin.vo.currUserInfovo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("用户信息-user")
public class UserVO {
	@ApiModelProperty(value = "头像地址")
	public String avatar;
	@ApiModelProperty(value = "用户名称")
	public String user_name;
	@ApiModelProperty(value = "手机号码")
	public String phonenumber;
	@ApiModelProperty(value = "邮箱")
	public String email;
}
