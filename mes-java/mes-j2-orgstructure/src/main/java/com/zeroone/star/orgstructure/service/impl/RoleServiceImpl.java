package com.zeroone.star.orgstructure.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.date.DateTime;
import com.alibaba.cloud.commons.lang.StringUtils;
import com.zeroone.star.orgstructure.entity.RoleDO;
import com.zeroone.star.orgstructure.mapper.*;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.entity.UserDO;
import com.zeroone.star.orgstructure.entity.UserRoleDO;
import com.zeroone.star.orgstructure.parameterMapstruct.MsUserRoleMapper;
import com.zeroone.star.orgstructure.service.RoleService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.orgstructure.dto.role.*;
import com.zeroone.star.project.j2.orgstructure.query.role.RoleConditionQuery;
import com.zeroone.star.project.j2.orgstructure.query.role.RolePermissionsQuery;
import com.zeroone.star.project.j2.orgstructure.query.role.UserRoleQuery;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import net.sf.cglib.core.Local;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import com.zeroone.star.orgstructure.mapper.UserRoleMapper;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

/**
 * role对应的MapStructMapper接口
 */
@Mapper(componentModel = "spring")
interface MsRoleMapper {
    /**
     * 将roleDO转为 roleDTO
     *
     * @param roleDO
     * @return
     */
    RoleListDTO roleDOToRoleListDTO(RoleDO roleDO);
    RoleDTO roleDOToRoleDTO(RoleDO roleDO);
    RolePermissionsDTO roleDOTORolePermissionsDTO(RoleDO roleDO);

    List<RoleListDTO> roleDOToRoleListDTO(List<RoleDO> roleDOList);
}

/**
 * 描述：Role 角色服务接口
 *
 * @author 0xu0 tianyantudou
 * @version 1.0.0
 */
@Service
@Slf4j
public class RoleServiceImpl extends ServiceImpl<RoleMapper, RoleDO> implements RoleService {

    @Autowired
    RoleMapper roleMapper;
    @Resource
    UserHolder userHolder;
    @Resource
    UserRoleMapper userRoleMapper;
    @Resource
    EasyExcelComponent excel;

    @Resource
    private MsRoleMapper msRoleMapper;

    @Resource
    private UserConvertMapper userConvertMapper;

    @Resource
    private UserMapper userMapper;
    @Resource
    private MsUserRoleMapper msUserRoleMapper;


    /**
     * 查询全部角色列表
     *
     * @return 角色集合
     * @author 天衍土豆
     */
    @Override
    public List<RoleListDTO> listRoles() {
        log.info("查询全部列表");
        List<RoleDO> result = baseMapper.selectList(null);
        return msRoleMapper.roleDOToRoleListDTO(result);
    }

    @Override
    public PageDTO<RoleListDTO> listPageRoles(RoleConditionQuery condition) {
        //构建分页查询对象
        Page<RoleDO> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        //构建分页查询条件
        LambdaQueryWrapper<RoleDO> queryWrapper = new LambdaQueryWrapper();
        if (StringUtils.isNotEmpty(condition.getRoleName())) {
            queryWrapper.like(RoleDO::getRoleName, condition.getRoleName());
        }
        if (StringUtils.isNotEmpty(condition.getRoleKey())) {
            queryWrapper.like(RoleDO::getRoleKey, condition.getRoleKey());
        }
        if (StringUtils.isNotEmpty(condition.getStatus())) {
            queryWrapper.eq(RoleDO::getStatus, condition.getStatus());
        }
        if (StringUtils.isNotEmpty(condition.getStartTime()) && StringUtils.isNotEmpty(condition.getEndTime())){
            queryWrapper.between(RoleDO::getCreateTime, condition.getStartTime() , condition.getEndTime());
        }

        //执行查询
        Page<RoleDO> result = baseMapper.selectPage(page, queryWrapper);
        return PageDTO.create(result, src -> msRoleMapper.roleDOToRoleListDTO(src));
    }

    /**
     * 根据id查询角色详情
     * @param id
     * @return
     */
    @Override
    public RoleDTO getById(Integer id) {
        RoleDO result = baseMapper.selectById(id);
        return msRoleMapper.roleDOToRoleDTO(result);
    }

    @Override
    public RolePermissionsDTO getPermissions(Integer id) {
        RoleDO result = baseMapper.selectById(id);
        return msRoleMapper.roleDOTORolePermissionsDTO(result);
    }

    @Override
    public int updatePermissions(RolePermissionsQuery rolePermissionsQuery) {
        RoleDO roleDO= new RoleDO();
        BeanUtils.copyProperties(rolePermissionsQuery,roleDO);
        roleDO.setUpdateTime(LocalDateTime.now());
        int rows = baseMapper.updateById(roleDO);
        return rows;
    }

