package com.zeroone.star.project.j1.syshome.dto.workshop;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * 描述：车间列表数据模型
 * @author 李兴昊
 * @version 1.0.0
 */
@Data
@ApiModel("车间列表数据模型")
public class WorkshopDTO {
    @ApiModelProperty(value = "车间id",example = "1")
    private Long workshopId;
    @ApiModelProperty(value = "车间名称",example = "一汽")
    private String workshopName;
    @ApiModelProperty(value = "车间id",example = "10")
    private Long workstationId;
    @ApiModelProperty(value = "车间名称",example = "一汽")
    private String workstationName;
    @ApiModelProperty(value = "车间对应人数",example = "10")
    private Integer workstationTotalUsers;
}
