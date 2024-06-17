package com.zeroone.star.productClassification.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket api() {
        return SwaggerCore.defaultDocketBuilder("物料分类模块",
                "com.zeroone.star.productClassification.controller",
                "productClassification");
    }
}
