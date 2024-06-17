package com.zeroone.star.project.j1.syshome;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.syshome.dto.facility.FacilityDTO;
import com.zeroone.star.project.j1.syshome.dto.plan.PlanDTO;
import com.zeroone.star.project.j1.syshome.dto.production.ProductionDTO;
import com.zeroone.star.project.j1.syshome.dto.quality.QualityDTO;
import com.zeroone.star.project.j1.syshome.dto.repertory.RepertoryDTO;
import com.zeroone.star.project.j1.syshome.dto.toDoEvent.ToDoEventDTO;
import com.zeroone.star.project.j1.syshome.dto.workshop.WorkshopDTO;
import com.zeroone.star.project.j1.syshome.query.EPageQuery;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：系统首页接口
 * </p>
 * @author twelve
 * @version 1.0.0
 */
public interface SysHomeApis {
    /**
     * 生产进度分页查询
     * @param condition 查询条件对象
     * @return 查询结果
     */
    JsonVO<PageDTO<ProductionDTO>> queryProduction(EPageQuery condition);
    /**
     * 通过仓库编号查询数据
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<List<RepertoryDTO>> queryRepertory(Long id);
    /**
     * 设备查询
     * @param
     * @return 查询结果
     */
    JsonVO<FacilityDTO> queryFacility();
    /**
     * 品质查询
     * @param
     * @return 查询结果
     */
    JsonVO<List<QualityDTO>> queryQuality();


/**
     * 车间信息查询
     * @param
     * @return 查询结果
     */
    JsonVO<List<WorkshopDTO>> queryWorkshop();

    /**
     * 排班情况分页查询
     * @param
     * @return 查询结果
     */
    JsonVO<PageDTO<PlanDTO>> queryPlan(PageQuery pageQuery);

    /**
     * 我的待办分页查询
     * @param
     * @return 查询结果
     */
    JsonVO<PageDTO<ToDoEventDTO>> queryToDoEvent(PageQuery pageQuery);
}