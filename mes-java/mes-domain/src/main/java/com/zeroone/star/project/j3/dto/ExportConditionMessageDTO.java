package com.zeroone.star.project.j3.dto;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * ClassName:ExportConditionMessageDTO
 * Package:com.zeroone.star.project.j3.dto
 * Description:
 *      导出消息前筛选的字段
 * @Author Chi池
 * @Create 2024/5/23  17:52
 * @Version 1.0
 */

@Data
public class ExportConditionMessageDTO {

    /** 消息类型 */
    @ApiModelProperty(value = "消息类型",example = "公告")
    private String messageType;

    /** 消息级别 */
    @ApiModelProperty(value = "消息级别",example = "普通")
    private String messageLevel;

    /** 发送人昵称 */
    @ApiModelProperty(value = "发送人昵称",example = "")
    private String senderNick;

    /** 接收人昵称 */
    @ApiModelProperty(value = "接收人昵称",example = "")
    private String recipientNick;

    /** 状态 */
    @ApiModelProperty(value = "状态",example = "")
    private String status;


}
