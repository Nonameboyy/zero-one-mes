package com.zeroone.star.syshome.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.syshome.dto.plan.PlanDTO;
import com.zeroone.star.project.j1.syshome.vo.plan.PlanVO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.syshome.entity.CalTeamMember;
import com.zeroone.star.syshome.mapper.CalTeamMemberMapper;
import com.zeroone.star.syshome.service.ICalTeamMemberService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 班组成员表 服务实现类
 * </p>
 *
 * @author lxh
 * @since 2024-05-29
 */
@Service
public class CalTeamMemberServiceImpl extends ServiceImpl<CalTeamMemberMapper, CalTeamMember> implements ICalTeamMemberService {

    @Resource
    MsSysHomeMapper msSysHomeMapper;
    @Resource
    CalTeamMemberMapper calTeamMemberMapper;

    @Override
    public PageDTO<PlanDTO> listPlan(PageQuery pageQuery) {
        // 构建分页查询对象
        Page<PlanVO> page = new Page<>(pageQuery.getPageIndex(), pageQuery.getPageSize());
        // 执行分页查询
        Page<PlanVO> result = calTeamMemberMapper.selectPlan(page);
        // 结果转换成DTO
        return PageDTO.create(result, src -> msSysHomeMapper.planVOToPlanDTO(src));
    }
}
