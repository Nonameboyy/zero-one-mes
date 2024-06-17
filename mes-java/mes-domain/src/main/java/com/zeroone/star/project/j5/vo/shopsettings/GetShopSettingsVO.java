package com.zeroone.star.project.j5.vo.shopsettings;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

@Data
@ApiModel("车间管理显示对象")
public class GetShopSettingsVO {
    @ApiModelProperty(value = "车间id", example = "1")
    private Long workshop_id;
    @ApiModelProperty(value = "车间编码", example = "WS001")
    private String workshop_code;
    @ApiModelProperty(value = "车间名称", example = "五金车间")
    private String workshop_name;
    @ApiModelProperty(value = "面积", example = "0")
    private Double area;
    @ApiModelProperty(value = "负责人", example = "翔君")
    private String charge;
    @ApiModelProperty(value = "是否启用", example = "Y")
    private String enable_flag;
    @ApiModelProperty(value = "备注", example = "1")
    private String remark;

}
