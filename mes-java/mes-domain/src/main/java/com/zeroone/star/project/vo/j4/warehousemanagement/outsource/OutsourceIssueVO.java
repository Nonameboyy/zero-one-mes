package com.zeroone.star.project.vo.j4.warehousemanagement.outsource;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * @Description
 * @Author diwu
 * @Date 2024/5/30
 */
@Data
@ApiModel("外协放料数据显示对象")
public class OutsourceIssueVO {

    /**
     * 领料单编号
     */
    @ApiModelProperty(value = "发料单编号",example = "OI202405300009")
    private String issueCode;

    /**
     * 领料单名称
     */
    @ApiModelProperty(value = "发料单名称",example = "东方卫视")
    private String issueName;

    /**
     * 生产工单编码
     */
    @ApiModelProperty(value = "生产工单编码也是外协工单编码",example = "MO202405290010")
    private String workorderCode;

    /**
     * 供应商名称
     */
    @ApiModelProperty(value = "供应商名称",example = "百度")
    private String vendorName;

    /**
     * 单据状态
     */
    @ApiModelProperty(value = "单据状态",example = "草稿或者已完成")
    private String status;
    /**
     * 领料日期
     */
    @ApiModelProperty(value = "领料日期",example = "2023-9-4")
    private LocalDateTime issueDate;
}
