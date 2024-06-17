package com.zeroone.star.productClassification;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
@EnableDiscoveryClient
public class ProductClassificationApplication {

    public static void main(String[] args) {
        SpringApplication.run(ProductClassificationApplication.class, args);
    }

}
