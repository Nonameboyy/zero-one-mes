package com.zeroone.star.project.vo.j4.warehousemanagement.outsource;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
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
@ApiModel("外协放料单行表数据显示对象")
public class OutsourceIssueLineVO {
    /**
     * 行ID
     */
    @ApiModelProperty(value = "行id",example = "01")
    private Long lineId;

    /**
     * 领料单ID
     */
    @ApiModelProperty(value = "领料单Id",example = "01")
    private Long issueId;

    /**
     * 库存ID
     */
    @ApiModelProperty(value = "库存ID",example = "01")
    private Long materialStockId;

    /**
     * 产品物料ID
     */
    @ApiModelProperty(value = "产品物料id",example = "01")
    private Long itemId;

    /**
     * 产品物料编码
     */
    @ApiModelProperty(value = "产品物料编码",example = "DJDJJDJ")
    private String itemCode;

    /**
     * 产品物料名称
     */
    @ApiModelProperty(value = "产品物料名称",example = "螺丝刀刀头")
    private String itemName;

    /**
     * 规格型号
     */
    @ApiModelProperty(value = "规格型号",example = "15cm")
    private String specification;

    /**
     * 单位
     */
    @ApiModelProperty(value = "单位",example = "PCS")
    private String unitOfMeasure;

    /**
     * 领料数量
     */
    @ApiModelProperty(value = "领料数量",example = "01")
    private Double quantityIssued;

    /**
     * 领料批次号
     */
    @ApiModelProperty(value = "领料批次号",example = "01")
    private String batchCode;

    /**
     * 仓库ID
     */
    @ApiModelProperty(value = "仓库ID",example = "01")
    private Long warehouseId;

    /**
     * 仓库编码
     */
    @ApiModelProperty(value = "仓库编码",example = "01")
    private String warehouseCode;

    /**
     * 仓库名称
     */
    @ApiModelProperty(value = "仓库名称",example = "成品仓")
    private String warehouseName;

    /**
     * 库区ID
     */
    @ApiModelProperty(value = "库区id",example = "01")
    private Long locationId;

    /**
     * 库区编码
     */
    @ApiModelProperty(value = "库区编码",example = "defe")
    private String locationCode;

    /**
     * 库区名称
     */
    @ApiModelProperty(value = "库区名称",example = "半成品区")
    private String locationName;

    /**
     * 库位ID
     */
    @ApiModelProperty(value = "库位id",example = "34")
    private Long areaId;

    /**
     * 库位编码
     */
    @ApiModelProperty(value = "库位编码",example = "afeafea")
    private String areaCode;

    /**
     * 库位名称
     */
    @ApiModelProperty(value = "库位名称",example = "注塑半成品库位")
    private String areaName;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "发顺丰")
    private String remark;

}
