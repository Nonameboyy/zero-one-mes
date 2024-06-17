package com.zeroone.star.project.j3.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @version v1.0
 * @author OldGj 2024/5/24
 * @apiNote 发送短信消息数据传输层
 */
@Data
@ApiModel
public class SmsQuery {

    @ApiModelProperty(value = "消息类型",example = "CAPTCHA")
    private String mesType;

    @ApiModelProperty(value = "接收人手机号",example = "15635417896")
    private String phone;

    @ApiModelProperty(value = "短信中的动态参数",example = "158785")
    private String code;
}
