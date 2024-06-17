package com.zeroone.star.project.j6.product_management.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：产品SOP查询对象
 * </p>
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("产品SOP查询对象")
public class ProductSopQuery extends PageQuery {
    @ApiModelProperty(value = "物料产品id", example = "288")
    private Long itemId;
}
