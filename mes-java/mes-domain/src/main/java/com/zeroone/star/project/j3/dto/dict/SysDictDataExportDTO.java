package com.zeroone.star.project.j3.dto.dict;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @Author：xiong
 * @Date：2024/5/23 19:52
 */
@Data
@ApiModel("字典类型导出传输类")
public class SysDictDataExportDTO {

    @NotBlank(message = "字典名称不能为空")
    @ApiModelProperty(value = "字典名称", example = "sys_user_sex")
    private String dictType;

    @ApiModelProperty(value = "字典标签", example = "男")
    private String dictLabel;

    @ApiModelProperty(value = "状态(0正常 1停用)", example = "0")
    private String status;
}
