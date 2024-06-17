package com.zeroone.star.orgstructure.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgstructure.entity.User;
import com.zeroone.star.project.j1.orgstructure.dto.user.AddUserDTO;
import com.zeroone.star.project.j1.orgstructure.dto.user.UpdateUserDTO;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

public interface IUserService extends IService<User> {
    public void saveUser(AddUserDTO addUserDTO);

    public void updateUser(UpdateUserDTO updateUserDTO);

    public void removeUser(List<Long> userIds);

    public Long checkUserNameUnique(Long userId, String name);

    public Long checkPhoneUnique(Long userId, String phoneNumber);

    public Long checkEmailUnique(Long userId, String email);

    boolean checkUser(Long userId);

    public void userExport(HttpServletResponse response) throws IOException;

    public void downloadUserTemplate(HttpServletResponse response) throws IOException;

    public void userImport(MultipartFile file) throws IOException;

}
