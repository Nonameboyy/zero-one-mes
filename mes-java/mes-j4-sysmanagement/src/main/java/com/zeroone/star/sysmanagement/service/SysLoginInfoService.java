package com.zeroone.star.sysmanagement.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.logmanagement.SysLoginInfoDTO;
import com.zeroone.star.project.query.j4.logmanagement.SysLoginInfoQuery;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.sysmanagement.entity.SysLoginInfor;
import org.springframework.stereotype.Service;

/**
* @author diwu
* @description 针对表【sys_logininfor(系统访问记录)】的数据库操作Service
* @createDate 2024-05-18 23:35:56
*/
@Service
public interface SysLoginInfoService extends IService<SysLoginInfor> {

    /**
     * 分页查询所有的数据
     *
     * @param query
     * @return
     */
    PageDTO<SysLoginInfoDTO> listAll(SysLoginInfoQuery query);

    boolean add(SysLoginInfoDTO dto);
}
