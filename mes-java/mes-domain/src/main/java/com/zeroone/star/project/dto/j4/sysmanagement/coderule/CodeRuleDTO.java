package com.zeroone.star.project.dto.j4.sysmanagement.coderule;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;

/**
 * @version 1.0
 * @Description: 编码生成规则表数据传输对象
 * @Author: jm
 * @Date: 2024/5/19 14:38
 */
@Data
@ApiModel("编码规则的数据传输对象")
public class CodeRuleDTO {
    /**
     * 编码规则ID
     */
    @ApiModelProperty(value = "编码规则ID", example = "1")
    private Long ruleId;
    /**
     * 规则编码
     */
    @NotBlank(message = "规则编码不能为空")
    @ApiModelProperty(value = "规则编码", example = "ITEM_TYPE_CODE")
    private String ruleCode;

    /**
     * 规则名称
     */
    @NotBlank(message = "规则名称不能为空")
    @ApiModelProperty(value = "规则名称", example = "物料分类编码")
    private String ruleName;

    /**
     * 描述
     */
    @ApiModelProperty(value = "描述", example = "物料分类编码")
    private String ruleDesc;

    /**
     * 最大长度
     */
    @Min(value = 0, message = "maxLength不能小于0")
    @ApiModelProperty(value = "最大长度", example = "14")
    private Integer maxLength;

    /**
     * 是否补齐
     */
    @ApiModelProperty(value = "是否补齐", example = "N/Y")
    private String isPadded;

    /**
     * 是否启用
     */
    @ApiModelProperty(value = "是否启用", example = "N/Y")
    private String enableFlag;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "物料分类编码")
    private String remark;
}
