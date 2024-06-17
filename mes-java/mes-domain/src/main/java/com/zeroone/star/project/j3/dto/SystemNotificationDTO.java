package com.zeroone.star.project.j3.dto;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.zeroone.star.project.j3.vo.NotificationType;
import com.zeroone.star.project.j3.vo.PriorityType;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.List;

@Data
@ApiModel("系统消息数据")
@JsonInclude(JsonInclude.Include.NON_NULL)
public class SystemNotificationDTO implements Serializable {

    /**
     * 通知ID
     */
    @ApiModelProperty(value = "通知ID", example = "1639767433576448")
    private long id;

    /**
     * 通知类型
     */
    @ApiModelProperty(value = "通知类型", example = "NotificationType.ENTERTAINMENT", required = false)
    private String type;

    /**
     * 通知优先级
     */
    @ApiModelProperty(value = "通知优先级", example = "NotificationType.ENTERTAINMENT", required = false)
    private String priority;


    /**
     * 通知标题
     */
    @ApiModelProperty(value = "通知标题", example = "涨薪通知", required = true)
    private String head;

    /**
     * 通知内容
     */
    @ApiModelProperty(value = "通知内容", example = "每人涨薪20%", required = true)
    private String content;

    /**
     * 收通知人
     */
    @ApiModelProperty(value = "收通知人", required = true)
    private List<Long> receivers;

}
