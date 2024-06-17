package com.zeroone.star.orgstructure.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgstructure.entity.*;
import com.zeroone.star.orgstructure.mapper.*;
import com.zeroone.star.orgstructure.service.IUserQueryService;
import com.zeroone.star.project.j1.orgstructure.dto.user.CompleteUserDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.UserDTO;
import com.zeroone.star.project.j1.orgstructure.query.user.UserQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

/**
 * 用户信息接口实现类
 * @author Tme
 */
@Service
public class UserQueryServiceImpl implements IUserQueryService {

    //日期全局转换格式
    DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");

    @Autowired
    private SysUserMapper sysUserMapper;
    @Autowired
    private DeptMapper deptMapper;
    @Autowired
    private SysUserPostMapper sysUserPostMapper;
    @Autowired
    private PostMapper postMapper;
    @Autowired
    private SysUserRoleDOMapper sysUserRoleMapper;
    @Autowired
    private RoleMapper roleMapper;

    /**
     * 获取用户列表
     * @param userQuery
     * @return
     */
    public List<UserDTO> queryUserList(UserQuery userQuery)
    {
        List<SysUserDO> sysUserDOS = null;
        //构建分页对象
        IPage<SysUserDO> page = new Page<>(userQuery.getPageIndex(), userQuery.getPageSize());

        //构建用户表wrapper对象
        QueryWrapper<SysUserDO> queryWrapper = new QueryWrapper<>();

        //将query对象所有属性插入 使用lambda，避免字符串魔法值
        if(userQuery.getStatus() != null)
        {
            queryWrapper.lambda().eq(SysUserDO::getStatus, userQuery.getStatus());//用户状态精确查询
        }
        if(userQuery.getUserName() != null)
        {
            queryWrapper.lambda().like(SysUserDO::getUserName, userQuery.getUserName());//用户名称模糊查询
        }
        if(userQuery.getPhonenumber() != null)
        {
            queryWrapper.lambda().like(SysUserDO::getPhonenumber, userQuery.getPhonenumber());//用户电话模糊查询
        }
        //判断创建时间和结束时间是否为空
        if(userQuery.getBeginDate() != null && userQuery.getEndDate() != null)
        {
            //将userQuery的String日期转换为LocalDatetime类型
            LocalDateTime begin = LocalDateTime.parse(userQuery.getBeginDate() + " 00:00:00", dtf);
            LocalDateTime end = LocalDateTime.parse(userQuery.getEndDate() + " 23:59:59", dtf);

            queryWrapper.lambda().between(SysUserDO::getCreateTime, begin, end);//用户创建时间范围查询
        }
        //判断部门名称是否为空
        if (userQuery.getDept() != null)
        {
            //构建部门的wrapper 通过部门名称查询部门DO实体
            QueryWrapper<SysDeptDO> deptDOQueryWrapper = new QueryWrapper<>();
            deptDOQueryWrapper.lambda().eq(SysDeptDO::getDeptName, userQuery.getDept());
            SysDeptDO deptDO = deptMapper.selectOne(deptDOQueryWrapper);

            queryWrapper.lambda().eq(SysUserDO::getDeptId, deptDO.getDeptId());//用户部门id精确查询
        }

        sysUserMapper.selectPage(page, queryWrapper);
        sysUserDOS = page.getRecords();

        List<UserDTO> userDTOS = new ArrayList<>();
        if(sysUserDOS != null)
        {
            for(int i = 0; i < sysUserDOS.size(); i++)
            {
                UserDTO userDTO = new UserDTO();

                userDTO.setUserId(sysUserDOS.get(i).getUserId());
                userDTO.setUserName(sysUserDOS.get(i).getUserName());
                userDTO.setNickName(sysUserDOS.get(i).getNickName());

                //设置部门名称
                SysDeptDO deptDO = deptMapper.selectById(sysUserDOS.get(i).getDeptId());
                if(deptDO != null)
                {
                    userDTO.setDept(deptDO.getDeptName());
                }

                userDTO.setPhonenumber(sysUserDOS.get(i).getPhonenumber());
                userDTO.setStatus(sysUserDOS.get(i).getStatus());
                userDTO.setCreateTime(sysUserDOS.get(i).getCreateTime().format(dtf));
                userDTOS.add(userDTO);
            }
        }

        return userDTOS;
    }

