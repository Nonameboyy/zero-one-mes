package com.zeroone.star.sysmanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.transaction.annotation.EnableTransactionManagement;

/**
 * <p>
 * SysManagementApplication
 * @author j2
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
@EnableTransactionManagement
public class SysManagementApplication {

    public static void main(String[] args) {
        SpringApplication.run(SysManagementApplication.class, args);
    }

}
