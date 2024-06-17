package com.zeroone.star.project.vo.j4.sysmanagement.logmanagement.OperationLog;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * 操作日志记录
 */
@ApiModel("操作日志列表")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class OperationLogVO extends PageDTO<OperationLogVO> {
    /** 日志主键 */
    @ApiModelProperty(value = "日志主键", example = "1")
    private Long operId;

    /** 操作模块 */
    @ApiModelProperty(value = "操作模块", example = "系统管理")
    private String title;

    /** 业务类型（0其它 1新增 2修改 3删除） */
    @ApiModelProperty(value = "业务类型（0其它 1新增 2修改 3删除）", example = "1")
    private Integer businessType;

    /** 业务类型数组 */
    @ApiModelProperty(value = "业务类型数组", example = "[1,2,3]")
    private Integer[] businessTypes;

    /** 请求方法 */
    @ApiModelProperty(value = "请求方法", example = "com.zeroone.star.project.controller.sysmanagement.logmanagement.OperationLogController.list()")
    private String method;

    /** 请求方式 */
    @ApiModelProperty(value = "请求方式", example = "GET")
    private String requestMethod;

    /** 操作类别（0其它 1后台用户 2手机端用户） */
    @ApiModelProperty(value = "操作类别（0其它 1后台用户 2手机端用户）", example = "1")
    private Integer operatorType;

    /** 操作人员 */
    @ApiModelProperty(value = "操作人员", example = "admin")
    private String operName;

    /** 部门名称 */
    @ApiModelProperty(value = "部门名称", example = "01星球")
    private String deptName;

    /** 请求url */
    @ApiModelProperty(value = "请求地址", example = "/sysmanagement/logmanagement/OperationLog/list")
    private String operUrl;

    /** 操作地址 */
    @ApiModelProperty(value = "操作地址", example = "127.0.0.1")
    private String operIp;

    /** 操作地点 */
    @ApiModelProperty(value = "操作地点", example = "中国")
    private String operLocation;

    /** 请求参数 */
    @ApiModelProperty(value = "请求参数", example = "{'page':1,'limit':10}")
    private String operParam;

    /** 返回参数 */
    @ApiModelProperty(value = "返回参数", example = "{'code':10000,'message':'提示消息内容','data':[]}")
    private String jsonResult;

    /** 操作状态（0正常 1异常） */
    @ApiModelProperty(value = "操作状态（0正常 1异常）", example = "0")
    private Integer status;

    /** 错误消息 */
    @ApiModelProperty(value = "错误消息", example = "操作成功")
    private String errorMsg;

    /** 操作时间 */
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "操作时间", example = "2024-05-20 00:00:00")
    private Date operTime;

}
