package com.zeroone.star.project.j1.syslogin.vo.currUserInfovo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("部门信息-dept")
public class DeptVO {

	@ApiModelProperty(value = "所属部门")
	public String dept_name;
}
