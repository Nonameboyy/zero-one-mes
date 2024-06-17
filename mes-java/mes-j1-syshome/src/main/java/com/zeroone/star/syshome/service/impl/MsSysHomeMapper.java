package com.zeroone.star.syshome.service.impl;

import com.zeroone.star.project.j1.syshome.dto.plan.PlanDTO;
import com.zeroone.star.project.j1.syshome.dto.toDoEvent.ToDoEventDTO;
import com.zeroone.star.project.j1.syshome.dto.workshop.WorkshopDTO;
import com.zeroone.star.project.j1.syshome.vo.plan.PlanVO;
import com.zeroone.star.project.j1.syshome.vo.toDoEvent.ToDoEventVO;
import com.zeroone.star.project.j1.syshome.vo.workshop.WorkshopVO;
import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：Sample对应MapStructMapper接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsSysHomeMapper {
    /**
     * 将 WorkshopVO 转换成 WorkshopDTO
     *
     * @param workshopVO vo对象
     * @return 转换后的结果
     */
    WorkshopDTO workshopVOToworkshopDTO(WorkshopVO workshopVO);

    /**
     * 将 PlanVO 转换成 PlanDTO
     * @param planVO vo对象
     * @return 转换后的结果
     */
    PlanDTO planVOToPlanDTO(PlanVO planVO);

    /**
     * 将 toDoEventVO 转换成 toDoEventDTO
     * @param toDoEventVO vo对象
     * @return 转换后的结果
     */
    ToDoEventDTO toDoEventVOTotoDoEventDTO(ToDoEventVO toDoEventVO);
}
