package com.zeroone.star.mycenter.sms;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

/**
* 描述：阿里云相关秘钥和key配置数据
* @author 白河夜船
* @version 1.0.0
*/
@Data
@Component
@ConfigurationProperties(prefix="aliyun.sms")
public class KeyConfig {
    /**
     * AccessKey
     */
    private String ak;
    /**
     * AccessKeySecret
     */
    private String sk;
}
