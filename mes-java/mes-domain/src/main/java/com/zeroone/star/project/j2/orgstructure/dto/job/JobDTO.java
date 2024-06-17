package com.zeroone.star.project.j2.orgstructure.dto.job;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

/**
 * @author 爱吃猫的鱼 Feng
 * @version 1.0.0
 * @Description:岗位相关DTO
 */
@Data
@ApiOperation("岗位传输数据对象")
public class JobDTO {
    @ApiModelProperty(value = "岗位Id",example = "1")
    Long postId;

    @ApiModelProperty(value = "岗位编码",example = "1")
    String postCode;

    @ApiModelProperty(value = "岗位名称",example = "CEO")
    String postName;

    @ApiModelProperty(value = "岗位排序",example = "1")
    Integer postSort;

    @ApiModelProperty(value = "状态",example = "1")
    String status;


    @ApiModelProperty(value = "备注",example = "1")
    String remark;
}
