package com.zeroone.star.project.j2.sysmanagement.vo;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

/**
 * @author: Dding
 * @date: 2024/05/20
 **/
@Data
@ApiOperation("资源数据对象")
public class ResourceVO {
    //菜单ID
    @ApiModelProperty(value = "菜单ID",example = "1")
    private String menu_id;

    //菜单名称
    @ApiModelProperty(value = "菜单名称",example = "基础数据")
    private String menu_name;

    //父级ID
    @ApiModelProperty(value = "父级ID",example = "1")
    private Integer parent_id;

    //图标
    @ApiModelProperty(value = "图标",example = "0")
    private String icon;

    //排序
    @ApiModelProperty(value = "排序",example = "1")
    private Integer order_num;

    //权限标识
    @ApiModelProperty(value = "权限标识",example = "0")
    private String perms;

    //组件路径
    @ApiModelProperty(value = "组件路径",example = "ip")
    private String component;

    //状态
    @ApiModelProperty(value = "状态",example = "0")
    private String status;

    //创建时间
    @ApiModelProperty(value = "创建时间",example = "0")
    private DateTime create_time;


}
