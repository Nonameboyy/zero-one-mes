package com.zeroone.star.project.j6.product_management.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
/**
 * <p>
 * 描述：产品SOP传输数据对象
 * </p>
 * @version 1.0.0
 */
@Data
@ApiModel("产品SOP传输数据对象")
public class ProductSopDTO {
    @ApiModelProperty(value = "记录id", example = "288")
    private Long sopId;
    @ApiModelProperty(value = "物料产品id", example = "288")
    private Long itemId;
    @ApiModelProperty(value = "标题", example = "装配SOP")
    private String sopTitle;
    @ApiModelProperty(value = "排列顺序", example = "1")
    private Integer orderNum;
    @ApiModelProperty(value = "详细描述", example = "详细的装配步骤描述")
    private String sopDescription;
    @ApiModelProperty(value = "对应的工序ID", example = "2001")
    private Long processId;
    @ApiModelProperty(value = "图片地址", example = "http://example.com/sop.jpg")
    private String sopUrl;


}