package com.zeroone.star.orgstructure.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.List;

@Data
@TableName("sys_user_post")
public class UserPost {
    private Long userId;
    private Long postId;
}
