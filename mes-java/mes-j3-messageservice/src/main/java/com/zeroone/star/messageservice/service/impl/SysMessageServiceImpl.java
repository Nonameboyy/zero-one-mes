package com.zeroone.star.messageservice.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;

import cn.hutool.core.lang.UUID;
import com.zeroone.star.messageservice.entity.SysMessage;
import com.zeroone.star.messageservice.entity.User;
import com.zeroone.star.messageservice.mapper.SysMessageMapper;
import com.zeroone.star.messageservice.mapper.UserMapper;
import com.zeroone.star.messageservice.service.ISysMessageService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.dto.SysMessageDTO;
import com.zeroone.star.project.j3.query.MessageQuery;
import org.springframework.beans.BeanUtils;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.query.NewsPageQuery;
import com.zeroone.star.project.j3.vo.SysMessageVO;
import com.zeroone.star.project.j3.vo.UnreadMessageVO;
import org.springframework.beans.factory.annotation.Autowired;

import com.zeroone.star.messageservice.service.SessionService;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.j3.dto.LogoutDTO;
import com.zeroone.star.project.j3.dto.Session;
import com.zeroone.star.project.j3.dto.SystemNotificationDTO;
import com.zeroone.star.project.j3.vo.LoginResultVO;

import com.zeroone.star.project.j3.vo.LoginVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.apache.rocketmq.spring.core.RocketMQTemplate;

import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import javax.annotation.Resource;
import java.util.*;

import javax.annotation.Resource;
import java.time.Instant;
import java.util.Optional;

/**
 * <p>
 * 消息表 服务实现类
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
@Service
public class SysMessageServiceImpl extends ServiceImpl<SysMessageMapper, SysMessage> implements ISysMessageService {


    @Override
    public List<Long> removeMessages(List<Long> ids) {
        List<SysMessage> updatedList = baseMapper.selectList(new QueryWrapper<>()).stream().filter(message -> ids.contains(message.getMessageId())).map(message -> {
            SysMessage sysMessage = new SysMessage();
            BeanUtils.copyProperties(message, sysMessage);
            sysMessage.setDeletedFlag("Y");
            return sysMessage;
        }).collect(Collectors.toList());
        if(list() == null) return new ArrayList<>();
        List<Long> returnIds = new ArrayList<>();
        for(SysMessage message : updatedList){
            returnIds.add(baseMapper.update(message, new QueryWrapper<SysMessage>().eq("message_id", message.getMessageId())) > 0 ? message.getMessageId() : -1L);
        }
        return returnIds;
    }

    @Override
    public List<SysMessageDTO> queryMessage(MessageQuery query) {
        List<SysMessageDTO> sysMessages;
        if (query.getMessageId() != null){
            SysMessage sysMessage = baseMapper.selectById(query.getMessageId());
            SysMessageDTO sysMessageDTO = new SysMessageDTO();
            BeanUtils.copyProperties(sysMessage, sysMessageDTO);
            sysMessages = new ArrayList<>();
            sysMessages.add(sysMessageDTO);
        } else {
            QueryWrapper<SysMessage> wrapper = getSysMessageQueryWrapper(query);
            sysMessages = baseMapper.selectList(wrapper).stream().map(message -> {
                SysMessageDTO sysMessageDTO = new SysMessageDTO();
                BeanUtils.copyProperties(message, sysMessageDTO);
                return sysMessageDTO;
            }).collect(Collectors.toList());
        }
        return sysMessages;
    }

    private QueryWrapper<SysMessage> getSysMessageQueryWrapper(MessageQuery query) {
        QueryWrapper<SysMessage> wrapper = new QueryWrapper<>();
        if(query.getStatus() != null && !query.getStatus().isEmpty()) wrapper.eq("status", query.getStatus());
        if(query.getMessageType() != null && !query.getMessageType().isEmpty()) wrapper.like("message_type", query.getMessageType());
        if(query.getMessageLevel() != null && !query.getMessageLevel().isEmpty()) wrapper.like("message_level", query.getMessageLevel());
        if(query.getSenderNick() != null && !query.getSenderNick().isEmpty()) wrapper.like("sender_nick", query.getSenderNick());
        if(query.getRecipientNick() != null && !query.getRecipientNick().isEmpty()) wrapper.like("recipient_nick", query.getRecipientNick());
        return wrapper;
    }

    @Override
    public List<Long> modifyMessage(Long id) {
        SysMessage sysMessage = baseMapper.selectById(id);
        if(sysMessage == null){
            return new ArrayList<>();
        }
        if(sysMessage.getStatus().equals("已读")){
            sysMessage.setStatus("未读");
        } else{
            sysMessage.setStatus("已读");
        }
        baseMapper.updateById(sysMessage);
        List<Long> list = new ArrayList<>();
        list.add(id);
        return list;
    }
    @Autowired
    private SysMessageMapper sysMessageMapper;
//    @Resource
//    private SmsComponent smsComponent;

    /**
     * 获取消息通知列表（条件+分页）
     * @param newsPageQuery
     * @return
     */
    @Override
    public PageDTO<SysMessage> pageQuery(NewsPageQuery newsPageQuery) {
        // 消息类型
        String messageType = newsPageQuery.getMessageType();
        // 消息级别
        String messageLevel = newsPageQuery.getMessageLevel();
        // 发送人昵称
        String senderNick = newsPageQuery.getSenderNick();
        // 接收人昵称
        String receiverNick = newsPageQuery.getReceiverNick();
        // 状态
        String status = newsPageQuery.getStatus();
        // 当前页
        long pageIndex = newsPageQuery.getPageIndex();
        // 每页条数
        long pageSize = newsPageQuery.getPageSize();
        // 构造条件查询
        LambdaQueryWrapper<SysMessage> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        if (messageType != null) {
            lambdaQueryWrapper.eq(SysMessage::getMessageType, messageType);
        }
        if (messageLevel != null) {
            lambdaQueryWrapper.eq(SysMessage::getMessageLevel, messageLevel);
        }
        if (senderNick != null) {
            lambdaQueryWrapper.eq(SysMessage::getSenderNick, senderNick);
        }
        if (receiverNick != null) {
            lambdaQueryWrapper.eq(SysMessage::getRecipientNick, receiverNick);
        }
        if (status != null) {
            lambdaQueryWrapper.eq(SysMessage::getStatus, status);
        }
        // 开启分页查询
        Page<SysMessage> messagePage = sysMessageMapper.selectPage(new Page<>(pageIndex, pageSize), lambdaQueryWrapper);
        // 封装PageDTO对象
        PageDTO<SysMessage> pageDTO = new PageDTO<>();
        pageDTO.setPageIndex(messagePage.getCurrent());
        pageDTO.setPageSize(messagePage.getSize());
        pageDTO.setTotal(messagePage.getTotal());
        pageDTO.setPages(messagePage.getPages());
        pageDTO.setRows(messagePage.getRecords());
        return pageDTO;
    }

    /**
     * 获取最新未读消息列表 5条
     * @return
     */
    @Override
    public UnreadMessageVO getUnreadMessage() {
        // 构造查询条件
        LambdaQueryWrapper<SysMessage> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        lambdaQueryWrapper.eq(SysMessage::getStatus, "UNREAD");
        lambdaQueryWrapper.orderByDesc(SysMessage::getCreateTime);
        lambdaQueryWrapper.last("LIMIT 5");
        List<SysMessage> sysMessages = sysMessageMapper.selectList(lambdaQueryWrapper);
        // 封装结果
        List<SysMessageVO> list = new ArrayList<>();
        for (SysMessage sysMessage : sysMessages) {
            SysMessageVO sysMessageVO = new SysMessageVO();
            BeanUtils.copyProperties(sysMessage, sysMessageVO);
            list.add(sysMessageVO);
        }
        return UnreadMessageVO.builder()
                .unreadMessage(list)
                .build();
    }

