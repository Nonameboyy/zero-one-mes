package com.zeroone.star.project.components.sms.aliyun;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

/**
 * <p>
 * 描述：阿里云相关秘钥和key配置数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
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
