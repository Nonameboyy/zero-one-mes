package com.zeroone.star.project.j6.product_classification.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel(value = "ItemTypeQuery", description = "物料产品分类查询条件")
public class ItemTypeQuery {
    @ApiModelProperty(value = "分类ID", required = false)
    private Long itemTypeId;

    @ApiModelProperty(value = "父分类ID", required = false)
    private Long parentTypeId;

    @ApiModelProperty(value = "分类编码", required = false)
    private String itemTypeCode;

    @ApiModelProperty(value = "分类名称", example = "原材料", required = true)
    private String itemTypeName;

    @ApiModelProperty(value = "启用标识", example = "Y", required = true)
    private String enableFlag;

    @ApiModelProperty(value = "产品物料标识", required = false)
    private String itemOrProduct;

}
