package com.zeroone.star.project.j6.product_management.query;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data

@ApiModel(value = "MdItemQuery", description = "物料产品查询条件")
public class MdItemQuery {

    @ApiModelProperty(value = "产品物料编码")
    private String itemCode;

    @ApiModelProperty(value = "产品物料名称")
    private String itemName;

    @ApiModelProperty(value = "产品物料分类ID")
    private int itemTypeId;
}
