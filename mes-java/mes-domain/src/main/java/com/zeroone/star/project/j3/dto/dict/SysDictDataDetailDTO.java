package com.zeroone.star.project.j3.dto.dict;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * 字典数据传输类
 *
 * @Author：xiong
 * @Date：2024/5/19 14:01
 */

@Data
@ApiModel("字典数据传输类")
public class SysDictDataDetailDTO implements Serializable {

    @ApiModelProperty(value = "字典编号", example = "1")
    private Long dictCode;

    @ApiModelProperty(value = "字典排序", example = "1", required = true)
    private Integer dictSort;

    @ApiModelProperty(value = "字典标签", example = "男", required = true)
    private String dictLabel;

    @ApiModelProperty(value = "字典键值", example = "0", required = true)
    private String dictValue;

    @ApiModelProperty(value = "字典类型", example = "sys_user_sex")
    private String dictType;

    @ApiModelProperty(value = "样式属性（其他样式扩展）", example = "")
    private String cssClass;

    @ApiModelProperty(value = "表格回显样式", example = "info")
    private String listClass;

    @ApiModelProperty(value = "状态（0正常 1停用）", example = "0")
    private String status;

    @ApiModelProperty(value = "备注", example = "用户性别列表")
    private String remark;
}
