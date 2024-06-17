package com.zeroone.star.project.query.j4.sysmanagement.logmanagement.OperationLog;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 操作日志查询对象
 * @version 1.0.0
 */
@Data
@ApiModel(value = "OperationLogQuery", description = "操作日志查询对象")
@AllArgsConstructor
@NoArgsConstructor
public class OperationLogQuery extends PageQuery {
    /**
     * 排序的方向desc或者asc
     */
    @ApiModelProperty(value = "排序的方向desc或者asc", example = "desc")
    private String isAsc;
    /**
     * 排序列
     */
    @ApiModelProperty(value = "排序列", example = "oper_time")
    private String orderByColumn;
    /**
     * 业务类型（0其它 1新增 2修改 3删除 4查询 5导出 6导入 7强退 8生成代码 9清空数据）
     */
    @ApiModelProperty(value = "业务类型（0其它 1新增 2修改 3删除 4查询 5导出 6导入 7强退 8生成代码 9清空数据）", example = "1")
    private String businessType;
    /**
     * 系统模块
     */
    @ApiModelProperty(value = "系统模块", example = "设备管理")
    private String title;
    /**
     * 操作状态（0正常 1异常）
     */
    @ApiModelProperty(value = "操作状态（0正常 1异常）", example = "0")
    private Integer status;

    /**
     * 操作人员
     */
    @ApiModelProperty(value = "操作人员", example = "admin")
    private String operName;
    /**
     * 开始时间
     */
    @ApiModelProperty(value = "开始时间", example = "2024-05-16")
    private String beginTime;
    /**
     * 结束时间
     */
    @ApiModelProperty(value = "结束时间", example = "2024-05-16")
    private String endTime;
}
