package com.zeroone.star.project.vo;



import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author feng
 * @version 1.0.0
 * @Description: 岗位视图对象
 */

@Data
public class JobVO {

    @ApiModelProperty(value = "岗位Id", example = "1")
    private Long postId;

    @ApiModelProperty(value = "岗位编码", example = "1")
    private String postCode;

    @ApiModelProperty(value = "岗位名称", example = "CEO")
    private String postName;

    @ApiModelProperty(value = "岗位排序", example = "1")
    private Integer postSort;

    @ApiModelProperty(value = "状态", example = "1")
    private String status;

    @ApiModelProperty(value = "创建人", example = "1")
    private String createBy;

    @ApiModelProperty(value = "创建时间", example = "2024-05-17")
    private String createTime;

    @ApiModelProperty(value = "更新时间", example = "2024-05-17")
    private String updateTime;

    @ApiModelProperty(value = "备注", example = "1")
    private String remark;
}