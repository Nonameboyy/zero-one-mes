package com.zeroone.star.project.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("删除产品（支持批量删除）")
public class ProductListDTO {
    @ApiModelProperty(value = "删除产品的ids", example = "1, 2, 3", required = true)
    private List<Long> productIds;
}