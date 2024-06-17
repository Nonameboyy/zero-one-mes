package com.zeroone.star.orgstructure.service.impl;

import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.context.AnalysisContext;
import com.alibaba.excel.event.AnalysisEventListener;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.entity.User;
import com.zeroone.star.orgstructure.entity.UserPost;
import com.zeroone.star.orgstructure.entity.UserRole;
import com.zeroone.star.orgstructure.mapper.UserMapper;
import com.zeroone.star.orgstructure.service.IUserPostService;
import com.zeroone.star.orgstructure.service.IUserRoleService;
import com.zeroone.star.orgstructure.service.IUserService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j1.orgstructure.dto.user.AddUserDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.UpdateUserDTO;

import com.zeroone.star.project.j1.orgstructure.dto.user.UserTemplateDTO;
import lombok.SneakyThrows;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.net.URLEncoder;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {

    @Resource
    private UserMapper userMapper;
    @Resource
    private IUserRoleService userRoleService;

    @Resource
    private IUserPostService userPostService;

    /**
     * 新增用户
     * @param addUserDTO 传入用户信息
     */
    @SneakyThrows
    public void saveUser(AddUserDTO addUserDTO){
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        User user = new  User();
        BeanUtils.copyProperties(addUserDTO, user, "postId", "roleId");
        user.setCreateTime(LocalDateTime.now());
//        UserDTO currentUser = userHolder.getCurrentUser();
//        user.setCreateBy(currentUser.getUsername());
        user.setDelFlag("0");
        this.save(user);

        queryWrapper.eq(User::getUserName, addUserDTO.getUserName());
        Long userId = userMapper.selectOne(queryWrapper).getUserId();

        List<UserPost> userPosts = new ArrayList<>();
        for (Long postId : addUserDTO.getPostId()) {
            UserPost userPost = new UserPost();
            userPost.setUserId(userId);
            userPost.setPostId(postId);
            userPosts.add(userPost);
        }
        userPostService.saveBatch(userPosts);

        List<UserRole> userRoles = new ArrayList<>();
        for (Long roleId : addUserDTO.getRoleId()) {
            UserRole userRole = new UserRole();
            userRole.setUserId(userId);
            userRole.setRoleId(roleId);
            userRoles.add(userRole);
        }
        userRoleService.saveBatch(userRoles);
    }

    /**
     * 修改用户信息
     * @param updateUserDTO 传入的待更新用户信息
     */
    @Override
    public void updateUser(UpdateUserDTO updateUserDTO) {
        User user = new  User();
        BeanUtils.copyProperties(updateUserDTO, user, "postId", "roleId");
        user.setUpdateTime(LocalDateTime.now());

        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(User::getUserId, updateUserDTO.getUserId());
        this.update(user, queryWrapper);

        LambdaQueryWrapper<UserRole> queryWrapper1 = new LambdaQueryWrapper<>();
        queryWrapper1.eq(UserRole::getUserId, updateUserDTO.getUserId());
        userRoleService.remove(queryWrapper1);

        LambdaQueryWrapper<UserPost> queryWrapper2 = new LambdaQueryWrapper<>();
        queryWrapper2.eq(UserPost::getUserId, updateUserDTO.getUserId());
        userPostService.remove(queryWrapper2);

        List<UserPost> userPosts = new ArrayList<>();
        for (Long postId : updateUserDTO.getPostId()) {
            UserPost userPost = new UserPost();
            userPost.setUserId(updateUserDTO.getUserId());
            userPost.setPostId(postId);
            userPosts.add(userPost);
        }
        userPostService.saveBatch(userPosts);

        List<UserRole> userRoles = new ArrayList<>();
        for (Long roleId : updateUserDTO.getRoleId()) {
            UserRole userRole = new UserRole();
            userRole.setUserId(updateUserDTO.getUserId());
            userRole.setRoleId(roleId);
            userRoles.add(userRole);
        }
        userRoleService.saveBatch(userRoles);
    }

    /**
     * 删除用户信息，支持批量删除
     * @param userIds 要删除的用户id
     */
    @Override
    public void removeUser(List<Long> userIds) {
        userMapper.deleteBatchIds(userIds);

        for(Long id : userIds){
            LambdaQueryWrapper<UserRole> Wrapper1 = new LambdaQueryWrapper<>();
            Wrapper1.eq(UserRole::getUserId, id);
            userRoleService.remove(Wrapper1);

            LambdaQueryWrapper<UserPost> Wrapper2 = new LambdaQueryWrapper<>();
            Wrapper2.eq(UserPost::getUserId, id);
            userPostService.remove(Wrapper2);
        }
    }

    /**
     * 校验用户名是否唯一
     * @param name 用户名
     * @return 返回查询结果个数
     */
    @Override
    public Long checkUserNameUnique(Long userId, String name) {
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        if(userId != null){
            queryWrapper.ne(User::getUserId, userId).eq(User::getUserName, name);
            return userMapper.selectCount(queryWrapper);
        }
        queryWrapper.eq(User::getUserName, name);
        return userMapper.selectCount(queryWrapper);
    }

    /**
     * 校验电话号码是否唯一
     * @param phoneNumber 电话号码
     * @return 返回查询结果个数
     */
    @Override
    public Long checkPhoneUnique(Long userId, String phoneNumber) {
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        if(userId != null){
            queryWrapper.ne(User::getUserId, userId).eq(User::getPhonenumber, phoneNumber);
            return userMapper.selectCount(queryWrapper);
        }
        queryWrapper.eq(User::getPhonenumber, phoneNumber);
        return userMapper.selectCount(queryWrapper);
    }

    /**
     * 检验邮箱是否唯一
     * @param email 邮箱
     * @return 返回查询结果个数
     */
    @Override
    public Long checkEmailUnique(Long userId, String email) {
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        if(userId != null){
            queryWrapper.ne(User::getUserId, userId).eq(User::getEmail, email);
            return userMapper.selectCount(queryWrapper);
        }
        queryWrapper.eq(User::getEmail, email);
        return userMapper.selectCount(queryWrapper);
    }

    @Override
    public boolean checkUser(Long userId) {
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(User::getUserId, userId);
        User user = userMapper.selectOne(queryWrapper);
        return user != null;
    }


    @Override
    public void userExport(HttpServletResponse response) throws IOException {

        //将查询到的所有用户数据users存入userTemplateDTOList
        List<User> users = this.list();
        List<UserTemplateDTO> userTemplateDTOList = new ArrayList<>();
        for (User user : users) {
            UserTemplateDTO dto = new UserTemplateDTO();
            BeanUtils.copyProperties(user, dto);
            userTemplateDTOList.add(dto);
        }

        // 这里注意 有同学反应使用swagger 会导致各种问题，请直接用浏览器或者用postman
        response.setContentType("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
        response.setCharacterEncoding("utf-8");
        // 这里URLEncoder.encode可以防止中文乱码 当然和easyexcel没有关系
        String fileName = URLEncoder.encode("用户导出", "UTF-8").replaceAll("\\+", "%20");
        response.setHeader("Content-disposition", "attachment;filename*=utf-8''" + fileName + ".xlsx");
        EasyExcel.write(response.getOutputStream(), UserTemplateDTO.class).sheet("用户").doWrite(userTemplateDTOList);
    }

    @Override
    public void userImport(MultipartFile file) throws IOException {

        // 读取excel
        EasyExcel.read(file.getInputStream(), UserTemplateDTO.class, new AnalysisEventListener<UserTemplateDTO>() {
            // 每解析一行数据,该方法会被调用一次
            @Override
            public void invoke(UserTemplateDTO userTemplateDTO, AnalysisContext analysisContext) {
                System.out.println("解析数据为:" + userTemplateDTO.toString());

                //将解析的数据保存到数据库
                //将解析到的usersTemplateDTO存入AddUserDTO
                AddUserDTO addUserDTO = new AddUserDTO();
                BeanUtils.copyProperties(userTemplateDTO, addUserDTO,"userId");
                saveUser(addUserDTO);
            }
            // 全部解析完成被调用
            @Override
            public void doAfterAllAnalysed(AnalysisContext analysisContext) {
                System.out.println("解析完成...");
            }
        }).sheet().doRead();

    }

    @Override
    public void downloadUserTemplate(HttpServletResponse response) throws IOException {
        //写一个空数据
        List<UserTemplateDTO> users = new ArrayList<>();
        // 这里注意 有同学反应使用swagger 会导致各种问题，请直接用浏览器或者用postman
        response.setContentType("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
        response.setCharacterEncoding("utf-8");
        // 这里URLEncoder.encode可以防止中文乱码 当然和easyexcel没有关系
        String fileName = URLEncoder.encode("用户模版", "UTF-8").replaceAll("\\+", "%20");
        response.setHeader("Content-disposition", "attachment;filename*=utf-8''" + fileName + ".xlsx");
        EasyExcel.write(response.getOutputStream(), UserTemplateDTO.class).sheet("模板").doWrite(users);
    }
}
