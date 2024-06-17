package com.zeroone.star.syshome.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 设备信息数据实体类
 * </p>
 *
 * @author awei
 * @since 2024-05-10
 */
@Getter
@Setter
@TableName("dv_machinery")
public class Facility{
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "设备总数",example = "100240")
    private long facilitySum;
    @ApiModelProperty(value = "运行数量",example = "1880")
    private long facilityRun;
    @ApiModelProperty(value = "待机数量",example = "18480")
    private long facilityAwait;
    @ApiModelProperty(value = "故障数量",example = "19520")
    private long facilityFault;

}
