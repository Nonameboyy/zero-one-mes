package com.zeroone.star.orgstructure.service;

import com.zeroone.star.project.j1.orgstructure.dto.user.CompleteUserDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.UserDTO;
import com.zeroone.star.project.j1.orgstructure.query.user.UserQuery;

import java.util.List;

/**
 * 用户信息的Service接口
 * @author Tme
 */
public interface IUserQueryService {
    /**
     * 获取用户列表
     * @param userQuery
     * @return
     */
    public List<UserDTO> queryUserList(UserQuery userQuery);

    /**
     * 获取用户详情
     * @param userDTO
     * @return
     */
    public CompleteUserDTO queryUser(UserDTO userDTO);
}
