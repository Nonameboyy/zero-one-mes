package com.zeroone.star.project.j5.dto.shopsettings;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class AddShopSettingsDTO {


    @ApiModelProperty(value = "车间id", example = "1")
    private Long workshopId;;
    @ApiModelProperty(value = "车间编码", example = "WS001")
    private String workshopCode;
    @ApiModelProperty(value = "车间名称", example = "五金车间")
    private String workshopName;
    @ApiModelProperty(value = "面积", example = "0")
    private Double area;
    @ApiModelProperty(value = "负责人", example = "翔君")
    private String charge;
    @ApiModelProperty(value = "是否启用", example = "Y")
    private String enableFlag;
    @ApiModelProperty(value = "备注", example = "1")
    private String remark;
}
