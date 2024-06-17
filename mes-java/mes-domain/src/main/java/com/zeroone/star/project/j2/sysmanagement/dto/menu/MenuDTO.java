package com.zeroone.star.project.j2.sysmanagement.dto.menu;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import java.util.Date;

/**
 * @author 熠 Di
 * @version 1.0.0
 * @Description: TODO
 */

@Data
@ApiOperation("系统管理数据对象")
public class MenuDTO {

    //菜单ID
    @ApiModelProperty(value = "菜单ID",example = "1")
    private String menu_id;


    //菜单名称
    @ApiModelProperty(value = "菜单名称",example = "部门管理")
    private String menu_name;

    //父菜单ID
    @ApiModelProperty(value = "父级ID",example = "1")
    private String parent_id;

    //显示顺序
    @ApiModelProperty(value = "显示顺序",example = "1")
    private Integer order_num;

    //路由地址
    @ApiModelProperty(value = "路由地址",example = "ip")
    private String path;

    //组件路径
    @ApiModelProperty(value = "组件路径",example = "ip")
    private String component;

    //路由参数
    @ApiModelProperty(value = "路由参数",example = "ip")
    private String query;

    //是否外链
    @ApiModelProperty(value = "是否外链",example = "0")
    private int is_frame;

    //是否缓存
    @ApiModelProperty(value = "是否缓存",example = "0")
    private int is_cache;

    //菜单类型
    @ApiModelProperty(value = "菜单类型",example = "目录")
    private String menu_type;

    //菜单状态
    @ApiModelProperty(value = "菜单状态",example = "0")
    private char visible;

    //菜单状态
    @ApiModelProperty(value = "菜单状态",example = "0")
    private String status;

    //权限标识
    @ApiModelProperty(value = "权限标识",example = "0")
    private String perms;

    //菜单图标
    @ApiModelProperty(value = "菜单图标",example = "0")
    private String icon;

    //创建着
    @ApiModelProperty(value = "创建人",example = "0")
    private String create_by;

    //创建时间
    @ApiModelProperty(value = "创建时间",example = "0")
    private Date create_time;

    //更新者
    @ApiModelProperty(value = "更新者人",example = "0")
    private String update_by;

    //更新时间
    @ApiModelProperty(value = "更新时间",example = "0")
    private Date update_time;

    //备注
    @ApiModelProperty(value = "备注",example = "0")
    private String remark;
}
