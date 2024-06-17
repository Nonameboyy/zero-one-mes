package com.zeroone.star.warehousemanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import java.time.LocalDateTime;
import java.io.Serializable;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.experimental.Accessors;

/**
 * <p>
 * 产品销售退货行表
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-29
 */
@Data
@EqualsAndHashCode(callSuper = false)
@Accessors(chain = true)
@TableName("wm_rt_salse_line")
@ApiModel(value="WmRtSalseLine对象", description="产品销售退货行表")
public class WmRtSalseLine implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "行ID")
    @TableId(value = "line_id", type = IdType.AUTO)
    private Long lineId;

    @ApiModelProperty(value = "退货单ID")
    private Long rtId;

    @ApiModelProperty(value = "产品物料ID")
    private Long itemId;

    @ApiModelProperty(value = "产品物料编码")
    private String itemCode;

    @ApiModelProperty(value = "产品物料名称")
    private String itemName;

    @ApiModelProperty(value = "规格型号")
    private String specification;

    @ApiModelProperty(value = "单位")
    private String unitOfMeasure;

    @ApiModelProperty(value = "退货数量")
    private Double quantityRted;

    @ApiModelProperty(value = "批次号")
    private String batchCode;

    @ApiModelProperty(value = "仓库ID")
    private Long warehouseId;

    @ApiModelProperty(value = "仓库编码")
    private String warehouseCode;

    @ApiModelProperty(value = "仓库名称")
    private String warehouseName;

    @ApiModelProperty(value = "库区ID")
    private Long locationId;

    @ApiModelProperty(value = "库区编码")
    private String locationCode;

    @ApiModelProperty(value = "库区名称")
    private String locationName;

    @ApiModelProperty(value = "库位ID")
    private Long areaId;

    @ApiModelProperty(value = "库位编码")
    private String areaCode;

    @ApiModelProperty(value = "库位名称")
    private String areaName;

    @ApiModelProperty(value = "有效期")
    private LocalDateTime expireDate;

    @ApiModelProperty(value = "备注")
    private String remark;

    @ApiModelProperty(value = "预留字段1")
    private String attr1;

    @ApiModelProperty(value = "预留字段2")
    private String attr2;

    @ApiModelProperty(value = "预留字段3")
    private Integer attr3;

    @ApiModelProperty(value = "预留字段4")
    private Integer attr4;

    @ApiModelProperty(value = "创建者")
    private String createBy;

    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "更新者")
    private String updateBy;

    @ApiModelProperty(value = "更新时间")
    private LocalDateTime updateTime;


}
