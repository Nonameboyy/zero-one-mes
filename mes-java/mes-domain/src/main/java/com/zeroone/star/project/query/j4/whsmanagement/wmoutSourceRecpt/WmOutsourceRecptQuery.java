package com.zeroone.star.project.query.j4.whsmanagement.wmoutSourceRecpt;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.Date;

/**
 * @Author: jingzi
 * @createTime: 2024-05-27
 * @description: 外协入库查询条件对象
 */


@Data
@ApiModel("查询外协入库数据对象(条件+分页)")
public class WmOutsourceRecptQuery extends PageQuery {

    /**
     * 入库单编号
     */
    @ApiModelProperty(value = "入库单编号", example = "1")
    private String recptCode;

    /**
     * 外协工单编号
     */
    @ApiModelProperty(value = "外协工单编号", example = "1")
    private String workorderCode;


    /**
     * 供应商名称
     */
    @ApiModelProperty(value = "供应商名称", example = "乙方工厂")
    private String vendorName;


    /**
     * 入库日期
     */
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "入库日期", example = "2024-05-29")
    private Date recptDate;

}
