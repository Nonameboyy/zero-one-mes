package com.zeroone.star.syshome.service;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.syshome.dto.plan.PlanDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.syshome.entity.CalTeamMember;
import com.baomidou.mybatisplus.extension.service.IService;


/**
 * <p>
 * 班组成员表 服务类
 * </p>
 *
 * @author lxh
 * @since 2024-05-29
 */
public interface ICalTeamMemberService extends IService<CalTeamMember> {
    PageDTO<PlanDTO> listPlan(PageQuery pageQuery);
}
