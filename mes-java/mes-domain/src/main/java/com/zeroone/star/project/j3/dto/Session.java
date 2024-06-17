package com.zeroone.star.project.j3.dto;

import lombok.Data;
import org.springframework.data.annotation.Id;
import org.springframework.data.redis.core.RedisHash;

import java.time.Instant;

@RedisHash("Session")
@Data
public class Session {
    @Id
    private String id;
    private Long userId;
    private Instant loginTime;
}
