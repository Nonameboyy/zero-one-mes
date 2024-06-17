package com.zeroone.star.syshome.mapper;


import com.zeroone.star.project.j1.syshome.vo.workshop.WorkshopVO;
import com.zeroone.star.syshome.entity.MdWorkshop;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 车间表 Mapper 接口
 * </p>
 *
 * @author lxh
 * @since 2024-05-29
 */
@Mapper
public interface MdWorkshopMapper extends BaseMapper<MdWorkshop> {

    @Select("SELECT w.workshop_id, w.workshop_name, s.workstation_id, s.workstation_name, COUNT(u.user_id) as workstation_total_users " +
            "FROM md_workshop w " +
            "JOIN md_workstation s ON w.workshop_id = s.workshop_id " +
            "JOIN pro_user_workstation u ON s.workstation_id = u.workstation_id " +
            "GROUP BY w.workshop_id, s.workstation_id")
    List<WorkshopVO> selectWorkshop();

}
