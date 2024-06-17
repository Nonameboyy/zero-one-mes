package com.zeroone.star.project.j3.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("字典类型对应的字典数据列表对象")
public class DictDataNameVO {

    @ApiModelProperty(value = "字典数据名称(标签)")
    private String dictLabel;

    @ApiModelProperty(value = "字典数据编码(唯一标识)")
    private Long dictCode;

}
