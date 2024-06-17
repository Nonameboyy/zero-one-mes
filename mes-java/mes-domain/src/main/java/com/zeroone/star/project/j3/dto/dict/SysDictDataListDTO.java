package com.zeroone.star.project.j3.dto.dict;

import com.alibaba.excel.annotation.ExcelIgnore;
import com.alibaba.excel.annotation.ExcelProperty;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * 字典数据传输类
 *
 * @Author：xiong
 * @Date：2024/5/19 14:01
 */


@Data
@ApiModel("字典数据传输列表类")
public class SysDictDataListDTO implements Serializable {

    @ExcelProperty("字典编号")
    @ApiModelProperty(value = "字典编号", example = "1")
    private Long dictCode;

    @ExcelProperty("字典排序")
    @ApiModelProperty(value = "字典排序", example = "1")
    private Integer dictSort;

    @ExcelProperty("字典标签")
    @ApiModelProperty(value = "字典标签", example = "男")
    private String dictLabel;

    @ExcelProperty("字典键值")
    @ApiModelProperty(value = "字典键值", example = "0")
    private String dictValue;

    @ExcelIgnore
    @ApiModelProperty(value = "样式属性（其他样式扩展）", example = "")
    private String cssClass;

    @ExcelIgnore
    @ApiModelProperty(value = "表格回显样式", example = "info")
    private String listClass;

    @ExcelProperty("状态")
    @ApiModelProperty(value = "状态（0正常 1停用）", example = "0")
    private String status;

    @ExcelProperty("创建时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建时间", example = "2022-04-07 00:29:32")
    private LocalDateTime createTime;

    @ExcelProperty("备注")
    @ApiModelProperty(value = "备注", example = "用户性别列表")
    private String remark;
}
