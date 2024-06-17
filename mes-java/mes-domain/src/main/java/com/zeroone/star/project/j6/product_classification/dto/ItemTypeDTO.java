package com.zeroone.star.project.j6.product_classification.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel(value = "ItemTypeDTO", description = "物料产品分类数据传输对象")
public class ItemTypeDTO {
    @ApiModelProperty(value = "分类ID", required = false)
    private Long itemTypeId;

    @ApiModelProperty(value = "父分类ID", required = false)
    private Long parentTypeId;

    @ApiModelProperty(value = "分类编码", required = false)
    private String itemTypeCode;

    @ApiModelProperty(value = "分类名称", example = "原材料", required = true)
    private String itemTypeName;

    @ApiModelProperty(value = "祖先节点列表", required = false)
    private String ancestors;

    @ApiModelProperty(value = "产品物料标识", example = "PRODUCT", required = true)
    private String itemOrProduct;

    @ApiModelProperty(value = "排序号", example = "1", required = true)
    private Integer orderNum;

    @ApiModelProperty(value = "启用标识", example = "Y", required = true)
    private String enableFlag;

    @ApiModelProperty(value = "备注", required = false)
    private String remark;

    @ApiModelProperty(value = "创建者", required = false)
    private String createBy;

    @ApiModelProperty(value = "更新者", required = false)
    private String updateBy;
}
