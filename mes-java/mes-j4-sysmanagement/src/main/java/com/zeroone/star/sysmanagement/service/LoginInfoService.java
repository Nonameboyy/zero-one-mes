package com.zeroone.star.sysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.sysmanagement.entity.LoginInfo;

import java.util.List;

/**
 * <p>
 * 系统访问记录 服务类
 * </p>
 *
 * @author jingzi
 * @since 2024-05-19
 */
public interface LoginInfoService extends IService<LoginInfo>{


   /**
    * 获取登录日志信息
    * @return
    */
   List<LoginInfo> listLoginInfo();


   /**
    * 删除登录日志
    * @param ids 登录日志id
    */
   Long removeLoginInfo(List<Long> ids);

   /**
    * 清空登录日志
    */
   void clearLoginInfo();

}
