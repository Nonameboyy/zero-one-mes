package com.zeroone.star.project.j5.dto.shopsettings;

import com.zeroone.star.project.dto.ExtendPageDTO;
import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;
import java.util.List;

@Data
public class ShopSettingsDTO {

    @ApiModelProperty(value = "车间id", example = "1")
    private Long workshopId;
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
//    @ApiModelProperty(value = "预留字段1", example = "1")
//    private String attr1;
//    @ApiModelProperty(value = "预留字段2", example = "1")
//    private String attr2;
//    @ApiModelProperty(value = "预留字段3", example = "1")
//    private Integer attr3;
//    @ApiModelProperty(value = "预留字段4", example = "1")
//    private Integer attr4;
//    @ApiModelProperty(value = "创建者", example = "1")
//    private String create_by;
//    @ApiModelProperty(value = "创建时间", example = "2022-08-24 21：54：31")
//    private Date create_time;
//    @ApiModelProperty(value = "更新者", example = "1")
//    private String update_by;
//    @ApiModelProperty(value = "更新时间", example = "2022-08-24 21：54：31")
//    private Date update_time;
}

