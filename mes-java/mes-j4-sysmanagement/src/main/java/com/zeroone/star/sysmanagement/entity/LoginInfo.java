package com.zeroone.star.sysmanagement.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 系统访问记录
 * </p>
 *
 * @author jingzi
 * @since 2024-05-19
 */
@Getter
@Setter
@TableName("登录日志实体")
public class LoginInfo implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 访问ID
     */
    @TableId(value = "info_id", type = IdType.AUTO)
    @ExcelProperty(value = "访问ID", index = 0)
    private Long infoId;

    /**
     * 用户账号
     */
    @ExcelProperty(value = "用户账号", index = 1)
    private String userName;

    /**
     * 登录IP地址
     */
    @ExcelProperty(value = "登录IP地址", index = 2)
    private String ipaddr;

    /**
     * 登录地点
     */
    @ExcelProperty(value = "登录地点", index = 3)
    private String loginLocation;

    /**
     * 浏览器类型
     */
    @ExcelProperty(value = "浏览器类型", index = 4)
    private String browser;

    /**
     * 操作系统
     */
    @ExcelProperty(value = "操作系统", index = 5)
    private String os;

    /**
     * 登录状态（0成功 1失败）
     */
    @ExcelProperty(value = "登录状态", index = 6)
    private String status;

    /**
     * 提示消息
     */
    @ExcelProperty(value = "提示消息", index = 7)
    private String msg;

    /**
     * 访问时间
     */
    @ExcelProperty(value = "访问时间", index = 8)
    private LocalDateTime loginTime;


}
