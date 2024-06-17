package com.zeroone.star.scheduleplan.controller.shift;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.shiftplan.ShiftPlanAddDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.shiftplan.ShiftPlanDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.shiftplan.ShiftPlanModifyDTO;
import com.zeroone.star.project.j5.query.scheduleplan.shiftplan.ShiftPlanQuery;
import com.zeroone.star.project.j5.scheduleplan.shift.ShiftApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.scheduleplan.service.ICalShiftService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 描述：班次控制器
 * </p>
 * @author interstellar
 * @version 1.0.0
 */
@RestController
@RequestMapping("sch-manage/sch-plan/shift")
@Api(tags = "班次接口")
public class ShiftController implements ShiftApis {
    @Resource
    ICalShiftService calShiftService;
    @GetMapping("/list")
    @ApiOperation("获取班次列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<ShiftPlanDTO>> queryShiftPlanByPlanId(@Validated ShiftPlanQuery shiftPlanQuery) {
        // 查询班次列表业务处理
        PageDTO<ShiftPlanDTO> pageDTO = calShiftService.queryShiftPlanByPlanId(shiftPlanQuery);
        if(pageDTO != null){
            return JsonVO.success(pageDTO);
        }
        return JsonVO.fail(null);
    }

    @PutMapping("/modify")
    @ApiOperation("修改班次")
    @Override
    public JsonVO<Integer> modifyShiftPlan(@Validated @RequestBody ShiftPlanModifyDTO shiftPlanModifyDto) {
        //修改班次业务
        int updateRow = calShiftService.modifyShiftPlan(shiftPlanModifyDto);
        //业务层返回修改信息
        return updateRow > 0 ? JsonVO.success(updateRow) : JsonVO.fail(null);
    }

    @DeleteMapping("/remove/{shiftIds}")
    @ApiOperation("删除班次（支持批量删除）")
    @Override
    public JsonVO<Integer> removeShiftPlan(@PathVariable List<Long> shiftIds) {
        int deleteRow = calShiftService.removeShiftPlan(shiftIds);
        //返回操作结果
        return deleteRow > 0 ? JsonVO.success(deleteRow) : JsonVO.fail(null);
    }

    @PostMapping("/add")
    @ApiOperation("添加班次")
    @Override
    public JsonVO<Integer> addShiftPlan(@Validated @RequestBody ShiftPlanAddDTO shiftPlanAddDto) {
        //执行新增业务处理操作
        int addRow = calShiftService.addShiftPlan(shiftPlanAddDto);

        //返回操作结果
        return addRow > 0 ? JsonVO.success(addRow) : JsonVO.fail(null);
        }
}
