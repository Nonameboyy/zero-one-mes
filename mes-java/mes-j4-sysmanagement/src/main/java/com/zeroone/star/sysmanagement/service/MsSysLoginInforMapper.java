package com.zeroone.star.sysmanagement.service;

import com.zeroone.star.project.dto.j4.logmanagement.SysLoginInfoDTO;
import com.zeroone.star.sysmanagement.entity.SysLoginInfor;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

/**
 * @Description 将SysLoginInfor 转换为 SysLoginInforDTO
 * @Author diwu
 * @Date 2024/5/21
 */
@Mapper(componentModel = "spring")
public interface MsSysLoginInforMapper {
    SysLoginInfoDTO sysLoginInfoToDto(SysLoginInfor entity);
}
