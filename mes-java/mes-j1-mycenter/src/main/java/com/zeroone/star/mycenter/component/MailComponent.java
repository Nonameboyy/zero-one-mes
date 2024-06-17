package com.zeroone.star.mycenter.component;


import com.zeroone.star.project.j1.mycenter.entity.MailMessage;
import org.springframework.mail.javamail.MimeMessageHelper;
import org.springframework.stereotype.Component;
import org.springframework.util.StringUtils;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.mail.javamail.JavaMailSenderImpl;
import javax.annotation.Resource;
import java.util.Date;
import java.util.Objects;

/**
 * 描述：书写一个邮件发送组件
 * @author 白河夜船
 * @version 1.0.0
 */
@Component
public class MailComponent {
    /**
     * 注入邮件工具类
     */
    @Resource
    private JavaMailSenderImpl mailSender;

    /**
     * 从配置中获取邮件发送人邮箱
     * @return 邮件发送人邮箱
     */
    private String getMailSendFrom() {
        return mailSender.getJavaMailProperties().getProperty("from");
    }

    /**
     * 从配置中获取邮件发送人名称
     * @return 邮件发送人名称
     */
    private String getMailSendFromName() {
        return mailSender.getJavaMailProperties().getProperty("name");
    }

    /**
     * 检测邮件信息类
     * @param msg 信息对象
     */
    private void checkMail(MailMessage msg) {
        if (StringUtils.isEmpty(msg.getTo())) {
            throw new RuntimeException("邮件收信人不能为空");
        }
        if (StringUtils.isEmpty(msg.getSubject())) {
            throw new RuntimeException("邮件主题不能为空");
        }
        if (StringUtils.isEmpty(msg.getText())) {
            throw new RuntimeException("邮件内容不能为空");
        }
    }

    /**
     * 构建复杂邮件信息类
     * @param msg 信息对象
     */
    private void sendMimeMail(MailMessage msg) {
        try {
            //true表示支持复杂类型
            MimeMessageHelper messageHelper = new MimeMessageHelper(mailSender.createMimeMessage(), true);
            //邮件发信人从配置项读取
            msg.setFrom(getMailSendFrom());
            msg.setFromName(getMailSendFromName());
            //邮件发信人
            messageHelper.setFrom(msg.getFrom(), msg.getFromName());
            //邮件收信人
            for (String one : msg.getTo().split(MailMessage.SR)) {
                messageHelper.addTo(one);
            }
            //邮件主题
            messageHelper.setSubject(msg.getSubject());
            //邮件内容
            messageHelper.setText(msg.getText());
            //抄送
            if (!StringUtils.isEmpty(msg.getCc())) {
                for (String one : msg.getCc().split(MailMessage.SR)) {
                    messageHelper.addCc(one);
                }
            }
            //密送
            if (!StringUtils.isEmpty(msg.getBcc())) {
                for (String one : msg.getBcc().split(MailMessage.SR)) {
                    messageHelper.addCc(one);
                }
            }
            //添加邮件附件
            if (msg.getMultipartFiles() != null) {
                for (MultipartFile multipartFile : msg.getMultipartFiles()) {
                    messageHelper.addAttachment(Objects.requireNonNull(multipartFile.getOriginalFilename()), multipartFile);
                }
            }
            //发送时间
            if (StringUtils.isEmpty(msg.getSentDate())) {
                msg.setSentDate(new Date());
            }
            messageHelper.setSentDate(msg.getSentDate());
            //正式发送邮件
            mailSender.send(messageHelper.getMimeMessage());
            msg.setStatus("ok");
        } catch (Exception e) {
            //发送失败
            throw new RuntimeException(e);
        }
    }

    /**
     * 发送邮件
     * @param msg 邮件信息对象
     * @return MailMessage对象，其中包含了状态信息
     */
    // 只暴露发送邮件的公共方法
    public MailMessage sendMail(MailMessage msg) {
        try {
            //1.检测邮件
            checkMail(msg);
            //2.发送邮件
            sendMimeMail(msg);
        } catch (Exception e) {
            e.printStackTrace();
            msg.setStatus("fail");
            msg.setError(e.getMessage());
        }
        return msg;
    }
}