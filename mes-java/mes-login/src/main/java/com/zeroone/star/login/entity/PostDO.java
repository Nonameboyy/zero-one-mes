package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

/**
 * sys_post表映射实体类
 */
@Data
@TableName("sys_post")
public class PostDO {
	// 岗位ID
	@TableId(value = "post_id", type = IdType.AUTO)
	private Long postId;
	// 岗位编码
	@TableField(value = "post_code")
	private String postCode;
	// 岗位名称
	@TableField(value = "post_name")
	public String postName;
	// 显示顺序
	@TableField(value = "post_sort")
	private Integer postSort;
	// 状态（0正常 1停用）
	@TableField(value = "status")
	private String status;
	// 创建者
	@TableField(value = "create_by")
	private String createBy;
	// 创建时间
	@TableField(value = "create_time")
	private String createTime;
	// 更新者
	@TableField(value = "update_by")
	private String updateBy;
	// 更新时间
	@TableField(value = "update_time")
	private String updateTime;
	// 备注
	@TableField(value = "remark")
	private String remark;
}

