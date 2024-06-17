package com.zeroone.star.mycenter.sms;

import lombok.Builder;
import lombok.Data;

/**
 * 描述：发送消息响应结果
 * @author 白河夜船
 * @version 1.0.0
 */
@Data
@Builder
public class SmsResult {
    /**
     * 请求状态码。
     * 返回OK代表请求成功。
     * 其他错误码，请参见<a href="https://help.aliyun.com/document_detail/101346.html">API错误码</a>。
     */
    private String code;
    /**
     * 状态码的描述。
     */
    private String message;
    /**
     * 发送回执ID。
     * 可根据发送回执ID在接口QuerySendDetails中查询具体的发送状态。
     */
    private String bizId;
    /**
     * 请求ID。
     */
    private String requestId;
}
