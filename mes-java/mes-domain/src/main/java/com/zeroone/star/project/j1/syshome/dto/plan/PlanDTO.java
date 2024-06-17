package com.zeroone.star.project.j1.syshome.dto.plan;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：车间列表数据模型
 * @author 李兴昊
 * @version 1.0.0
 */
@Data
@ApiModel("排班情况数据模型")
public class PlanDTO {
    @ApiModelProperty(value = "用户id",example = "1")
    private Long userId;
    @ApiModelProperty(value = "用户名",example = "张三")
    private String userName;
    @ApiModelProperty(value = "班组名",example = "白班1组")
    private String teamName;
    @ApiModelProperty(value = "开始时间",example = "9:00")
    private String startTime;
    @ApiModelProperty(value = "结束时间",example = "12:00")
    private String endTime;
}
