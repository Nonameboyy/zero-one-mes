package com.zeroone.star.scheduleplan.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.planteam.PlanTeamDTO;
import com.zeroone.star.project.j5.query.scheduleplan.planteam.AddPlanTeamQuery;
import com.zeroone.star.project.j5.query.scheduleplan.planteam.PlanTeamQuery;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.scheduleplan.entity.CalPlanTeam;

import java.util.List;

/**
 * <p>
 * 演示示例表 服务类
 * </p>
 *
 * @author awei
 * @since 2024-05-10
 */
public interface IPlanTeamService extends IService<CalPlanTeam> {
    /**
     * 分页查询所有数据
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<PlanTeamDTO> listAll(PlanTeamQuery query);

    /**
     * 添加关联班组(支持多项添加)
     * @param addPlanTeamQueries 添加关联班组参数
     * @return 结果: 0-失败, 1-成功
     */
    Integer addPlanTeam(List<AddPlanTeamQuery> addPlanTeamQueries);

    /**
     * 通过recordId删除关联班组数据
     * @param recordId ID\流水号
     * @return 删除结果: 0-失败, 1-成功
     */
    Integer deletePlanTeam(Long recordId);
}
