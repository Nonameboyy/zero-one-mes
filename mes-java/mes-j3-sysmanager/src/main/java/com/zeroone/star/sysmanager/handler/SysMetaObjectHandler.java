package com.zeroone.star.sysmanager.handler;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import com.zeroone.star.project.components.user.UserHolder;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：字段自动填充, 填充创建者/创建时间/更新者/更新时间
 * </p>
 * @author Ankh
 * @version 1.0.0
 */
@Component
public class SysMetaObjectHandler implements MetaObjectHandler {

    @Resource
    UserHolder userHolder;

    @Override
    public void insertFill(MetaObject metaObject) {
        String userName;
        try {
            userName = userHolder.getCurrentUser().getUsername();
        } catch (Exception e) {//当前无用户登录, 或没有传入token
            userName = "unKnow";
        }

        LocalDateTime now = LocalDateTime.now();

        //注入
        this.setFieldValByName("createBy", userName, metaObject);
        this.setFieldValByName("createTime", now, metaObject);
        this.setFieldValByName("updateBy", userName, metaObject);
        this.setFieldValByName("updateTime", now, metaObject);
    }

    @Override
    public void updateFill(MetaObject metaObject) {
        String userName;
        try {
            userName = userHolder.getCurrentUser().getUsername();
        } catch (Exception e) {//当前无用户登录, 或没有传入token
            userName = "unKnow";
        }

        LocalDateTime now = LocalDateTime.now();

        //注入
        this.setFieldValByName("updateBy", userName, metaObject);
        this.setFieldValByName("updateTime", now, metaObject);
    }
}
