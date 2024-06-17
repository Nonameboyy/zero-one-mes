package com.zeroone.star.orgstructure.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 用户与岗位关联表
 * </p>
 *
 * @author 爱吃猫的鱼
 * @since 2024-05-22
 */
@Getter
@Setter
@TableName("sys_user_post")
public class UserAndPsotDO implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 用户ID
     */
    private Long userId;

    /**
     * 岗位ID
     */
    private Long postId;


}
