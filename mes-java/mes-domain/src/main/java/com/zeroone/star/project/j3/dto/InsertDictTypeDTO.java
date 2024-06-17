package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("新增字典类型对象")
public class InsertDictTypeDTO {

    @ApiModelProperty(value = "字典名称", example = "用户性别")
    @NotBlank(message = "新增字典时, 字典名称不能为空")
    private String dictName;

    @ApiModelProperty(value = "字典类型", example = "sys_user_sex")
    @NotBlank(message = "新增字典时, 字典类型不能为空")
    private String dictType;

    @ApiModelProperty(value = "状态（0正常 1停用）", example = "0")
    @NotBlank(message = "新增字典时, 状态不能为空")
    @Pattern(regexp = "0|1", message = "状态只能是0或1")
    private String status;

    @ApiModelProperty(value = "备注", example = "此处写字典类型相关备注")
    private String remark;

}
