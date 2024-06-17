package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

/**
 * sys_dept表映射实体类
 */
@Data
@TableName("sys_dept")
public class DeptDO {
	//部门ID
	@TableId(value = "dept_id", type = IdType.AUTO)
	private Integer deptId;
	//父部门ID
	@TableField(value = "parent_id")
	private Integer parentId;
	//祖级列表
	@TableField(value = "ancestors")
	private String ancestors;
	//部门名称
	@TableField(value = "dept_name")
	private String deptName;
	//显示顺序
	@TableField(value = "order_num")
	private Integer orderNum;
	//负责人
	@TableField(value = "leader")
	private String leader;
	//联系电话
	@TableField(value = "phone")
	private String phone;
	//邮箱
	@TableField(value = "email")
	private String email;
	//部门状态（0正常 1停用）
	@TableField(value = "status")
	private String status;
	//删除标志（0代表存在 2代表删除）
	@TableLogic(value = "0", delval = "2")
	private String del_Flag;
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
