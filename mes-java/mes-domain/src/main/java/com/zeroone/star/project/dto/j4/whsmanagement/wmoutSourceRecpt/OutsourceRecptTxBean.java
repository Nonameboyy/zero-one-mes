package com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.util.Date;

/**
 * @Author: jingzi
 * @createTime: 2024-05-30
 * @description: 外协入库物料传输数据对象
 */

@Data
@ApiModel("外协入库物料传输数据对象")
public class OutsourceRecptTxBean {

    private static final long serialVersionUID = 1L;

    /**
     * 产品物料ID
     */
    @ApiModelProperty(value = "产品物料ID")
    private Long itemId;

    /**
     * 产品物料编码
     */
    @ApiModelProperty(value = "产品物料编码")
    private String itemCode;

    /**
     * 产品物料名称
     */
    @ApiModelProperty(value = "产品物料名称")
    private String itemName;

    /**
     * 规格型号
     */
    @ApiModelProperty(value = "规格型号")
    private String specification;

    /**
     * 单位
     */
    @ApiModelProperty(value = "单位")
    private String unitOfMeasure;

    /**
     * 入库批次号
     */
    @ApiModelProperty(value = "入库批次号")
    private String batchCode;

    /**
     * 仓库ID
     */
    @ApiModelProperty(value = "仓库ID")
    private Long warehouseId;

    /**
     * 仓库编码
     */
    @ApiModelProperty(value = "仓库编码")
    private String warehouseCode;

    /**
     * 仓库名称
     */
    @ApiModelProperty(value = "仓库名称")
    private String warehouseName;

    /**
     * 库区ID
     */
    @ApiModelProperty(value = "库区ID")
    private Long locationId;

    /**
     * 库区编码
     */
    @ApiModelProperty(value = "库区编码")
    private String locationCode;

    /**
     * 库区名称
     */
    @ApiModelProperty(value = "库区名称")
    private String locationName;

    /**
     * 库位ID
     */
    @ApiModelProperty(value = "库位ID")
    private Long areaId;

    /**
     * 库位编码
     */
    @ApiModelProperty(value = "库位编码")
    private String areaCode;

    /**
     * 库位名称
     */
    @ApiModelProperty(value = "库位名称")
    private String areaName;

    /**
     * 供应商ID
     */
    @ApiModelProperty(value = "供应商ID")
    private Long vendorId;

    /**
     * 供应商编号
     */
    @ApiModelProperty(value = "供应商编号")
    private String vendorCode;

    /**
     * 供应商名称
     */
    @ApiModelProperty(value = "供应商名称")
    private String vendorName;

    /**
     * 供应商简称
     */
    @ApiModelProperty(value = "供应商简称")
    private String vendorNick;

    /**
     * 单据类型
     */
    @ApiModelProperty(value = "单据类型")
    private String sourceDocType;

    /**
     * 单据ID
     */
    @ApiModelProperty(value = "单据ID")
    private Long sourceDocId;

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号")
    private String sourceDocCode;

    /**
     * 单据行ID
     */
    @ApiModelProperty(value = "单据行ID")
    private Long sourceDocLineId;

    /**
     * 事务数量
     */
    @ApiModelProperty(value = "事务数量")
    private BigDecimal transactionQuantity;

    /**
     * 入库日期
     */
    @ApiModelProperty(value = "入库日期")
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date recptDate;

    /**
     * 库存有效期
     */
    @ApiModelProperty(value = "库存有效期")
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date expireDate;

}
