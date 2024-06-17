package com.zeroone.star.project.dto.j4.sysmanagement.logmanagement.OperationLog;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：操作日志添加数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @version 1.0.0
 */
@Data
@ApiModel("操作日志添加数据对象")
public class OperationLogDTO {
    @ApiModelProperty(value = "模块标题", example = "用户管理")
    private String title;

    @ApiModelProperty(value = "业务类型（0其它 1新增 2修改 3删除）", example = "1")
    private Integer businessType;

    @ApiModelProperty(value = "方法名称", example = "createUser")
    private String method;

    @ApiModelProperty(value = "请求方式", example = "POST")
    private String requestMethod;

    @ApiModelProperty(value = "操作类别（0其它 1后台用户 2手机端用户）", example = "1")
    private Integer operatorType;

    @ApiModelProperty(value = "操作人员", example = "张三")
    private String operName;

    @ApiModelProperty(value = "部门名称", example = "研发部")
    private String deptName;

    @ApiModelProperty(value = "请求URL", example = "/api/user/create")
    private String operUrl;

    @ApiModelProperty(value = "主机地址", example = "192.168.0.1")
    private String operIp;

    @ApiModelProperty(value = "操作地点", example = "01星球总部")
    private String operLocation;

    @ApiModelProperty(value = "请求参数", example = "{ \"username\": \"张三\" }")
    private String operParam;

    @ApiModelProperty(value = "返回参数", example = "{ \"success\": true }")
    private String jsonResult;

    @ApiModelProperty(value = "操作状态（0正常 1异常）", example = "0")
    private Integer status;

    @ApiModelProperty(value = "错误消息", example = "无")
    private String errorMsg;

    @ApiModelProperty(value = "操作时间", example = "2023-05-19T14:35:04")
    private LocalDateTime operTime;
}
