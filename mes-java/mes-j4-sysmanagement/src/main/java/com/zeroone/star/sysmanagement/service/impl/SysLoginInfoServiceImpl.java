package com.zeroone.star.sysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.logmanagement.SysLoginInfoDTO;
import com.zeroone.star.project.query.j4.logmanagement.SysLoginInfoQuery;
import com.zeroone.star.sysmanagement.entity.SysLoginInfor;
import com.zeroone.star.sysmanagement.service.MsSysLoginInforMapper;
import com.zeroone.star.sysmanagement.service.SysLoginInfoService;
import com.zeroone.star.sysmanagement.mapper.SysLoginInfoMapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.Date;

/**
* @author diwu
* @description 针对表【sys_logininfor(系统访问记录)】的数据库操作Service实现
* @createDate 2024-05-18 23:35:56
*/
@Service
public class SysLoginInfoServiceImpl extends ServiceImpl<SysLoginInfoMapper, SysLoginInfor>
    implements SysLoginInfoService {

    @Resource
    private MsSysLoginInforMapper msSysLoginInforMapper;

    @Resource
    private SysLoginInfoMapper sysLoginInfoMapper;

    @Override
    public PageDTO<SysLoginInfoDTO> listAll(SysLoginInfoQuery query) {
        // 构建分页的查询对象
        Page<SysLoginInfor> sysLoginInfoPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<SysLoginInfor> wrapper = new QueryWrapper<>();
        //根据登录地点查询
        if(query.getLoginLocation()!= null){
            wrapper.like("login_location",query.getLoginLocation());
        }
        //根据登录用户查询
        if(query.getUserName()!= null){
            wrapper.like("user_name",query.getUserName());
        }
        //根据登录的状态
        if(query.getStatus()!= null){
            wrapper.eq("status",query.getStatus());
        }
        //根据时间的范围来查询
        if(query.getStartLoginTime()!=null && query.getEndLoginTime()!= null){
            //1. 先将前端的日期数据进行处理
            Date startLoginTime = query.getStartLoginTime();
            Date endLoginTime = query.getEndLoginTime();
            LocalDateTime startDateTime = LocalDateTime.ofInstant(startLoginTime.toInstant(), ZoneId.systemDefault())
                    .toLocalDate().atStartOfDay();
            LocalDateTime endDateTime = LocalDateTime.ofInstant(endLoginTime.toInstant(), ZoneId.systemDefault())
                    .toLocalDate().atStartOfDay().plusDays(1).minusSeconds(1);
            //2. 添加到wrapper 的条件当中去
            wrapper.between("login_time",startLoginTime,endLoginTime);
        }
//        // 执行查询
       Page<SysLoginInfor> sysLoginInfoList = baseMapper.selectPage(sysLoginInfoPage, wrapper);
       return PageDTO.create(sysLoginInfoList,src -> msSysLoginInforMapper.sysLoginInfoToDto(src));



    }

    @Override
    @Transactional
    public boolean add(SysLoginInfoDTO dto) {
        SysLoginInfor loginInfor = BeanUtil.copyProperties(dto, SysLoginInfor.class);
        int insert = sysLoginInfoMapper.insert(loginInfor);
        return insert>0;
    }
}




