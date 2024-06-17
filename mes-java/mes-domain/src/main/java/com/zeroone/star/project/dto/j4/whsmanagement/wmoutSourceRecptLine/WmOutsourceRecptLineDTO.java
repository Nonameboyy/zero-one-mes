package com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecptLine;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * @Author: jingzi
 * @createTime: 2024-05-30
 * @description: 外协入库单行基本传输对象
 */

@Data
@ApiModel("外协入库单行传输数据对象")
public class WmOutsourceRecptLineDTO {

    /**
     * 行ID
     */
    @ApiModelProperty(value = "入库单行ID", example = "1")
    private Long lineId;

    /**
     * 入库单ID
     */
    @ApiModelProperty(value = "入库单ID", example = "1")
    private Long recptId;

    /**
     * 产品物料ID
     */
    @ApiModelProperty(value = "产品物料ID", example = "1")
    private Long itemId;

    /**
     * 产品物料编码
     */
    @ApiModelProperty(value = "产品物料编码", example = "1")
    private String itemCode;

    /**
     * 产品物料名称
     */
    @ApiModelProperty(value = "产品物料名称", example = "测试名称")
    private String itemName;

    /**
     * 规格型号
     */
    @ApiModelProperty(value = "规格型号", example = "100000")
    private String specification;

    /**
     * 单位
     */
    @ApiModelProperty(value = "单位", example = "kg")
    private String unitOfMeasure;

    /**
     * 入库数量
     */
    @ApiModelProperty(value = "入库数量", example = "1000")
    private Double quantityRecived;

    /**
     * 入库批次号
     */
    @ApiModelProperty(value = "入库批次号", example = "1")
    private String batchCode;

    /**
     * 仓库ID
     */
    @ApiModelProperty(value = "仓库ID", example = "1")
    private Long warehouseId;

    /**
     * 仓库编码
     */
    @ApiModelProperty(value = "仓库编码", example = "1")
    private String warehouseCode;

    /**
     * 仓库名称
     */
    @ApiModelProperty(value = "仓库名称", example = "测试名称")
    private String warehouseName;

    /**
     * 库区ID
     */
    @ApiModelProperty(value = "库区ID", example = "1")
    private Long locationId;

    /**
     * 库区编码
     */
    @ApiModelProperty(value = "库区编码", example = "1")
    private String locationCode;

    /**
     * 库区名称
     */
    @ApiModelProperty(value = "库区名称", example = "测试名称")
    private String locationName;

    /**
     * 库位ID
     */
    @ApiModelProperty(value = "库位ID", example = "1")
    private Long areaId;

    /**
     * 库位编码
     */
    @ApiModelProperty(value = "库位编码", example = "1")
    private String areaCode;

    /**
     * 库位名称
     */
    @ApiModelProperty(value = "库位名称", example = "测试名称")
    private String areaName;

    /**
     * 有效期
     */
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "有效期", example = "2024-05-30")
    private Date expireDate;

    /**
     * 是否来料检验
     */
    @ApiModelProperty(value = "是否来料检验", example = "是")
    private String iqcCheck;

    /**
     * 来料检验单ID
     */
    @ApiModelProperty(value = "来料检验单ID", example = "1")
    private Long iqcId;

    /**
     * 来料检验单编号
     */
    @ApiModelProperty(value = "来料检验单编号", example = "1")
    private String iqcCode;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "备注")
    private String remark;

    /**
     * 创建者
     */
    @ApiModelProperty(value = "创建者", example = "admin")
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "创建时间", example = "2024-05-30")
    private Date createTime;

    /**
     * 更新者
     */
    @ApiModelProperty(value = "更新者", example = "admin")
    private String updateBy;

    /**
     * 更新时间
     */
    @TableField(fill = FieldFill.INSERT)
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "更新时间", example = "2024-05-30")
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
