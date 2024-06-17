package com.zeroone.star.project.components.sms.aliyun;

import cn.hutool.json.JSONUtil;
import com.aliyun.dysmsapi20170525.Client;
import com.aliyun.dysmsapi20170525.models.*;
import com.aliyun.tea.TeaException;
import com.aliyun.teaopenapi.models.Config;
import com.aliyun.teautil.models.RuntimeOptions;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.util.List;
import java.util.Map;

/**
 * <p>
 * 描述：书写一个短信发送组件
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
public class SmsComponent {
    /**
     * 注入key
     */
    @Resource
    private KeyConfig key;

    /**
     * 使用AK&SK初始化账号Client
     * @return 返回客户端端对象
     */
    private Client createClient() throws Exception {
        Config config = new Config()
                // 必填，您的 AccessKey ID
                .setAccessKeyId(key.getAk())
                // 必填，您的 AccessKey Secret
                .setAccessKeySecret(key.getSk());
        // Endpoint 请参考 https://api.aliyun.com/product/Dysmsapi
        config.endpoint = "dysmsapi.aliyuncs.com";
        return new Client(config);
    }

    /**
     * 发送单条信息
     * @param phoneNumber    手机号码
     * @param signName       签名名称，如：阿里云短信测试
     * @param templateCode   短信模板CODE，如：SMS_15******
     * @param templateParams 模板参数值，key 参数名称 value 参数值
     * @return 发送结果
     */
    public SmsResult sendSms(String phoneNumber, String signName, String templateCode, Map<String, String> templateParams) {
        SendSmsRequest sendSmsRequest = new SendSmsRequest()
                .setPhoneNumbers(phoneNumber)
                .setSignName(signName)
                .setTemplateCode(templateCode)
                .setTemplateParam(JSONUtil.toJsonStr(templateParams));
        RuntimeOptions runtime = new RuntimeOptions();
        try {
            Client client = createClient();
            SendSmsResponse sendSmsResponse = client.sendSmsWithOptions(sendSmsRequest, runtime);
            SendSmsResponseBody body = sendSmsResponse.getBody();
            return SmsResult.builder()
                    .code(body.getCode())
                    .message(body.getMessage())
                    .bizId(body.getBizId())
                    .requestId(body.getRequestId())
                    .build();
        } catch (Exception e) {
            // 打印error
            e.printStackTrace();
            TeaException error = new TeaException(e.getMessage(), e);
            return SmsResult.builder()
                    .code(error.getCode())
                    .message(error.getMessage())
                    .build();
        }
    }

    /**
     * 批量发送短信，该接口单次最多支持100个号码。
     * @param phoneNumbers   接收短信的手机号码。
     * @param signNames      短信签名名称，短信签名的个数必须与手机号码的个数相同、内容一一对应。
     * @param templateCode   短信模板CODE。
     * @param templateParams 短信模板变量对应的实际值，模板变量值的个数必须与手机号码、签名的个数相同、内容一一对应，表示向指定手机号码中发对应签名的短信，且短信模板中的变量参数替换为对应的值。
     * @return 发送结果
     */
    public SmsResult sendSmsBatch(List<String> phoneNumbers, List<String> signNames, String templateCode, List<Map<String, String>> templateParams) {
        SendBatchSmsRequest sendBatchSmsRequest = new SendBatchSmsRequest()
                .setPhoneNumberJson(JSONUtil.toJsonStr(phoneNumbers))
                .setSignNameJson(JSONUtil.toJsonStr(signNames))
                .setTemplateCode(templateCode)
                .setTemplateParamJson(JSONUtil.toJsonStr(templateParams));
        RuntimeOptions runtime = new RuntimeOptions();
        try {
            Client client = createClient();
            SendBatchSmsResponse response = client.sendBatchSmsWithOptions(sendBatchSmsRequest, runtime);
            SendBatchSmsResponseBody body = response.getBody();
            return SmsResult.builder()
                    .code(body.getCode())
                    .message(body.getMessage())
                    .bizId(body.getBizId())
                    .requestId(body.getRequestId())
                    .build();
        } catch (Exception e) {
            e.printStackTrace();
            TeaException error = new TeaException(e.getMessage(), e);
            return SmsResult.builder()
                    .code(error.getCode())
                    .message(error.getMessage())
                    .build();
        }
    }
}
