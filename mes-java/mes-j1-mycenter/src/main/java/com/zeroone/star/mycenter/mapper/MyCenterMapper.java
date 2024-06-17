package com.zeroone.star.mycenter.mapper;

import com.zeroone.star.mycenter.service.MyCenterService;
import com.zeroone.star.project.j1.mycenter.DO.sysUserDO;
import com.zeroone.star.project.j1.mycenter.dto.MyCenterDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import org.mapstruct.factory.Mappers;


@Mapper
public interface MyCenterMapper {


    @Update("update sys_user set nick_name = #{nick_name},sex = #{sex},update_time = #{update_time} where user_id = #{user_id}")
    void updateInfo(MyCenterDTO myCenterDTO);
    @Update("update sys_user set avatar =#{avatar},update_time = #{update_time} where user_id = #{user_id}")
    void updateAvatar(MyCenterDTO myCenterDTO);
    @Update("update sys_user set phonenumber = #{phonenumber},update_time = #{update_time} where user_id = #{user_id}")
    void updatePhone(MyCenterDTO myCenterDTO);
    @Update("update sys_user set email = #{email},update_time = #{update_time} where user_id = #{user_id}")
    void updateEmail(MyCenterDTO myCenterDTO);
    @Update("update sys_user set password = #{password},update_time = #{update_time} where user_id = #{user_id}")
    void updatePassword(MyCenterDTO myCenterDTO);

    @Select("select avatar,nick_name,phonenumber,email,sex,update_time,user_id from sys_user where user_id = #{id}")
    sysUserDO selectUser(int id);



}
