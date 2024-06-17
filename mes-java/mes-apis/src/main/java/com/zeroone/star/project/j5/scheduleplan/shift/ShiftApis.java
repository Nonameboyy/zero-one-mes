package com.zeroone.star.project.j5.scheduleplan.shift;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.shiftplan.ShiftPlanAddDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.shiftplan.ShiftPlanDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.shiftplan.ShiftPlanModifyDTO;
import com.zeroone.star.project.j5.query.scheduleplan.shiftplan.ShiftPlanQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

import java.util.List;

/**
 * <p>
 * 描述：排班计划接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author qwert
 * @version 1.0.0
 */
public interface ShiftApis {
    /**
     * 根据排班计划id来查询班次计划列表
     * @param shiftPlanQuery 排班计划id，具体的排班计划表的id，
     * @return  班次计划列表
     */
    JsonVO<PageDTO<ShiftPlanDTO>> queryShiftPlanByPlanId(ShiftPlanQuery shiftPlanQuery);

    /**
     * 新增班次计划
     *
     * @param shiftPlanAddDto 新增班次计划数据
     * @return 新增数据的唯一编号
     */
    JsonVO<Integer> addShiftPlan(ShiftPlanAddDTO shiftPlanAddDto);

    /**
     * 更新班次计划
     * @param shiftPlanModifyDto 更新班次计划数据
     * @return  修改的行数
     */
    JsonVO<Integer> modifyShiftPlan(ShiftPlanModifyDTO shiftPlanModifyDto);

    /**
     * 删除排班计划v1
     * @param shiftId 排班计划id
     * @return  修改的行数
     */
    JsonVO<Integer> removeShiftPlan(List<Long> shiftId);
}
