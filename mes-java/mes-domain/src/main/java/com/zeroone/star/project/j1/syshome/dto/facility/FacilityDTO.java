package com.zeroone.star.project.j1.syshome.dto.facility;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：设备信息查询模型
 * @author twelve
 * @version 1.0.0
 */
@Data
@ApiModel("设备信息查询对象")
public class FacilityDTO {
    @ApiModelProperty(value = "设备总数",example = "100240")
    private long facilitySum;
    @ApiModelProperty(value = "运行数量",example = "1880")
    private long facilityRun;
    @ApiModelProperty(value = "待机数量",example = "18480")
    private long facilityWait;
    @ApiModelProperty(value = "故障数量",example = "19520")
    private long facilityStop;

}
