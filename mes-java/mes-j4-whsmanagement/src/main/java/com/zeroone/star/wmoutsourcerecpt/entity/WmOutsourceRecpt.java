package com.zeroone.star.wmoutsourcerecpt.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.util.Date;

import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

/**
 * <p>
 * 外协入库单对象
 * </p>
 *
 * @author jingzi
 * @since 2024-05-27
 */
@Data
@TableName("wm_outsource_recpt")
public class WmOutsourceRecpt implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 入库单ID
     */
    @TableId(value = "recpt_id", type = IdType.AUTO)
    @ExcelProperty(value = "入库单ID", index = 0)
    private Long recptId;

    /**
     * 入库单编号
     */
    @ExcelProperty(value = "入库单编号", index = 1)
    private String recptCode;

    /**
     * 入库单名称
     */
    @ExcelProperty(value = "入库单名称", index = 2)
    private String recptName;

    /**
     * 来料检验单ID
     */
    @ExcelProperty(value = "来料检验单ID", index = 3)
    private Long iqcId;

    /**
     * 来料检验单编号
     */
    @ExcelProperty(value = "来料检验单编号", index = 4)
    private String iqcCode;

    /**
     * 外协工单ID
     */
    @ExcelProperty(value = "外协工单ID", index = 5)
    private Long workorderId;

    /**
     * 外协工单编号
     */
    @ExcelProperty(value = "外协工单编号", index = 6)
    private String workorderCode;

    /**
     * 供应商ID
     */
    @ExcelProperty(value = "供应商ID", index = 7)
    private Long vendorId;

    /**
     * 供应商编码
     */
    @ExcelProperty(value = "供应商编码", index = 8)
    private String vendorCode;

    /**
     * 供应商名称
     */
    @ExcelProperty(value = "供应商名称", index = 9)
    private String vendorName;

    /**
     * 供应商简称
     */
    @ExcelProperty(value = "供应商简称", index = 10)
    private String vendorNick;

    /**
     * 仓库ID
     */
    @ExcelProperty(value = "仓库ID", index = 11)
    private Long warehouseId;

    /**
     * 仓库编码
     */
    @ExcelProperty(value = "仓库编码", index = 12)
    private String warehouseCode;

    /**
     * 仓库名称
     */
    @ExcelProperty(value = "仓库名称", index = 13)
    private String warehouseName;

    /**
     * 库区ID
     */
    @ExcelProperty(value = "库区ID", index = 14)
    private Long locationId;

    /**
     * 库区编码
     */
    @ExcelProperty(value = "库区编码", index = 15)
    private String locationCode;

    /**
     * 库区名称
     */
    @ExcelProperty(value = "库区名称", index = 16)
    private String locationName;

    /**
     * 库位ID
     */
    @ExcelProperty(value = "库位ID", index = 17)
    private Long areaId;

    /**
     * 库位编码
     */
    @ExcelProperty(value = "库位编码", index = 18)
    private String areaCode;

    /**
     * 库位名称
     */
    @ExcelProperty(value = "库位名称", index = 19)
    private String areaName;

    /**
     * 入库日期
     */
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ExcelProperty(value = "入库日期", index = 20)
    private Date recptDate;

    /**
     * 单据状态
     */
    @ExcelProperty(value = "单据状态", index = 21)
    private String status;

    /**
     * 备注
     */
    @ExcelProperty(value = "备注", index = 22)
    private String remark;


    /**
     * 创建者
     */
    @ExcelProperty(value = "创建者", index = 23)
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ExcelProperty(value = "创建日期", index = 24)
    private Date createTime;

    /**
     * 更新者
     */
    @ExcelProperty(value = "更新者", index = 25)
    private String updateBy;

    /**
     * 更新时间
     */
    @TableField(fill = FieldFill.INSERT)
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ExcelProperty(value = "更新日期", index = 26)
    private Date updateTime;

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

}
