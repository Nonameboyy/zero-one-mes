package com.zeroone.star.project.query.j4.sysmanagement.sysAutoCodePart;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @version 1.0
 * @Description: 编码生成规则组成表数据查询对象
 * @Author: jm
 * @Date: 2024/5/21 20:05
 */
@ApiModel("编码生成规则组成表的数据查询对象")
@Data
public class sysAutoCodePartQuery extends PageQuery {

    /**
     * 分段序号
     */

    @ApiModelProperty(value = "分段序号", example = "1")
    private Integer partIndex;

    /**
     * 分段名称
     */
    @ApiModelProperty(value = "分段名称", example = "前缀，流水号，流水号部分，年月日部分，固定前缀，年份，年月日等")
    private String partName;
}
