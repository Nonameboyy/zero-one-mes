package com.zeroone.star.project.j5.scheduleplan;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.AddPlanDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.PlanDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.PlanStatusDTO;
import com.zeroone.star.project.j5.query.scheduleplan.PlanPageQuery;
import com.zeroone.star.project.j5.vo.scheduleplan.PlanListVO;
import com.zeroone.star.project.j5.vo.scheduleplan.PlanVO;
import com.zeroone.star.project.vo.JsonVO;

import org.springframework.http.ResponseEntity;

import java.io.IOException;
import java.util.List;

/**
 * <p>
 * 描述：排班计划接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author interstellar
 * @version 1.0.0
 */
public interface SchedulePlanApis {
    /**
     * 查询排班计划列表
     * @param condition 查询条件
     * @author brickbreaker
     * @return  排班计划列表
     */
    JsonVO<PageDTO<PlanListVO>> queryPlanList (PlanPageQuery condition);

    /**
     * 获取计划详情
     * @param planId
     * @author brickbreaker
     * @return 计划详情
     */
    JsonVO<PlanVO> queryPlanDetails(Long planId);


    /**
     * 添加计划
     * @param addPlanDTO 计划信息
     * @author brickbreaker
     * @return 添加结果
     */
    JsonVO<Integer> addPlan(AddPlanDTO addPlanDTO);


    /**
     * 修改计划
     * @param planDTO 计划信息
     * @author brickbreaker
     * @return 修改结果
     */
    JsonVO<Integer> modifyPlan(PlanDTO planDTO);

    /**
     * 删除排版计划(可批量删除)
     * @param rems 删除数据的id集合
     *  @author sailing
     */
    JsonVO<Integer> removeSchPlan(List<Long> rems);

    /**
     * 修改计划状态
     * @param planDTO  修改状态模型
     * @author sailing
     */
    JsonVO<Integer>  modifySchPlanStatus(PlanStatusDTO planDTO);

    /**
     * 导出排班计划
     * @author interstellar
     */
    ResponseEntity<byte[]> exportSchPlan(List<Long> ids) throws IOException;

}
