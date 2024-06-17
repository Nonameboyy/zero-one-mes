package com.zeroone.star.sysmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.sysmanagement.entity.LoginInfo;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 系统访问记录 Mapper 接口
 * </p>
 *
 * @author jingzi
 * @since 2024-05-19
 */
@Mapper
public interface LoginInfoMapper extends BaseMapper<LoginInfo> {

    /**
     * 获取登录日志访问接口
     * @return 日志实体
     */
    List<LoginInfo> selectLoginInfo();

    /**
     * 删除登录日志访问接口
     * @param ids 根据id集合查询
     * @return 返回结果
     */
    Long deleteLoginInfo(List<Long> ids);


    /**
     * 清空登录日志访问接口
     * @return 返回结果
     */
    int cleanLoginInfo();
}