//    @Value("${nacos.addr}")
//    private String nacosServerAddr;

    /**
     * 发送短信消息
     * @param smsQuery
     * @return
     */
//    @Override
//    public SmsResult sendSms(SmsQuery smsQuery) {
//        String phone = smsQuery.getPhone();
//        String code = smsQuery.getCode();
//        String mesType = smsQuery.getMesType();
//        NacosConfigUtil nacosConfigUtil = null;
//        try {
//            nacosConfigUtil = new NacosConfigUtil(nacosServerAddr);
//            String signName = nacosConfigUtil.getConfig(mesType + ".signName", "DEFAULT_GROUP", 5000);
//            String templateCode = nacosConfigUtil.getConfig(mesType + ".templateCode", "DEFAULT_GROUP", 5000);
//            Map<String, String> params = new HashMap<>();
//            params.put("code", code);
//            return smsComponent.sendSms(phone, signName, templateCode, params);
//        } catch (NacosException e) {
//            throw new RuntimeException(e);
//        }
//    }
    @Autowired
    private UserMapper userMapper;

    @Autowired
    private SessionService sessionService;

    @Resource
    private RocketMQTemplate rocketMQTemplate;

    private final String systemNoticeTopic = "system-notice-topic";

    @Override
    public LoginResultVO login(LoginDTO loginDTO) {
        LoginResultVO loginResultVO = new LoginResultVO();
        LoginVO loginVO = new LoginVO();
        // 获取info
        String username = loginDTO.getUsername();
        String password = loginDTO.getPassword(); // TODO 加密
        // 验证
        User user = userMapper.findByUsername(username);
        if (user != null && user.getPassword().equals(password)) {
            Session session = new Session();
            session.setId(UUID.randomUUID().toString());
            session.setUserId(user.getUserId());
            session.setLoginTime(Instant.ofEpochSecond(System.currentTimeMillis()));
            loginVO.setSession(session);
            loginVO.setId(user.getUserId());
            loginResultVO.setLoginVO(loginVO);
            loginResultVO.setResultStatus(ResultStatus.SUCCESS);
            sessionService.saveSession(session);
            return loginResultVO;
        }
        // 失败
        loginResultVO.setResultStatus(ResultStatus.FAIL);
        loginResultVO.setLoginVO(loginVO);
        return loginResultVO;
    }


    @Override
    public ResultStatus logout(LogoutDTO logoutDTO) {
        Optional<Session> session = sessionService.findSessionById(logoutDTO.getUserId());
        if (session == null) {
            return ResultStatus.UNAUTHORIZED;
        } else {
            sessionService.deleteSessionById(logoutDTO.getUserId());
            return ResultStatus.SUCCESS;
        }
    }

    @Override
    public ResultStatus sendNotice(SystemNotificationDTO systemNotificationDTO) {
        // 消息验证
        try {
            rocketMQTemplate.asyncSend(systemNoticeTopic, systemNotificationDTO, null, 30000);
            return ResultStatus.SUCCESS;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            return ResultStatus.FAIL;
        }
    }
}
