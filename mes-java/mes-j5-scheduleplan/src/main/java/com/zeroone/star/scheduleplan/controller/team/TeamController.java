package com.zeroone.star.scheduleplan.controller.team;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.planteam.PlanTeamDTO;
import com.zeroone.star.project.j5.query.scheduleplan.planteam.AddPlanTeamQuery;
import com.zeroone.star.project.j5.query.scheduleplan.planteam.PlanTeamQuery;
import com.zeroone.star.project.j5.scheduleplan.team.TeamApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.scheduleplan.service.IPlanTeamService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.Min;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * <p>
 * 描述：关联班组控制器
 * </p>
 * @author linglan
 * @version 1.0.0
 */
@RestController
@RequestMapping("sch-manage/sch-plan/team")
@Api(tags = "关联班组接口")
@Validated
public class TeamController implements TeamApis {
        @Resource
        IPlanTeamService planTeamService;
        @GetMapping("/list")
        @ApiOperation("获取关联班组列表(条件+分页)")
        @Override
        public JsonVO<PageDTO<PlanTeamDTO>> queryAllPlanTeam(@Validated PlanTeamQuery condition) {
                return JsonVO.success(planTeamService.listAll(condition));
        }
        @PostMapping("/add")
        @ApiOperation("添加关联班组(支持多项添加)")
        @Override
        public JsonVO<Integer> addPlanTeam(@ApiParam(value = "Array of plan teams to add", required = true, allowMultiple = true) @RequestBody List<AddPlanTeamQuery> addPlanTeamQueries) {
                // 创建一个Set用于检查重复
                Set<AddPlanTeamQuery> set = new HashSet<>();
                for (AddPlanTeamQuery query : addPlanTeamQueries) {
                        // 尝试将元素添加到Set中，如果添加失败则表示有重复
                        if (!set.add(query)) {
                                throw new RuntimeException("Duplicate AddPlanTeamQuery found: " + query);
                        }
                }
                // 如果没有重复，继续执行原有逻辑
                Integer res = planTeamService.addPlanTeam(addPlanTeamQueries);
                return res == 1 ? JsonVO.success(res) : JsonVO.fail(res);
        }

        @Override
        public JsonVO<Integer> deletePlanTeam(Long recordId) {
                Integer res = planTeamService.deletePlanTeam(recordId);
                return res == 1 ? JsonVO.success(res) : JsonVO.create(res, 9999, "操作失败,可能是没有对应流水号(recordId)");
        }
        @DeleteMapping("/{recordId}")
        @ApiOperation("删除关联班组")
        public JsonVO<Integer> deletePlanTeamValidated(@PathVariable @Min(value = 1, message = "recordId最小为1") Long recordId) {
                return deletePlanTeam(recordId);
        }
}