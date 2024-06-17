package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

/**
 * sys_user表映射实体类
 */
@Data
@TableName("sys_user")
public class UserDO {
	//用户ID
	@TableId(value = "user_id", type = IdType.AUTO)
	private Long user_id;
	//部门ID
	@TableField(value = "dept_id")
	private Long deptId;
	//用户账号
	@TableField(value = "user_name")
	private String userName;
	//用户昵称
	@TableField(value = "nick_name")
	private String nickName;
	//用户类型（00系统用户）
	@TableField(value = "user_type")
	private String userType;
	//用户邮箱
	@TableField(value = "email")
	private String email;
	//手机号码
	@TableField(value = "phonenumber")
	private String phoneNumber;
	//用户性别（0男 1女 2未知）
	@TableField(value = "sex")
	private String sex;
	//头像地址
	@TableField(value = "avatar")
	private String avatar;
	//密码
	@TableField(value = "password", select = false)
	private String password;
	//帐号状态（0正常 1停用）
	@TableField(value = "status")
	private String status;
	//删除标志（0代表存在 2代表删除）
	@TableLogic(value = "0", delval = "2")
	private String del_flag;
	//最后登录IP
	@TableField(value = "login_ip")
	private String loginIp;
	//最后登录时间
	@TableField(value = "login_date")
	private String loginDate;
	//创建者
	@TableField(value = "create_by")
	private String createBy;
	//创建时间
	@TableField(value = "create_time")
	private String createTime;
	//更新者
	@TableField(value = "update_by")
	private String updateBy;
	//更新时间
	@TableField(value = "update_time")
	private String updateTime;
}

