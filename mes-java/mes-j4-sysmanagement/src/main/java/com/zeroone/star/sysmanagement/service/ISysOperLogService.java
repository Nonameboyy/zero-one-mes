package com.zeroone.star.sysmanagement.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.sysmanagement.logmanagement.OperationLog.OperationLogQuery;
import com.zeroone.star.sysmanagement.entity.SysOperLog;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * 操作日志记录服务接口。
 * 提供操作日志的增删查等相关操作方法定义。
 * 扩展了MyBatis Plus的IService接口，用于基础的CRUD操作。
 *
 * @author lenyan
 * @since 2024-05-19
 */
public interface ISysOperLogService extends IService<SysOperLog> {
    /**
     * 新增操作日志
     *
     * @param operLog 操作日志对象
     */
    public void insertOperlog(SysOperLog operLog);

    /**
     * 查询系统操作日志集合
     *
     * @param query 操作日志对象
     * @return 操作日志集合
     */
    public PageDTO<SysOperLog> selectOperLogList(OperationLogQuery query);

    /**
     * 查询操作日志详细
     *
     * @param operId 操作ID
     * @return 操作日志对象
     */
    public SysOperLog selectOperLogById(Long operId);
    /**
     * 删除所有操作日志记录。
     * 此操作将清空操作日志表中的所有数据，请谨慎使用。
     */
    void removeAllOperLog();

    /**
     * 获取操作日志信息列表。
     *
     * @return 操作日志实体列表
     */
    List<SysOperLog> Operloginfo();

}
