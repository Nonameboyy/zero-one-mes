package com.zeroone.star.project.j1.syslogin.vo.currUserInfovo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("岗位信息-post")
public class PostVO {

	@ApiModelProperty(value = "岗位名称")
	public String postName;
}
