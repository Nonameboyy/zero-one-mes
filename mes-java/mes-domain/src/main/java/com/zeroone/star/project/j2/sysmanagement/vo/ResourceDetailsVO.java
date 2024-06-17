package com.zeroone.star.project.j2.sysmanagement.vo;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

/**
 * @author: Dding
 * @date: 2024/05/20
 **/
@Data
@ApiOperation("资源详情")
public class ResourceDetailsVO {

    //菜单ID
    @ApiModelProperty(value = "菜单ID",example = "1")
    private String menu_id;

    //资源名称
    @ApiModelProperty(value = "资源名称",example = "部门管理")
    private String menu_name;

    //父级ID
    @ApiModelProperty(value = "父级ID",example = "1")
    private Integer parent_id;

    //顺序
    @ApiModelProperty(value = "顺序",example = "1")
    private Integer order_num;

    //资源路径
    @ApiModelProperty(value = "资源路径",example = "ip")
    private String path;

    //是否外链
    @ApiModelProperty(value = "是否外链",example = "0")
    private Integer is_frame;

    //菜单类型
    @ApiModelProperty(value = "菜单类型",example = "目录")
    private String menu_type;

    //显示状态
    @ApiModelProperty(value = "visible",example = "0")
    private Integer visible;

    //菜单状态
    @ApiModelProperty(value = "菜单状态",example = "0")
    private String status;

    //图标
    @ApiModelProperty(value = "图标",example = "0")
    private String icon;

}
