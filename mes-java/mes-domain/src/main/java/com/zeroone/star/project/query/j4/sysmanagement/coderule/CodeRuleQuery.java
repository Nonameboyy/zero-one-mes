package com.zeroone.star.project.query.j4.sysmanagement.coderule;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @version 1.0
 * @Description: 编码生成规则表的数据查询对象
 * @Author: jm
 * @Date: 2024/5/19 16:03
 */
@ApiModel("编码生成规则表的数据查询对象")
@Data
public class CodeRuleQuery extends PageQuery {
    /**
     * 规则名称
     */
    @ApiModelProperty(value = "规则名称", example = "物料分类编码")
    private String ruleName;
    /**
     * 规则编码
     */
    @ApiModelProperty(value = "规则编码", example = "ITEM_TYPE_CODE")
    private String ruleCode;
    /**
     * 是否启用
     */
    @ApiModelProperty(value = "是否启用", example = "N/Y")
    private String enableFlag;
}
