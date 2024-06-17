package com.zeroone.star.project.j6.product_management.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("查询BOM相关数据模型")
public class BomQuery extends PageQuery {
    @ApiModelProperty(value = "物料/产品分类id", example = "507", required = true)
    private Long itemId;
}
