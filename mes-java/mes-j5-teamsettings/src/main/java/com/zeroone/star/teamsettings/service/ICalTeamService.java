package com.zeroone.star.teamsettings.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.teamsettings.AddTeamDTO;
import com.zeroone.star.project.j5.dto.teamsettings.TeamDTO;
import com.zeroone.star.project.j5.query.teamsettings.TeamQuery;
import com.zeroone.star.teamsettings.entity.CalTeam;
import com.baomidou.mybatisplus.extension.service.IService;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * <p>
 * 班组表 服务类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
public interface ICalTeamService extends IService<CalTeam> {
    /**
     * author interstellar
     * @param condition 条件
     * @return 分页数据
     */
     PageDTO<TeamDTO> listAll(TeamQuery condition);

    /**
     * author interstellar
     * @param teamId 班组id
     * @return 详情
     */
    TeamDTO queryTeamDetails(Long teamId);

    /**
     * author interstellar
     * @param condition 条件
     * @return 添加结果
     */
     boolean addTeam(AddTeamDTO condition);

    /**
     * author interstellar
     * @param condition 条件
     * @return 修改结果
     */
     boolean modifyTeam(TeamDTO condition);

    /**
     * author interstellar
     * @param ids 条件
     * @return 删除结果
     */
     boolean removeTeam(List<Long> ids);

    /**
     * author interstellar
     * @param condition 条件
     * @return 导出结果
     */
     ResponseEntity<byte[]> queryTeamListByExcel(TeamQuery condition);

}
