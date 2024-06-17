package com.zeroone.star.project.j1.syshome.dto.toDoEvent;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 描述：我的待办数据模型
 * @author 李兴昊
 * @version 1.0.0
 */
@Data
@ApiModel("我的待办数据模型")
public class ToDoEventDTO {
    @ApiModelProperty(value = "待办类型",example = "dv_repair")
    private String eventType;
    @ApiModelProperty(value = "代办类型名称",example = "维修工单")
    private String eventTypeName;
    @ApiModelProperty(value = "唯一标识",example = "123")
    private Long id;
    @ApiModelProperty(value = "标题",example = "机器1变压器损坏待维修")
    private String title;
    @ApiModelProperty(value = "备注(额外说明)",example = "发动机损坏")
    private String remark;
    @ApiModelProperty(value = "待办事件开始日期时间",example = "2021.09.03 11:44:15")
    private LocalDateTime eventDatatime;
}
