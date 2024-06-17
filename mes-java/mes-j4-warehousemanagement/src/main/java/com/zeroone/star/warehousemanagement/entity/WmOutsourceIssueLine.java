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
 * 外协领料单行表
 * </p>
 *
 * @author diwu
 * @since 2024-05-30
 */
@Getter
@Setter
@TableName("wm_outsource_issue_line")
public class WmOutsourceIssueLine implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 行ID
     */
    @TableId(value = "line_id", type = IdType.AUTO)
    private Long lineId;

    /**
     * 领料单ID
     */
    private Long issueId;

    /**
     * 库存ID
     */
    private Long materialStockId;

    /**
     * 产品物料ID
     */
    private Long itemId;

    /**
     * 产品物料编码
     */
    private String itemCode;

    /**
     * 产品物料名称
     */
    private String itemName;

    /**
     * 规格型号
     */
    private String specification;

    /**
     * 单位
     */
    private String unitOfMeasure;

    /**
     * 领料数量
     */
    private Double quantityIssued;

    /**
     * 领料批次号
     */
    private String batchCode;

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
