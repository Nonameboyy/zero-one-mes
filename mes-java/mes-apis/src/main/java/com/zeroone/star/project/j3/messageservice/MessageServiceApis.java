package com.zeroone.star.project.j3.messageservice;

import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.j3.dto.LogoutDTO;
import com.zeroone.star.project.j3.dto.SystemNotificationDTO;
import com.zeroone.star.project.j3.vo.LoginVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;



/**
 * 消息服务相关接口
 */

public interface MessageServiceApis {

    /**
     * 发送短信消息
     * @return
     */
   // JsonVO<SmsResult> sendOneSms(SmsQuery smsQuery);


    /**
     * 发送邮件
     * @param mailDTO 邮件信息
     * @return
     */
//    JsonVO<MailMessage> sendMail(MailDTO mailDTO);

    JsonVO<LoginVO> clientLogin(LoginDTO loginDTO);

    ResultStatus clientLogout(LogoutDTO logoutDTO);

    ResultStatus sendNotice(SystemNotificationDTO systemNotificationDTO);


}
