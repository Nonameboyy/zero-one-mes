package com.zeroone.star.mycenter.service;

import com.zaxxer.hikari.pool.HikariProxyCallableStatement;
import com.zeroone.star.mycenter.mapper.MapStructMyCenterMapper;
import com.zeroone.star.mycenter.mapper.MyCenterMapper;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.j1.mycenter.DO.sysUserDO;
import com.zeroone.star.project.j1.mycenter.MyCenterApis;
import com.zeroone.star.project.j1.mycenter.dto.MyCenterDTO;
import io.github.bluemiaomiao.service.FastdfsClientService;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;
import org.mapstruct.factory.Mappers;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.IOException;

@Service
public class MyCenterService  {

    private final MyCenterMapper myCenterMapper;
    private final PasswordEncoder passwordEncoder;
    private final MapStructMyCenterMapper mapStructMyCenterMapper;
    @Resource
    private FastDfsClientComponent dfs;
    @Autowired
    public MyCenterService(MyCenterMapper myCenterMapper, PasswordEncoder passwordEncoder,MapStructMyCenterMapper mapStructMyCenterMapper) {
        this.myCenterMapper = myCenterMapper;
        this.passwordEncoder = passwordEncoder;
        this.mapStructMyCenterMapper = mapStructMyCenterMapper;

    }
    public MyCenterDTO updateInfo(MyCenterDTO myCenterDTO) {
        int id = myCenterDTO.getUser_id();
        myCenterMapper.updateInfo(myCenterDTO);
        return mapStructMyCenterMapper.INSTANCE.SysUserDOToMyCenterDTO(myCenterMapper.selectUser(id));
    }


    public MyCenterDTO updateAvatar(MyCenterDTO myCenterDTO) throws Exception {
        int id = myCenterDTO.getUser_id();
        MultipartFile image = myCenterDTO.getImage();
        String filename = image.getOriginalFilename();
        String suffix = filename.substring(filename.lastIndexOf(".")+1);
        FastDfsFileInfo result = dfs.uploadFile(image.getBytes(), suffix);
        myCenterDTO.setAvatar(result.getGroup()+"/"+ result.getStorageId());

        myCenterMapper.updateAvatar(myCenterDTO);
        return mapStructMyCenterMapper.INSTANCE.SysUserDOToMyCenterDTO(myCenterMapper.selectUser(id));
    }


    public MyCenterDTO updatePhone(MyCenterDTO myCenterDTO) {
        int id = myCenterDTO.getUser_id();
        myCenterMapper.updatePhone(myCenterDTO);
        return mapStructMyCenterMapper.INSTANCE.SysUserDOToMyCenterDTO(myCenterMapper.selectUser(id));
    }


    public MyCenterDTO updateEmail(MyCenterDTO myCenterDTO) {
        int id = myCenterDTO.getUser_id();
        myCenterMapper.updateEmail(myCenterDTO);
        return mapStructMyCenterMapper.INSTANCE.SysUserDOToMyCenterDTO(myCenterMapper.selectUser(id));
    }


    public MyCenterDTO updatePassword(MyCenterDTO myCenterDTO) {
        int id = myCenterDTO.getUser_id();
        myCenterDTO.setPassword(passwordEncoder.encode(myCenterDTO.getPassword()));
        myCenterMapper.updatePassword(myCenterDTO);
        return mapStructMyCenterMapper.INSTANCE.SysUserDOToMyCenterDTO(myCenterMapper.selectUser(id));
    }



}
