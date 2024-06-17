package com.zeroone.star.messageservice.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.Session;

import java.util.Optional;

public interface SessionService extends IService<Session> {
    void saveSession(Session session);

    Optional<Session> findSessionById(String id);

    boolean existsSessionById(String id);

    long countSessions();

    void deleteSessionById(String id);

    void deleteSession(Session session);

    void deleteAllSessions();
}
