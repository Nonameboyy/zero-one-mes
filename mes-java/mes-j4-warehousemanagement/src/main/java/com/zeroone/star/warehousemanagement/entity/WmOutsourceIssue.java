package com.zeroone.star.warehousemanagement.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 外协领料单头表
 * </p>
 *
 * @author diwu
 * @since 2024-05-30
 */
@Getter
@Setter
@TableName("wm_outsource_issue")
public class WmOutsourceIssue implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 领料单ID
     */
    @TableId(value = "issue_id", type = IdType.AUTO)
    private Long issueId;

    /**
     * 领料单编号
     */
    private String issueCode;

    /**
     * 领料单名称
     */
    private String issueName;

    /**
     * 生产工单ID
     */
    private Long workorderId;

    /**
     * 生产工单编码
     */
    private String workorderCode;

    /**
     * 供应商ID
     */
    private Long vendorId;

    /**
     * 供应商编码
     */
    private String vendorCode;

    /**
     * 供应商名称
     */
    private String vendorName;

    /**
     * 供应商简称
     */
    private String vendorNick;

    /**
     * 仓库ID
     */
    private Long warehouseId;

    /**
     * 仓库编码
     */
    private String warehouseCode;

    /**
     * 仓库名称
     */
    private String warehouseName;

    /**
     * 库区ID
     */
    private Long locationId;

    /**
     * 库区编码
     */
    private String locationCode;

    /**
     * 库区名称
     */
    private String locationName;

    /**
     * 库位ID
     */
    private Long areaId;

    /**
     * 库位编码
     */
    private String areaCode;

    /**
     * 库位名称
     */
    private String areaName;

    /**
     * 领料日期
     */
    private LocalDateTime issueDate;

    /**
     * 单据状态
     */
    private String status;

    /**
     * 备注
     */
    private String remark;

    /**
     * 预留字段1
     */
    private String attr1;

    /**
     * 预留字段2
     */
    private String attr2;

    /**
     * 预留字段3
     */
    private Integer attr3;

    /**
     * 预留字段4
     */
    private Integer attr4;

    /**
     * 创建者
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 更新者
     */
    private String updateBy;

    /**
     * 更新时间
     */
    private LocalDateTime updateTime;


}
