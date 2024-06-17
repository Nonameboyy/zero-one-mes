package com.zeroone.star.project.j5.teamsettings;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.teamsettings.AddTeamDTO;
import com.zeroone.star.project.j5.dto.teamsettings.TeamDTO;
import com.zeroone.star.project.j5.query.teamsettings.TeamQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * <p>
 * 描述：班组设置接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author interstellar
 * @version 1.0.0
 */
public interface TeamSettingsApis {
    /**
     * 获取班组列表（条件 + 分页）
     * @author interstellar
     * @param condition 查询条件
     * @return 班组列表
     */
    JsonVO<PageDTO<TeamDTO>> queryTeamList(TeamQuery condition);

    /**
     * 获取班组详情
     * @author interstellar
     * @param teamId 班组ID
     * @return 班组详情
     */
    JsonVO<TeamDTO> queryTeamDetails(Long teamId);

    /**
     * 添加班组
     * @author interstellar
     * @param condition 班组信息
     * @return 添加结果
     */
    JsonVO<Integer> addTeam(AddTeamDTO condition);

    /**
     * 修改班组
     * @author interstellar
     * @param teamDTO 班组信息
     * @return 修改结果
     */
    JsonVO<Integer> modifyTeam(TeamDTO teamDTO);

    /**
     * 删除班组（支持批量删除）
     * @author interstellar
     * @param ids 班组ID列表
     * @return 删除结果
     */
    JsonVO<Integer> removeTeam(List<Long> ids);

    /**
     * 导出班组
     * @author interstellar
     * @param condition 查询条件
     * @return 导出结果
     */
    ResponseEntity<byte[]> exportTeam(TeamQuery condition);
}
