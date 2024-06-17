package com.zeroone.star.project.j1.syshome.dto.quality;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：质量统计查询模型
 * @author twelve
 * @version 1.0.0
 */
@Data
@ApiModel("质量统计查询对象")
public class QualityDTO {
    @ApiModelProperty(value = "缺陷描述",example = "外观缺陷")
    private String defectName;
    @ApiModelProperty(value = "缺陷数量",example = "856")
    private Integer defectQuantity;
}
