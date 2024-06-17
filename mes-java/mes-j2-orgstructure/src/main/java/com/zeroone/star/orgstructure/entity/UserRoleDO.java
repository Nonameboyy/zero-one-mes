package com.zeroone.star.orgstructure.entity;

import com.baomidou.mybatisplus.annotation.TableName;

@TableName("sys_user_role")
public class UserRoleDO {
    /** 用户ID */
    private Long userId;

    /** 角色ID */
    private Long roleId;

    public Long getUserId()
    {
        return userId;
    }

    public void setUserId(Long userId)
    {
        this.userId = userId;
    }

    public Long getRoleId()
    {
        return roleId;
    }

    public void setRoleId(Long roleId)
    {
        this.roleId = roleId;
    }

    @Override
    public String toString() {
        return "UserRoleDO{" +
                "userId=" + userId +
                ", roleId=" + roleId +
                '}';
    }
}
