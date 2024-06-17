package com.zeroone.star.project.j6.product_management.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：获取关联供应商列表（条件+分页）
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author smile
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("获取关联供应商列表（条件+分页）")
public class SupplierListQuery extends PageQuery {
    @ApiModelProperty(value = "供应商id", example = "1")
    private Long supplierId;
    @ApiModelProperty(value = "物料id", example = "1")
    private Long productId;
}
