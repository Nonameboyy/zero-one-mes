package com.zeroone.star.project.j3.dto.dict;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * 字典类型传输类
 *
 * @Author：xiong
 * @Date：2024/5/19 14:01
 */

@Data
@ApiModel("字典类型传输类")
public class SysDictTypeDetailDTO implements Serializable {

    @ApiModelProperty(value = "字典名称", example = "用户性别", required = true)
    private String dictName;

    @ApiModelProperty(value = "字典类型", example = "sys_user_sex", required = true)
    private String dictType;

    @ApiModelProperty(value = "状态(0正常 1停用)", example = "0", required = true)
    private String status;


    @ApiModelProperty(value = "备注", example = "用户性别列表")
    private String remark;

}
