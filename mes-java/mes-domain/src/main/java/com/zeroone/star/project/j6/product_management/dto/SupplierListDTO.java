package com.zeroone.star.project.j6.product_management.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：添加关联供应商（支持多项添加）
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author smile
 * @version 1.0.0
 */
@Data
@ApiModel("添加关联供应商（支持多项添加）")
public class SupplierListDTO {
    @ApiModelProperty(value = "供应商ids", example = "[1, 2, 3]", required = true)
    private List<Long> supplierIds;
    @ApiModelProperty(value = "物料id", example = "1", required = true)
    private Long productId;
}
