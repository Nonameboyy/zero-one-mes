package com.zeroone.star.syshome.controller;

import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.syshome.SysHomeApis;
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
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.syshome.service.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;


/**
 * <p>
 * 描述：系统首页
 * </p>
 * @author twelve
 * @version 1.0.0
 */
@RestController
@RequestMapping("syshome")
@Api(tags = "系统首页")
public class SysHomeController implements SysHomeApis {

    @Resource
    IProductionService productionService;

    @GetMapping("query-production-table")
    @ApiOperation(value = "生产进度列表")
    @Override
    public JsonVO<PageDTO<ProductionDTO>> queryProduction(EPageQuery condition){
        return JsonVO.success(productionService.listProduction(condition));
    }


    @Resource
    IRepertoryService repertoryService;

    @GetMapping("query-repertory/{warehouseId}")
    @ApiOperation(value = "库存统计饼图")
    @ApiImplicitParams({
            @ApiImplicitParam(name = "warehouseId", value = "仓库编号", dataType = "Long", paramType = "query", required = true,example = "210")
    })
    @Override
    public JsonVO<List<RepertoryDTO>> queryRepertory(@PathVariable Long warehouseId) {
        return JsonVO.success(repertoryService.getRepertory(warehouseId));
    }


    @Resource
    IFacilityService facilityService;

    @GetMapping("query-facility")
    @ApiOperation(value = "设备信息表")
    @Override
    public JsonVO<FacilityDTO> queryFacility() {
        return JsonVO.success(facilityService.getFacility());
    }


    @Resource
    IQualityService iQualityService;


    @GetMapping("query-quality")
    @ApiOperation(value = "质量统计饼图")
    @Override
    public JsonVO<List<QualityDTO>> queryQuality() {
        return JsonVO.success(iQualityService.getQuality());
    }






    @Resource
    IMdWorkshopService iMdWorkshopService;

    @GetMapping("query-workshop")
    @ApiOperation(value = "查询车间展示信息")
    @Override
    public JsonVO<List<WorkshopDTO>> queryWorkshop() {
        return JsonVO.success(iMdWorkshopService.listWorkshop());
    }


    @Resource
    ICalTeamMemberService iCalTeamMemberService;
    @GetMapping("query-plan")
    @ApiOperation(value = "查询排班情况信息")
    @Override
    public JsonVO<PageDTO<PlanDTO>> queryPlan(PageQuery pageQuery) {
        return JsonVO.success(iCalTeamMemberService.listPlan(pageQuery));
    }


    @Resource
    UserHolder userHolder;
    @Resource
    IDvRepairService iDvRepairService;
    @GetMapping("query-toDoEvent")
    @ApiOperation(value = "查询我的待办信息")
    @Override
    public JsonVO<PageDTO<ToDoEventDTO>> queryToDoEvent(PageQuery pageQuery) {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        } else {
            return JsonVO.success(iDvRepairService.selectToDoEvent(pageQuery, currentUser.getUsername()));
        }
    }
}
