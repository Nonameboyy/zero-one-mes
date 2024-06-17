package com.zeroone.star.project.j2.orgstructure.query.job;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

/**
 * @author 爱吃猫的鱼 Feng
 * @version 1.0.0
 * @Description:岗位相关Query
 */
@Data
@ApiOperation("岗位查询对象")
public class JobQuery {
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

    @ApiModelProperty(value = "创建人",example = "1")
    String createBy;

    @ApiModelProperty(value = "创建时间",example = "2024-05-17")
    String createTime;

    @ApiModelProperty(value = "更新时间",example = "2024-05-17")
    String updateTime;

    @ApiModelProperty(value = "备注",example = "1")
    String remark;


    @ApiModelProperty(value = "当前页", example = "1")
    private Integer page;

    @ApiModelProperty(value = "每页数量", example = "10")
    private Integer size;
}

