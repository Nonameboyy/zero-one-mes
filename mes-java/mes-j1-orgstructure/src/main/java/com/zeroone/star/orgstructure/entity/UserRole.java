package com.zeroone.star.orgstructure.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.List;

@Data
@TableName("sys_user_role")
public class UserRole {
    private Long userId;
    private Long roleId;
}
