package com.zeroone.star.mycenter;

import io.github.bluemiaomiao.annotation.EnableFastdfsClient;
import io.github.bluemiaomiao.service.FastdfsClientService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.context.annotation.ComponentScan;

/**
 * <p>
 * 描述：服务器启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
public class MyCenterApplication {


    public static void main(String[] args) {
        SpringApplication.run(MyCenterApplication.class, args);
    }

}
