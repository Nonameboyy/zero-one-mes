package com.zeroone.star.project.j2.orgstructure.query.dept;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * @author 宵夜 夕秋z
 * @version 1.0.0
 * @Description: TODO
 */
@Data
@ApiOperation(value = "部门查询对象")
public class DepartmentQuery {

    //部门Id
    @ApiModelProperty(value = "部门Id",example = "1")
    private Integer deptId;

    //父部门id
    @ApiModelProperty(value = "父部门id",example = "2")
    private Integer parentId;

    //部门名称
    @ApiModelProperty(value = "部门名称",example = "部门1")
    private String deptName;

    //部门状态 0正常 1停用
    @ApiModelProperty(value = "部门状态",example = "1")
    private Integer status;

    //显示顺序
    @ApiModelProperty(value = "排序",example = "1")
    private Integer orderNum;

    //创建时间
    @ApiModelProperty(value = "创建时间",example = "2024-05-17")
    private LocalDateTime CreateTime;

    //更新时间
    @ApiModelProperty(value = "更新时间",example = "2024-05-17")
    private LocalDateTime UpdateTime;

}
