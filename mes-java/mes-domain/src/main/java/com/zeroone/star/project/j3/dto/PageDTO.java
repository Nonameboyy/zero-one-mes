package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("分页结果")
public class PageDTO<T> {
    @ApiModelProperty(value = "总条数")
    Integer total;  
    @ApiModelProperty(value = "总页数")
    Integer pageSize;
    @ApiModelProperty(value = "集合")
    List<T> rows;
}
