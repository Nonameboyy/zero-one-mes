package com.zeroone.star.scheduleplan.service;

import com.zeroone.star.project.j5.dto.scheduleplan.PlanDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.PlanStatusDTO;
import com.zeroone.star.scheduleplan.entity.CalPlan;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.AddPlanDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.PlanDTO;
import com.zeroone.star.project.j5.query.scheduleplan.PlanPageQuery;
import com.zeroone.star.project.j5.vo.scheduleplan.PlanListVO;
import com.zeroone.star.project.j5.vo.scheduleplan.PlanVO;
import com.zeroone.star.scheduleplan.entity.CalPlan;
import org.springframework.http.ResponseEntity;

import java.io.IOException;
import java.util.List;

/**
 * <p>
 * 排班计划表 服务类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
public interface ICalPlanService extends IService<CalPlan> {
    /**
     * 删除排班计划(可批量删除)
     * @param rems 删除数据的id集合
     *  @author sailing
     */
    boolean removeSchPlan(List<Long> rems);

    /**
     * 修改计划状态
     * @param condition  修改状态模型
     * @author sailing
     */
    boolean  modifySchPlanStatus(PlanStatusDTO condition);

    /**
     * 导出排班计划
     */
    ResponseEntity<byte[]> exportSchPlan(List<Long> ids) throws IOException;

    /**
     * 分页+条件查询
     * @author brickbreaker
     * @param condition 查询条件
     * @return 分页数据
     */
    PageDTO<PlanListVO> queryPlanList(PlanPageQuery condition);

    /**
     * 查询计划详情
     * @author brickbreaker
     * @param planId 计划ID
     * @return 计划详情
     */
    PlanVO queryPlanDetails(Long planId);


    /**
     * 添加计划
     * @author brickbreaker
     * @param condition 添加条件
     * @return 添加结果
     */
    boolean addPlan(AddPlanDTO condition);

    /**
     * 修改计划
     * @author brickbreaker
     * @param planDTO 修改数据
     * @return 修改结果
     */
    boolean modifyPlan(PlanDTO planDTO);
}
