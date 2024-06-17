package com.zeroone.star.sysmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.sysmanagement.logmanagement.OperationLog.OperationLogQuery;
import com.zeroone.star.sysmanagement.entity.SysOperLog;
import com.zeroone.star.sysmanagement.mapper.SysOperLogMapper;
import com.zeroone.star.sysmanagement.service.ISysOperLogService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.apache.commons.lang3.StringUtils;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

/**
 * 操作日志记录服务实现类。
 * 实现了{@link ISysOperLogService}接口，提供了操作日志的增删改查等功能的具体实现。
 * 基于MyBatis Plus的{@link ServiceImpl}简化 CRUD 操作的实现。
 *
 * @author lenyan
 * @since 2024-05-19
 */
@Service
public class SysOperLogServiceImpl extends ServiceImpl<SysOperLogMapper, SysOperLog> implements ISysOperLogService {

    @Resource
    private SysOperLogMapper sysOperLogMapper;

    /**
     * 删除所有操作日志记录。
     * 根据当前时间删除所有的历史操作日志，注意：此操作不可逆，请谨慎使用。
     */
    @Override
    public void insertOperlog(SysOperLog operLog) {
        sysOperLogMapper.insert(operLog);
    }

    @Override
    public PageDTO<SysOperLog> selectOperLogList(OperationLogQuery query) {
        //组装查询条件
        QueryWrapper<SysOperLog> queryWrapper = new QueryWrapper<>();
        if (StringUtils.isNotBlank(query.getOperName())) {
            queryWrapper.like("oper_name", query.getOperName());
        }
        if (StringUtils.isNotBlank(query.getBusinessType())) {
            queryWrapper.eq("business_type", query.getBusinessType());
        }
        if (query.getStatus() != null) {
            queryWrapper.eq("status", query.getStatus());
        }
        if (StringUtils.isNotBlank(query.getBeginTime())) {
            queryWrapper.ge("oper_time", query.getBeginTime());
        }
        if (StringUtils.isNotBlank(query.getEndTime())) {
            queryWrapper.le("oper_time", query.getEndTime());
        }
        if (StringUtils.isNotBlank(query.getTitle())) {
            queryWrapper.like("title", query.getTitle());
        }
        if (StringUtils.isNotBlank(query.getOrderByColumn())) {
            queryWrapper.orderBy(true, "asc".equals(query.getIsAsc()), query.getOrderByColumn());
        }
        //分页查询
        Page<SysOperLog> sysOperLogPageDTO = new Page<>(query.getPageIndex(), query.getPageSize());
        Page<SysOperLog> sysOperLogPage = sysOperLogMapper.selectPage(sysOperLogPageDTO, queryWrapper);
        PageDTO<SysOperLog> resPage = PageDTO.create(sysOperLogPage);
        return resPage;
    }


    @Override
    public SysOperLog selectOperLogById(Long operId) {
        return sysOperLogMapper.selectById(operId);
    }

    @Override
    public void removeAllOperLog() {
        QueryWrapper<SysOperLog> queryWrapper = new QueryWrapper<>();
        queryWrapper.le("oper_time", LocalDateTime.now()); // 假设 oper_time 字段表示操作时间，删除时间小于等于当前时间的记录
        sysOperLogMapper.delete(queryWrapper);
    }

    /**
     * 查询操作日志信息。
     *
     * @return 操作日志实体列表
     */
    @Override
    public List<SysOperLog> Operloginfo() {
        return sysOperLogMapper.selectOperLogInfo();
    }
}
