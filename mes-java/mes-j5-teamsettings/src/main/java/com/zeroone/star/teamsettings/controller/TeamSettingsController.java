package com.zeroone.star.teamsettings.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.teamsettings.AddTeamDTO;
import com.zeroone.star.project.j5.dto.teamsettings.TeamDTO;
import com.zeroone.star.project.j5.query.teamsettings.TeamQuery;
import com.zeroone.star.project.j5.teamsettings.TeamSettingsApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.teamsettings.service.ICalTeamService;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import io.swagger.annotations.Api;

import javax.annotation.Resource;
import javax.validation.constraints.Min;
import java.util.List;

/**
 * <p>
 * 描述：班组设置控制器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author interstellar
 * @version 1.0.0
 */
@RestController
@RequestMapping("sch-manage/team-settings")
@Api(tags = "班组设置接口")
@Validated
public class TeamSettingsController implements TeamSettingsApis {
    @Resource
    ICalTeamService calTeamService;
    @ApiOperation(value = "获取班组列表（条件 + 分页）")
    @GetMapping("query-all")
    @Override
    public JsonVO<PageDTO<TeamDTO>> queryTeamList(@Validated TeamQuery condition) {
        PageDTO<TeamDTO> teams = calTeamService.listAll(condition);
        if (teams != null) {
            return JsonVO.success(teams);
        }
        return JsonVO.fail(null);
    }

    @Override
    public JsonVO<TeamDTO> queryTeamDetails(Long teamId) {
        TeamDTO teamDetails = calTeamService.queryTeamDetails(teamId);
        return teamDetails != null ? JsonVO.success(teamDetails) : JsonVO.fail(null);
    }

    @ApiOperation(value = "获取班组详情")
    @GetMapping("query-by-id")
    public JsonVO<TeamDTO> queryTeamDetailsValidated(@Min(value = 1, message = "id最小值为1") @RequestParam Long id) {
        return queryTeamDetails(id);
    }

    @ApiOperation(value = "添加班组")
    @PostMapping("add-team")
    @Override
    public JsonVO<Integer> addTeam(@Validated AddTeamDTO condition) {
        return calTeamService.addTeam(condition) ? JsonVO.success(1) : JsonVO.fail(0);
    }

    @ApiOperation(value = "修改班组")
    @PutMapping("modify-team")
    @Override
    public JsonVO<Integer> modifyTeam(@Validated TeamDTO teamDTO) {
        return calTeamService.modifyTeam(teamDTO) ? JsonVO.success(1) : JsonVO.fail(0);
    }

    @ApiOperation(value = "删除班组")
    @DeleteMapping("delete-team")
    @Override
    public JsonVO<Integer> removeTeam(@RequestBody List<Long> ids) {
        return calTeamService.removeTeam(ids) ? JsonVO.success(1) : JsonVO.fail(0);
    }

    @ApiOperation(value = "导出班组")
    @GetMapping(value = "export-team", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> exportTeam(@Validated TeamQuery condition) {
        return calTeamService.queryTeamListByExcel(condition);
    }
}
