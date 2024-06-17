package com.zeroone.star.messageservice;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
@EnableDiscoveryClient
public class MessageserviceApplication {

    public static void main(String[] args) {
        SpringApplication.run(MessageserviceApplication.class, args);
    }

}