    /**
     * 添加角色
     *
     * @param roleDTO
     * @return
     * @author 0xu0
     */
    @Override
    public Long addRole(@RequestBody RoleAddDto roleDTO) {
        RoleDO roleDo = new RoleDO();
        System.out.println(roleDTO.toString());
        //复制给Do
        BeanUtil.copyProperties(roleDTO, roleDo, true);
        //设置创建者，时间
        roleDo.setCreateTime(LocalDateTime.now());
        roleDo.setDelFlag("0");//伪删除标志，0表示存在2表示删除
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        roleDo.setCreateBy(currentUser.getUsername());
        roleMapper.insert(roleDo);
        Long roleId = roleDo.getRoleId();
        return roleId;
    }

    /***
     * 修改角色状态（角色页面，有个开关符号，控制停用和启用）
     * @author 0xu0
     * @param roleStatusModifyDto
     * @return
     */
    @Override
    public Integer modifyRoleStatus(@RequestBody RoleStatusModifyDto roleStatusModifyDto) throws Exception {
        UpdateWrapper updateRoleStatus = new UpdateWrapper();
        updateRoleStatus.eq("role_id", roleStatusModifyDto.getRoleId());
       RoleDO roleDo = new RoleDO();
        //复制给Do
        BeanUtil.copyProperties(roleStatusModifyDto, roleDo, true);
        //设置创建者，时间
        UserDTO currentUser = userHolder.getCurrentUser();
        roleDo.setUpdateBy(currentUser.getUsername());
        roleDo.setUpdateTime(LocalDateTime.now());
        //返回修改的主键值
        int update = roleMapper.update(roleDo, updateRoleStatus);
        if (update > 0) {
            return update;
        }
        return 0;
    }


    /**
     * 删除角色，支持批量删除
     *
     * @param ids
     * @return
     * @author 0xu0
     */
    @Override
    public Integer deleteRoles(@RequestParam List<String> ids) {
        return roleMapper.deleteBatchIds(ids);
    }

    /**
     * 修改角色信息
     *
     * @param roleDTO
     * @return
     */
    @Override
    public Integer modifyRoleInfo(@RequestBody RoleModifyDto roleDTO) throws Exception {
        UpdateWrapper updateRoleInfo = new UpdateWrapper();
        updateRoleInfo.eq("role_id", roleDTO.getRoleId());
        RoleDO roleDo = new RoleDO();
        //复制给Do
        BeanUtil.copyProperties(roleDTO, roleDo, true);
        //设置创建者，时间
        UserDTO currentUser = userHolder.getCurrentUser();
        roleDo.setUpdateBy(currentUser.getUsername());
        roleDo.setUpdateTime(LocalDateTime.now());
        //返回修改的主键值
        return roleMapper.update(roleDo, updateRoleInfo);
    }


    /*
     * 查找该角色所分配的用户
     * */
    @Override
    public PageDTO<UserRoleDTO> getUsersByRole(UserRoleQuery query) {

        QueryWrapper<UserRoleDO> queryWrapper = new QueryWrapper<>();
        // 添加角色条件
        queryWrapper.eq("role_id", query.getRoleId());
        //找出符合条件的用户
        List<UserRoleDO> userRoleDOS = userRoleMapper.selectList(queryWrapper);
        // 提取用户ID列表
        List<Long> userIds = new ArrayList<>();
        for (UserRoleDO userRole : userRoleDOS) {
            userIds.add(userRole.getUserId());
        }

        //创建分页条件
        Page<UserDO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 根据用户ID列表查询用户信息
        LambdaQueryWrapper<UserDO> lqw = new LambdaQueryWrapper<>();
        lqw.in(UserDO::getUserId, userIds);
        if(null != query.getUserName()) lqw.like(UserDO::getUserName,query.getUserName());
        if(null != query.getPhoneNumber()) lqw.like(UserDO::getPhonenumber, query.getPhoneNumber());

        Page<UserDO> res = userMapper.selectPage(page, lqw);
        return PageDTO.create(res, src -> msUserRoleMapper.userDOToUserDTO(src));
    }

    /*
     * 取消授权
     * */
    @Override
    public int deleteAuthUsers(Long roleId, Long[] userIds) {
        return userRoleMapper.deleteUserRoleInfos(roleId, userIds);
    }

    /*
     * 批量添加用户授权
     * */
    @Override
    public int insertAuthUsers(Long roleId, Long[] userIds) {
        // 新增用户与角色管理
        List<UserRoleDO> list = new ArrayList<>();
        for (Long userId : userIds) {
            UserRoleDO ur = new UserRoleDO();
            ur.setUserId(userId);
            ur.setRoleId(roleId);
            list.add(ur);
        }
        return userRoleMapper.batchUserRole(list);
    }


    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> downloadExcel() {
        QueryWrapper queryWrapper = new QueryWrapper();
        queryWrapper.select("role_id", "role_name", "role_key", "role_sort", "data_scope", "status");
        List<RoleDO> roles = roleMapper.selectList(queryWrapper);
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("role", out, RoleDO.class, roles);
        byte[] bytes = out.toByteArray();
        out.close();
        HttpHeaders headers = new HttpHeaders();
        String filename = "report-" + DateTime.now().toString("yyyyHHddHHmmssS") + ".xlsx";
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
/*
        headers.setContentType(MediaType.valueOf("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"));
*/
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }

}
