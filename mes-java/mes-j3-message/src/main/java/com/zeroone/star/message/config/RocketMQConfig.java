package com.zeroone.star.message.config;

import org.apache.rocketmq.spring.core.RocketMQTemplate;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Scope;

import javax.annotation.Resource;

@Configuration
public class RocketMQConfig {
    @Bean
    @Scope("singleton")
    public RocketMQTemplate rocketMQTemplate() {
        return new RocketMQTemplate();
    }
}
