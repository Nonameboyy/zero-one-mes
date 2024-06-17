package com.zeroone.star.project.j1.syshome.dto.repertory;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：库存统计查询模型
 * @author twelve
 * @version 1.0.0
 */
@Data
@ApiModel("库存统计查询对象")
public class RepertoryDTO {
    @ApiModelProperty(value = "产品名称",example = "衣柜")
    private String itemName;
    @ApiModelProperty(value = "在库数量",example = "886")
    private Integer quantityOnhand;
}
