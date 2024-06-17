package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

/**
 * sys_role表映射实体类
 */
@Data
@TableName("sys_role")
public class RoleDO {
	// 角色ID
	@TableId(value = "role_id", type = IdType.AUTO)
	private Long roleId;
	// 角色名称
	@TableField(value = "role_name")
	public String roleName;
	// 角色权限字符串
	@TableField(value = "role_key")
	private String roleKey;
	// 显示顺序
	@TableField(value = "role_sort")
	private Integer roleSort;
	//数据范围（1：全部数据权限 2：自定数据权限 3：本部门数据权限 4：本部门及以下数据权限）
	@TableField(value = "data_scope")
	private String dataScope;
	//菜单树选择项是否关联显示
	@TableField(value = "menu_check_strictly")
	private Integer menuCheckStrictly;
	//部门树选择项是否关联显示
	@TableField(value = "dept_check_strictly")
	private Integer deptCheckStrictly;
	//角色状态（0正常 1停用）
	@TableField(value = "status")
	private String status;
	//删除标志（0代表存在 2代表删除）
	@TableLogic(value = "0", delval = "2")
	private String del_flag;
	//创建者
	@TableField(value = "create_by")
	private String createBy;
	//创建时间
	@TableField(value = "create_time")
	public String createTime;
	//更新者
	@TableField(value = "update_by")
	private String updateBy;
	//更新时间
	@TableField(value = "update_time")
	private String updateTime;
	//备注
	@TableField(value = "remark")
	private String remark;
}
