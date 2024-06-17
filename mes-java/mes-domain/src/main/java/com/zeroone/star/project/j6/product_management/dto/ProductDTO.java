package com.zeroone.star.project.j6.product_management.dto;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("添加/修改产品传输对象")
public class ProductDTO {

    @ApiModelProperty(value = "产品ID", example = "1")
    private Long itemId;

    @ApiModelProperty(value = "物料编码", example = "001")
    private String itemCode;

    @ApiModelProperty(value = "物料名称", example = "尼龙棒")
    private String itemName;

    @ApiModelProperty(value = "规格型号", example = "50mm")
    private String specification;

    @ApiModelProperty(value = "单位", example = "1")
    private String unitOfMeasure;

    @ApiModelProperty(value = "所属类型名称", example = "物料产品分类")
    private String itemTypeName;

    @ApiModelProperty(value = "是否启用", example = "是")
    private String enableFlag;

    @ApiModelProperty(value = "是否设置安全库存", example = "否")
    private String safeStockFlag;

    @ApiModelProperty(value = "创建时间",example = "2024-05-21 07:31:24")
    private LocalDateTime createTime;
}
