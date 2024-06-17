package com.zeroone.star.wmoutsourcerecpt.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

import java.io.Serializable;
import java.util.Date;

import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

/**
 * <p>
 * 外协入库单行表
 * </p>
 *
 * @author jingzi
 * @since 2024-05-29
 */
@Data
@TableName("wm_outsource_recpt_line")
public class WmOutsourceRecptLine implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 行ID
     */
    @TableId(value = "line_id", type = IdType.AUTO)
    @ExcelProperty(value = "入库单行ID", index = 0)
    private Long lineId;

    /**
     * 入库单ID
     */
    @ExcelProperty(value = "入库单ID", index = 1)
    private Long recptId;

    /**
     * 产品物料ID
     */
    @ExcelProperty(value = "产品物料ID", index = 2)
    private Long itemId;

    /**
     * 产品物料编码
     */
    @ExcelProperty(value = "产品物料编码", index = 3)
    private String itemCode;

    /**
     * 产品物料名称
     */
    @ExcelProperty(value = "产品物料名称", index = 4)
    private String itemName;

    /**
     * 规格型号
     */
    @ExcelProperty(value = "规格型号", index = 5)
    private String specification;

    /**
     * 单位
     */
    @ExcelProperty(value = "单位", index = 6)
    private String unitOfMeasure;

    /**
     * 入库数量
     */
    @ExcelProperty(value = "入库数量", index = 7)
    private Double quantityRecived;

    /**
     * 入库批次号
     */
    @ExcelProperty(value = "入库批次号", index = 8)
    private String batchCode;

    /**
     * 仓库ID
     */
    @ExcelProperty(value = "仓库ID", index = 9)
    private Long warehouseId;

    /**
     * 仓库编码
     */
    @ExcelProperty(value = "仓库编码", index = 10)
    private String warehouseCode;

    /**
     * 仓库名称
     */
    @ExcelProperty(value = "仓库名称", index = 11)
    private String warehouseName;

    /**
     * 库区ID
     */
    @ExcelProperty(value = "库区ID", index = 12)
    private Long locationId;

    /**
     * 库区编码
     */
    @ExcelProperty(value = "库区编码", index = 13)
    private String locationCode;

    /**
     * 库区名称
     */
    @ExcelProperty(value = "库区名称", index = 14)
    private String locationName;

    /**
     * 库位ID
     */
    @ExcelProperty(value = "库位ID", index = 15)
    private Long areaId;

    /**
     * 库位编码
     */
    @ExcelProperty(value = "库位编码", index = 16)
    private String areaCode;

    /**
     * 库位名称
     */
    @ExcelProperty(value = "库位名称", index = 17)
    private String areaName;

    /**
     * 有效期
     */
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ExcelProperty(value = "有效期", index = 18)
    private Date expireDate;

    /**
     * 是否来料检验
     */
    @ExcelProperty(value = "是否来料检验", index = 19)
    private String iqcCheck;

    /**
     * 来料检验单ID
     */
    @ExcelProperty(value = "来料检验单ID", index = 20)
    private Long iqcId;

    /**
     * 来料检验单编号
     */
    @ExcelProperty(value = "来料检验单编号", index = 21)
    private String iqcCode;

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
    @ExcelProperty(value = "创建时间", index = 24)
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
    @ExcelProperty(value = "更新时间", index = 26)
    private Date updateTime;

    /**
     * 预留字段1
     */
    @ExcelProperty(value = "预留字段1", index = 27)
    private String attr1;

    /**
     * 预留字段2
     */
    @ExcelProperty(value = "预留字段2", index = 28)
    private String attr2;

    /**
     * 预留字段3
     */
    @ExcelProperty(value = "预留字段3", index = 29)
    private Integer attr3;

    /**
     * 预留字段4
     */
    @ExcelProperty(value = "预留字段4", index = 30)
    private Integer attr4;
}
