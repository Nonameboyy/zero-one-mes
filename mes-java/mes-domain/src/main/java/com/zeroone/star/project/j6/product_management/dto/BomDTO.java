package com.zeroone.star.project.j6.product_management.dto;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：BOM相关数据模型（支持多项添加）
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author smile
 * @version 1.0.0
 */
@Data
@ApiModel("BOM相关数据模型")
public class BomDTO {
    @ApiModelProperty(value = "BOMid", example = "933", required = true)
    private Long bomId;
    @ApiModelProperty(value = "BOM物料id", example = "507", required = true)
    private Long bomItemId;
    @ApiModelProperty(value = "BOM物料编码", example = "dxy7", required = true)
    private String bomItemCode;
    @ApiModelProperty(value = "BOM物料名称", example = "螺母", required = true)
    private String bomItemName;
    @ApiModelProperty(value = "BOM物料规格", example = "M16", required = true)
    private String bomItemSpec;

    @ApiModelProperty(value = "创建人", example = "aaa", required = true)
    private String createBy;
    @ApiModelProperty(value = "创建时间", example = "2024-05-20 09:41:55", required = true)
    private String createTime;
    @ApiModelProperty(value = "是否使用", example = "Y", required = true)
    private String enableFlag;
    @ApiModelProperty(value = "物料/产品分类id", example = "507", required = true)
    private Long itemId;
    @ApiModelProperty(value = "项目或产品", example = "PRODUCT", required = true)
    private String itemOrProduct;
    @ApiModelProperty(value = "使用比例", example = "1.7", required = true)
    private Double quantity;
    @ApiModelProperty(value = "备注", example = "", required = false)
    private String remark;
    @ApiModelProperty(value = "单位", example = "pcs", required = true)
    private String unitOfMeasure;
    @ApiModelProperty(value = "更新人", example = "bbb", required = true)
    private String updateBy;
    @ApiModelProperty(value = "更新时间", example = "2024-05-21 07:31:24", required = true)
    private String updateTime;
}