    /**
     * 获取用户详情
     * @param userDTO
     * @return
     */
    @Override
    public CompleteUserDTO queryUser(UserDTO userDTO) {
        //构建结果对象
        CompleteUserDTO completeUserDTO = new CompleteUserDTO();
        //查询用户表信息
        SysUserDO sysUserDO = sysUserMapper.selectById(userDTO.getUserId());

        //填充属性
        completeUserDTO.setUserId(sysUserDO.getUserId());
        completeUserDTO.setUserName(sysUserDO.getUserName());
        completeUserDTO.setNickName(sysUserDO.getNickName());
        completeUserDTO.setCommit(sysUserDO.getRemark());
        //设置部门名称
        SysDeptDO deptDO = deptMapper.selectById(sysUserDO.getDeptId());
        if(deptDO != null)
        {
            completeUserDTO.setDept(deptDO.getDeptName());
        }

        completeUserDTO.setPhonenumber(sysUserDO.getPhonenumber());
        completeUserDTO.setStatus(sysUserDO.getStatus());
        completeUserDTO.setCreateTime(sysUserDO.getCreateTime().format(dtf));
        completeUserDTO.setEmail(sysUserDO.getEmail());

        //设置性别
        if(sysUserDO.getSex() != null)
        {
            if(sysUserDO.getSex().equals("0"))
            {
                completeUserDTO.setSex("男");
            }
            else if ((sysUserDO.getSex().equals("1")))
            {
                completeUserDTO.setSex("女");
            }
            else
            {
                completeUserDTO.setSex("未知");
            }
        }

        //获取岗位信息
        QueryWrapper<SysUserPostDO> sysUserPostDOQueryWrapper = new QueryWrapper<>();
        //构造查询wrapper 通过userid查询postid
        sysUserPostDOQueryWrapper.lambda().eq(SysUserPostDO::getUserId, userDTO.getUserId());
        List<SysUserPostDO> sysUserPostDOS = sysUserPostMapper.selectList(sysUserPostDOQueryWrapper);

        if(sysUserPostDOS != null)
        {
            //通过postid获取post名称
            for(int i = 0; i < sysUserPostDOS.size(); i++)
            {
                Long postId = sysUserPostDOS.get(i).getPostId();
                SysPostDO sysPostDO = postMapper.selectById(postId);
                if((sysPostDO != null) && (sysPostDO.getPostName() != null))
                {
                    completeUserDTO.getPost().add(sysPostDO.getPostName());
                }
            }
        }

        //获取角色列表
        QueryWrapper<SysUserRoleDO> sysUserRoleDOQueryWrapper = new QueryWrapper<>();
        //通过用户id查询用户的角色名称
        sysUserRoleDOQueryWrapper.lambda().eq(SysUserRoleDO::getUserId, completeUserDTO.getUserId());
        List<SysUserRoleDO> sysUserRoleDOS = sysUserRoleMapper.selectList(sysUserRoleDOQueryWrapper);
        if(sysUserRoleDOS != null)
        {
            for(int i = 0; i < sysUserRoleDOS.size(); i++)
            {
                if(sysUserRoleDOS.get(i).getRoleId() != null)
                {
                    //根据roleId查询roleName
                    Long roleId = sysUserRoleDOS.get(i).getRoleId();
                    SysRoleDO sysRoleDO = roleMapper.selectById(roleId);
                    if((sysRoleDO != null) && (sysRoleDO.getRoleName() != null))
                    {
                        completeUserDTO.getRule().add(sysRoleDO.getRoleName());
                    }
                }
            }

        }

        return completeUserDTO;
    }
}
