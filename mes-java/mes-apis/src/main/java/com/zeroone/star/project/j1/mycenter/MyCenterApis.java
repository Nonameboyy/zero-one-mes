package com.zeroone.star.project.j1.mycenter;

import com.zeroone.star.project.j1.mycenter.dto.MyCenterDTO;
import com.zeroone.star.project.j1.mycenter.entity.MailMessage;
import com.zeroone.star.project.j1.mycenter.query.MyCenterQuery;
import com.zeroone.star.project.j1.mycenter.dto.mail.MailDTO;
import com.zeroone.star.project.j1.mycenter.dto.user.UserDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author 柱、白河夜船
 * @version 1.0.0
 * @Description MyCenterApis
 */
public interface MyCenterApis {

    //@author 柱
    //修改个人信息
    JsonVO<MyCenterDTO> modifyInfo(MyCenterDTO myCenterDTO);
    //修改头像
    JsonVO<MyCenterDTO> modifyAvatar(MyCenterDTO myCenterDTO);



    //修改手机
    JsonVO<MyCenterDTO> modifyPhone(MyCenterDTO myCenterDTO);
    //修改邮箱
    JsonVO<MyCenterDTO> modifyEmail(MyCenterDTO myCenterDTO);
    //修改密码
    JsonVO<MyCenterDTO> modifyPassword(MyCenterDTO myCenterDTO);


    //@author 白河夜船








    /**
     * 获取个人信息,ThreadLocal获取登录ID
     */
    JsonVO<UserDTO> getPersonalInfo(Long userId);

    /**
     * 获取邮箱验证码
     * @param mailDto
     * @return
     */
    JsonVO<MailMessage> getEMailCode(MailDTO mailDto);

    /**
     * 获取手机验证码
     * @return
     */
    JsonVO<String> getPhoneCode(String phone);}
