package com.zeroone.star.project.j1.syslogin.vo;

import com.baomidou.mybatisplus.annotation.TableField;
import com.zeroone.star.project.j1.syslogin.vo.currUserInfovo.PostVO;
import com.zeroone.star.project.j1.syslogin.vo.currUserInfovo.RoleVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.ArrayList;
import java.util.List;

@Data
@ApiModel("当前用户信息")
public class CurrentUserInfoVO {
	// 用户信息
	@ApiModelProperty(value = "头像地址")
	public String avatar;
	@ApiModelProperty(value = "用户名称")
	public String user_name;
	@ApiModelProperty(value = "手机号码")
	public String phonenumber;
	@ApiModelProperty(value = "邮箱")
	public String email;
	@ApiModelProperty(value = "用户昵称")
	public String nickName;
	@ApiModelProperty(value = "性别")
	public String sex;
	@ApiModelProperty(value = "用户创建时间")
	public String createTime;

	// 用户所属部门
	@ApiModelProperty(value = "所属部门")
	public String dept_name;

	// 用户的角色信息
	@ApiModelProperty(value = "用户的角色信息")
	public List<RoleVO> roleInfo = new ArrayList<>();

	// 岗位名称
	@ApiModelProperty(value = "岗位名称")
	public List<PostVO> postInfo = new ArrayList<>();

	public void setRoleInfo(RoleVO roleVO) {
		this.roleInfo.add(roleVO);
	}

	public void setPost(PostVO postVO) {
		this.postInfo.add(postVO);
	}
}
