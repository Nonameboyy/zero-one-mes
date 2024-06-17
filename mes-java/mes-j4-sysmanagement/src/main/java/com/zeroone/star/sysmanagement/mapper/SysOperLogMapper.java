package com.zeroone.star.sysmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.sysmanagement.entity.SysOperLog;
import org.apache.ibatis.annotations.Mapper;
import java.util.List;

/**
 * 操作日志记录的Mapper接口。
 * 提供数据库操作日志记录的SQL映射方法，包括由MyBatis-Plus提供的基础CRUD操作，
 * 以及自定义的方法来满足特定的查询需求。
 *
 * @author lenyan
 * @since 2024-05-19
 */
@Mapper // 标识这是一个MyBatis的Mapper接口
public interface SysOperLogMapper extends BaseMapper<SysOperLog> {

    /**
     * 自定义查询方法：获取操作日志信息。
     * 这个方法可以根据具体需求定制查询逻辑，例如筛选、排序等。
     *
     * @return 操作日志列表
     */
    List<SysOperLog> selectOperLogInfo();
}