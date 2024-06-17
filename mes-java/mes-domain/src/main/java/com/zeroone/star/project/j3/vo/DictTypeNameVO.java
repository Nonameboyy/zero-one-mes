package com.zeroone.star.project.j3.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("获取字典类型名对象")
public class DictTypeNameVO {

    @ApiModelProperty(value = "字典名称", example = "用户性别")
    private String dictName;

}
