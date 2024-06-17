package com.zeroone.star.project.j6.product_management.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("获取物料列表（条件+分页）")
public class ProductQuery extends PageQuery {
    @ApiModelProperty(value = "分类名称", example = "1")
    private String  classificationName;
    @ApiModelProperty(value = "物料编码", example = "1")
    private String  productCode;
    @ApiModelProperty(value = "物料名称", example = "1")
    private String  productName;
}
