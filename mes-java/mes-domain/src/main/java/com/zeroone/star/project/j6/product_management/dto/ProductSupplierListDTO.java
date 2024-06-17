package com.zeroone.star.project.j6.product_management.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：删除关联供应商（支持批量删除）
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author smile
 * @version 1.0.0
 */
@Data
@ApiModel("删除关联供应商（支持批量删除）")
public class ProductSupplierListDTO {
    @ApiModelProperty(value = "关联供应商ids", example = "[1, 2, 3]", required = true)
    private List<Long> productSupplierIds;
}
