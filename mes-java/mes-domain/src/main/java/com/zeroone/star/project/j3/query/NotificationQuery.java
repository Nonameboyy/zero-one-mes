package com.zeroone.star.project.j3.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("通知状态查询")
public class NotificationQuery {
    /**
     * 通知ID
     */
    @ApiModelProperty(value = "通知ID", example = "1639767433576448", required = true)
    private long notificationId;

    /**
     * 处理人ID
     */
    @ApiModelProperty(value = "处理人ID", example = "1639767433576448", required = true)
    private Long receiverID;
}
