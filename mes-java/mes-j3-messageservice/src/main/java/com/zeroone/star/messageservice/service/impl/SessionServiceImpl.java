package com.zeroone.star.messageservice.service.impl;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j3.dto.Session;
import com.zeroone.star.messageservice.service.SessionService;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.Duration;
import java.util.Collection;
import java.util.Map;
import java.util.Optional;
import java.util.function.Function;

@Service
public class SessionServiceImpl implements SessionService {

    @Resource
    private RedisTemplate<String, Session> redisTemplate;

    private static final String SESSION_KEY = "Session";

    @Override
    public void saveSession(Session session) {
        try {
            redisTemplate.opsForHash().put(SESSION_KEY, session.getUserId(), session);
            redisTemplate.expire(SESSION_KEY, Duration.ofHours(2));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public Optional<Session> findSessionById(String id) {
        return Optional.ofNullable((Session) redisTemplate.opsForHash().get(SESSION_KEY, id));
    }

    @Override
    public boolean existsSessionById(String id) {
        return redisTemplate.opsForHash().hasKey(SESSION_KEY, id);
    }

    @Override
    public long countSessions() {
        return redisTemplate.opsForHash().size(SESSION_KEY);
    }

    @Override
    public void deleteSessionById(String id) {
        redisTemplate.opsForHash().delete(SESSION_KEY, id);
    }

    @Override
    public void deleteSession(Session session) {
        redisTemplate.opsForHash().delete(SESSION_KEY, session.getId());
    }

    @Override
    public void deleteAllSessions() {
        redisTemplate.delete(SESSION_KEY);
    }

    @Override
    public boolean saveBatch(Collection<Session> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdateBatch(Collection<Session> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean updateBatchById(Collection<Session> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdate(Session entity) {
        return false;
    }

    @Override
    public Session getOne(Wrapper<Session> queryWrapper, boolean throwEx) {
        return null;
    }

    @Override
    public Map<String, Object> getMap(Wrapper<Session> queryWrapper) {
        return null;
    }

    @Override
    public <V> V getObj(Wrapper<Session> queryWrapper, Function<? super Object, V> mapper) {
        return null;
    }

    @Override
    public BaseMapper<Session> getBaseMapper() {
        return null;
    }

    @Override
    public Class<Session> getEntityClass() {
        return null;
    }
}