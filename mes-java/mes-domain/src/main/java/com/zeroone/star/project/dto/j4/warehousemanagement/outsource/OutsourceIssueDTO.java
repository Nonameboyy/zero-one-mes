package com.zeroone.star.project.dto.j4.warehousemanagement.outsource;

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
@ApiModel("外协放料基本信息传输数据对象")
public class OutsourceIssueDTO {

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
     * 生产工单ID
     */
    @ApiModelProperty(value = "生产工单编码也是外协工单ID",example = "233")
    private Long workorderId;

    /**
     * 生产工单编码
     */
    @ApiModelProperty(value = "生产工单编码也是外协工单编码",example = "MO202405290010")
    private String workorderCode;

    /**
     * 供应商ID
     */
    @ApiModelProperty(value = "供应商ID",example = "3232")
    private Long vendorId;

    /**
     * 供应商编码
     */
    @ApiModelProperty(value = "供应商编码",example = "MO202405290010")
    private String vendorCode;

    /**
     * 供应商名称
     */
    @ApiModelProperty(value = "供应商名称",example = "百度")
    private String vendorName;

    /**
     * 领料日期
     */
    @ApiModelProperty(value = "领料日期",example = "2023-9-4")
    private LocalDateTime issueDate;

    /**
     * 单据状态
     */
    @ApiModelProperty(value = "单据状态",example = "草稿或者已完成")
    private String status;

    /**
     * 备注
     */
    @ApiModelProperty(value = "单据备注",example = "很好，verygood")
    private String remark;

    /**
     * 创建者
     */
    @ApiModelProperty(value = "创建者",example = "第五")
    private String createBy;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间",example = "2024-7-7")
    private LocalDateTime createTime;

    /**
     * 更新者
     */
    @ApiModelProperty(value = "更新者",example = "阿伟")
    private String updateBy;

    /**
     * 更新时间
     */
    @ApiModelProperty(value = "更新时间",example = "2025-7-9")
    private LocalDateTime updateTime;

}
