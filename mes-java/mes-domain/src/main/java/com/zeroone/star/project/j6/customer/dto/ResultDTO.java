package com.zeroone.star.project.j6.customer.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：反馈客户导出、导入、下载结果数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 快乐小新
 * @version 1.0.0
 */
@Data
@ApiModel("返回导、导出、下载模板结果数据模型")
public class ResultDTO {
    @ApiModelProperty(value = "下载（0 失败，1 成功）",example = "1")
    private int status;
    @ApiModelProperty(value = "下载失败原因(如果成功返回null)",example = "null")
    private String reason;
}
