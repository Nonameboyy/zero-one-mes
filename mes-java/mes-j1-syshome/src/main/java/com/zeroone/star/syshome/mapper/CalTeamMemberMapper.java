package com.zeroone.star.syshome.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.j1.syshome.vo.plan.PlanVO;
import com.zeroone.star.syshome.entity.CalTeamMember;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * <p>
 * 班组成员表 Mapper 接口
 * </p>
 *
 * @author lxh
 * @since 2024-05-29
 */
@Mapper
public interface CalTeamMemberMapper extends BaseMapper<CalTeamMember> {
    @Select("SELECT tm.user_id, tm.user_name, t.team_name, s.start_time, s.end_time " +
            "FROM cal_teamshift ts " +
            "JOIN cal_team t ON ts.team_id = t.team_id " +
            "JOIN cal_team_member tm ON tm.team_id = t.team_id " +
            "JOIN cal_shift s ON ts.shift_id = s.shift_id")
    Page<PlanVO> selectPlan(Page<PlanVO> planVOPage);
}
