package com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt;

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
 * @createTime: 2024-05-27
 * @description: 外协入库基本传输对象
 */

@Data
@ApiModel("外协入库传输数据对象")
public class WmOutsourceRecptDTO {
    /**
     * 入库单ID
     */
    @ApiModelProperty(value = "入库单ID", example = "1")
    private Long recptId;

    /**
     * 入库单编号
     */
    @ApiModelProperty(value = "入库单编号", example = "1")
    private String recptCode;

    /**
     * 入库单名称
     */
    @ApiModelProperty(value = "入库单名称", example = "外协入库单")
    private String recptName;

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
     * 外协工单ID
     */
    @ApiModelProperty(value = "外协工单ID", example = "1")
    private Long workorderId;

    /**
     * 外协工单编号
     */
    @ApiModelProperty(value = "外协工单编号", example = "1")
    private String workorderCode;

    /**
     * 供应商ID
     */
    @ApiModelProperty(value = "供应商ID", example = "1")
    private Long vendorId;

    /**
     * 供应商编码
     */
    @ApiModelProperty(value = "供应商编码", example = "1")
    private String vendorCode;

    /**
     * 供应商名称
     */
    @ApiModelProperty(value = "供应商名称", example = "乙方工厂")
    private String vendorName;

    /**
     * 供应商简称
     */
    @ApiModelProperty(value = "供应商简称", example = "乙方")
    private String vendorNick;

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
    @ApiModelProperty(value = "仓库名称", example = "测试仓库")
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
    @ApiModelProperty(value = "库区名称", example = "测试库区")
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
    @ApiModelProperty(value = "库位名称", example = "测试库位")
    private String areaName;

    /**
     * 入库日期
     */
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "入库日期", example = "2024-05-29")
    private Date recptDate;

    /**
     * 单据状态
     */
    @ApiModelProperty(value = "单据状态", example = "PREPARE")
    private String status;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "测试备注")
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
    @ApiModelProperty(value = "创建日期", example = "2024-05-29")
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
    @ApiModelProperty(value = "更新日期", example = "2024-05-29")
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
