package com.zeroone.star.mycenter.component;

import cn.hutool.core.util.StrUtil;
import cn.hutool.json.JSONUtil;
import com.aliyun.dysmsapi20170525.Client;
import com.aliyun.dysmsapi20170525.models.*;
import com.aliyun.tea.TeaException;
import com.aliyun.teaopenapi.models.Config;
import com.aliyun.teautil.models.RuntimeOptions;


import com.zeroone.star.mycenter.sms.KeyConfig;


import com.zeroone.star.mycenter.sms.SmsResult;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

/**
 * 描述：书写一个短信发送组件
 * @author 白河夜船、
 * @version 1.0.0
 */
@Component
public class SmsComponent {
    /**
     * 注入key
     */
    @Resource
    private KeyConfig key;
    @Autowired
    private RedisTemplate redisTemplate;

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
     * 获取6位验证码
     * @return
     */
    public  String getVerifyCode(String phone) {
        Long codeL = System.nanoTime();
        String codeStr = Long.toString(codeL);
        String verifyCode = codeStr.substring(codeStr.length() - 6);
        //发送成功，将 code 保存至 Redis，失效时间 60s
        String key = "verify_code" + phone;
        redisTemplate.opsForValue().set(key, verifyCode, 60*5, TimeUnit.SECONDS);
        System.out.println("生成的6位验证码为:" + verifyCode);
        return verifyCode;
    }

    /**
     * 根据手机号查询是否已生成验证码
     *
     * @param phone
     * @return
     */
    private boolean checkCodeIsExpired(String phone) {
        String key = "verify_code" + phone;
        String code = (String) redisTemplate.opsForValue().get(key);
        return StrUtil.isBlank(code) ? true : false;
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

}
