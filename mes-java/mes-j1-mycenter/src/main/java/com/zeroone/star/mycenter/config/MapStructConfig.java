package com.zeroone.star.mycenter.config;

import com.zeroone.star.mycenter.mapper.MapStructMyCenterMapper;
import org.mapstruct.factory.Mappers;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class MapStructConfig {

    @Bean
    public MapStructMyCenterMapper mapStructMyCenterMapper() {
        return Mappers.getMapper(MapStructMyCenterMapper.class);
    }
}
