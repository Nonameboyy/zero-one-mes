package com.zeroone.star.project.j2.sysmanagement.query.menu;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

/**
 * @author: Di
 * @date: 2024/05/20
 **/
@Data
@ApiOperation("菜单查询条件")
public class MenuConditionQuery {

    @ApiModelProperty(value = "菜单名称",example = "基础数据", notes = "支持模糊查询")
    private String menuName;

    @ApiModelProperty(value = "状态",example = "0", notes = "0表示停用, 1表示正常")
    private Integer status;
}
