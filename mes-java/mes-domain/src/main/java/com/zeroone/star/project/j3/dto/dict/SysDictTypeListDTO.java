package com.zeroone.star.project.j3.dto.dict;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * 字典类型传输类
 *
 * @Author：xiong
 * @Date：2024/5/19 14:01
 */

@Data
@ApiModel("字典类型传输列表类")
public class SysDictTypeListDTO implements Serializable {

    @ApiModelProperty(value = "字典主键（编号）", example = "1")
    private Long dictId;

    @ApiModelProperty(value = "字典名称", example = "用户性别")
    private String dictName;

    @ApiModelProperty(value = "字典类型", example = "sys_user_sex")
    private String dictType;

    @ApiModelProperty(value = "状态(0正常 1停用)", example = "0")
    private String status;

    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建时间", example = "2022-04-07 00:29:32")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "备注", example = "用户性别列表")
    private String remark;

}
