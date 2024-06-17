package com.zeroone.star.scheduleplan.service;

import com.zeroone.star.scheduleplan.entity.CalTeam;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.HashMap;
import java.util.List;

/**
 * <p>
 * 班组表 服务类
 * </p>
 *
 * @author linglan
 * @since 2024-05-22
 */
public interface ICalTeamService extends IService<CalTeam> {
    /**
     * 通过teamIds查询Team表获取CalTeam Map
     * @param teamIds 班组ID
     * @return 班组Map
     */
    HashMap<Long, CalTeam> getCalTeamMap(List<Long> teamIds);
}
