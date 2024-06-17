package com.zeroone.star.project.j5.query.shopsettings;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("车间管理查询对象")
public class ShopSettingsQuery extends PageQuery {
    @ApiModelProperty(value = "车间编码", example = "WS001")
    private String workshopCode;
    @ApiModelProperty(value = "车间名称", example = "五金车间")
    private String workshopName;
}
