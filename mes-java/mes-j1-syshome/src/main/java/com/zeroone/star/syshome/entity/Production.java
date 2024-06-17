package com.zeroone.star.syshome.entity;


import com.baomidou.mybatisplus.annotation.TableName;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 生产进度数据实体类
 * </p>
 *
 */
@Getter
@Setter
@TableName("pro_task")
public class Production implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "订单编号",example = "ZL2050100240")
    private String workorderId;
    @ApiModelProperty(value = "客户编号",example = "C1880")
    private String clientCode;
    @ApiModelProperty(value = "产品编号",example = "P18480")
    private String itemCode;
    @ApiModelProperty(value = "机台",example = "1#注塑机")
    private String workstationName;
    @ApiModelProperty(value = "排产数量",example = "5000")
    private Double quantityProduced;
    @ApiModelProperty(value = "已生产进度",example = "0")
    private Double quantity;
    @ApiModelProperty(value = "交货日期",example = "2024-05-04 18:25")
    private Date endTime;
}
