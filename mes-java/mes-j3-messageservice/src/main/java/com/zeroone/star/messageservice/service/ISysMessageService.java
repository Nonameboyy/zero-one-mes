package com.zeroone.star.messageservice.service;

import com.zeroone.star.messageservice.entity.SysMessage;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.SysMessageDTO;
import com.zeroone.star.project.j3.query.MessageQuery;

import java.util.List;
import com.zeroone.star.project.components.sms.aliyun.SmsResult;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.query.NewsPageQuery;
import com.zeroone.star.project.j3.query.SmsQuery;
import com.zeroone.star.project.j3.vo.UnreadMessageVO;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.j3.dto.LogoutDTO;
import com.zeroone.star.project.j3.dto.SystemNotificationDTO;
import com.zeroone.star.project.j3.vo.LoginResultVO;
import com.zeroone.star.project.vo.ResultStatus;

/**
 * <p>
 * 消息表 服务类
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
public interface ISysMessageService extends IService<SysMessage> {
    LoginResultVO login(LoginDTO loginDTO);

    ResultStatus logout(LogoutDTO logoutDTO);

    ResultStatus sendNotice(SystemNotificationDTO systemNotificationDTO);


    List<Long> removeMessages(List<Long> ids);

    List<SysMessageDTO> queryMessage(MessageQuery query);

    List<Long> modifyMessage(Long id);
    /**
     * 获取消息通知列表（条件＋分页）
     * @param newsPageQuery
     * @return
     */
    PageDTO<SysMessage> pageQuery(NewsPageQuery newsPageQuery);

    /**
     * 获取最新未读消息列表
     * @return
     */
    UnreadMessageVO getUnreadMessage();

    /**
     * 发送短信消息
     * @param smsQuery
     * @return
     */
//    SmsResult sendSms(SmsQuery smsQuery);
}
