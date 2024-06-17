package com.zeroone.star.project.dto.j4.warehousemanagement.rtsalse;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("仓储管理销售退货单数据传输对象")
public class RtSalsesDTO {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "退货单ID")
    private Long rtId;

    @ApiModelProperty(value = "退货单编号")
    private String rtCode;

    @ApiModelProperty(value = "退货单名称")
    private String rtName;

    @ApiModelProperty(value = "销售订单编号")
    private String soCode;

    @ApiModelProperty(value = "客户ID")
    private Long clientId;

    @ApiModelProperty(value = "客户编码")
    private String clientCode;

    @ApiModelProperty(value = "客户名称")
    private String clientName;

    @ApiModelProperty(value = "客户简称")
    private String clientNick;

    @ApiModelProperty(value = "仓库ID")
    private Long warehouseId;

    @ApiModelProperty(value = "仓库编码")
    private String warehouseCode;

    @ApiModelProperty(value = "仓库名称")
    private String warehouseName;

    @ApiModelProperty(value = "库区ID")
    private Long locationId;

    @ApiModelProperty(value = "库区编码")
    private String locationCode;

    @ApiModelProperty(value = "库区名称")
    private String locationName;

    @ApiModelProperty(value = "库位ID")
    private Long areaId;

    @ApiModelProperty(value = "库位编码")
    private String areaCode;

    @ApiModelProperty(value = "库位名称")
    private String areaName;

    @ApiModelProperty(value = "退货日期")
    private LocalDateTime rtDate;

    @ApiModelProperty(value = "退货原因")
    private String rtReason;

    @ApiModelProperty(value = "单据状态")
    private String status;

    @ApiModelProperty(value = "备注")
    private String remark;

    @ApiModelProperty(value = "预留字段1")
    private String attr1;

    @ApiModelProperty(value = "预留字段2")
    private String attr2;

    @ApiModelProperty(value = "预留字段3")
    private Integer attr3;

    @ApiModelProperty(value = "预留字段4")
    private Integer attr4;

    @ApiModelProperty(value = "创建者")
    private String createBy;

    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "更新者")
    private String updateBy;

    @ApiModelProperty(value = "更新时间")
    private LocalDateTime updateTime;
}
