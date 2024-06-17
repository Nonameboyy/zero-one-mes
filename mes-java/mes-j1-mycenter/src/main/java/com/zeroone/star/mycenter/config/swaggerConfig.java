package com.zeroone.star.mycenter.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * @author twelve
 * @version 1.0.0
 * @Description: TODO
 */
@Configuration
@EnableSwagger2WebMvc
public class swaggerConfig {

    @Bean
    Docket SysHomeApis() {
        return SwaggerCore.defaultDocketBuilder("个人中心模块","com.zeroone.star.mycenter.controller","mycenter");
}


}
