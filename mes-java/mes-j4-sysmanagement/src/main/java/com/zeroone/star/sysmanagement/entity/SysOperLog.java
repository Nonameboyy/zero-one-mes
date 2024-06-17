package com.zeroone.star.sysmanagement.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 操作日志记录
 * </p>
 *
 * @since 2024-05-19
 */
@Data
@TableName("sys_oper_log")
public class SysOperLog implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 日志主键
     */
    @TableId(value = "oper_id", type = IdType.AUTO)
    @ExcelProperty(value = "操作序号", index = 0)
    private Long operId;

    /**
     * 模块标题
     */
    @ExcelProperty(value = "操作模块", index = 1)
    private String title;

    /**
     * 业务类型（0其它 1新增 2修改 3删除）
     */
    @ExcelProperty(value = "业务类型", index = 2)
    private Integer businessType;

    /**
     * 方法名称
     */
    @ExcelProperty(value = "请求方法", index = 3)
    private String method;

    /**
     * 请求方式
     */
    @ExcelProperty(value = "方法名称", index = 4)
    private String requestMethod;

    /**
     * 操作类别（0其它 1后台用户 2手机端用户）
     */
    @ExcelProperty(value = "操作类别", index = 5)
    private Integer operatorType;

    /**
     * 操作人员
     */
    @ExcelProperty(value = "操作人员", index = 6)
    private String operName;

    /**
     * 部门名称
     */
    @ExcelProperty(value = "部门名称", index = 7)
    private String deptName;

    /**
     * 请求URL
     */
    @ExcelProperty(value = "请求地址", index = 8)
    private String operUrl;

    /**
     * 主机地址
     */
    @ExcelProperty(value = "操作地址", index = 9)
    private String operIp;

    /**
     * 操作地点
     */
    @ExcelProperty(value = "操作地点", index = 10)
    private String operLocation;

    /**
     * 请求参数
     */
    @ExcelProperty(value = "请求参数", index = 11)
    private String operParam;

    /**
     * 返回参数
     */
    @ExcelProperty(value = "返回参数", index = 12)
    private String jsonResult;

    /**
     * 操作状态（0正常 1异常）
     */
    @ExcelProperty(value = "状态", index = 13)
    private Integer status;

    /**
     * 错误消息
     */
    @ExcelProperty(value = "错误消息", index = 14)
    private String errorMsg;

    /**
     * 操作时间
     */
    @ExcelProperty(value = "操作时间", index = 15)
    private LocalDateTime operTime;
}
