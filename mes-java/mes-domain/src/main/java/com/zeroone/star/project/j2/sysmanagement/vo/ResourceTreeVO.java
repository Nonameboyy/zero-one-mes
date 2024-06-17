package com.zeroone.star.project.j2.sysmanagement.vo;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

/**
 * @author: Dding
 * @date: 2024/05/25
 **/
@Data
@ApiOperation("资源树")
public class ResourceTreeVO {
    //菜单ID
    @ApiModelProperty(value = "菜单ID",example = "1")
    private String menu_id;

    //资源名称
    @ApiModelProperty(value = "资源名称",example = "部门管理")
    private String menu_name;

    //父级id
    @ApiModelProperty(value = "父级id",example = "1")
    private Integer parent_id;
}
