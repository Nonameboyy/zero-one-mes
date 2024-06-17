package com.zeroone.star.scheduleplan.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.scheduleplan.entity.CalTeam;
import com.zeroone.star.scheduleplan.mapper.CalTeamMapper;
import com.zeroone.star.scheduleplan.service.ICalTeamService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.List;

/**
 * <p>
 * 班组表 服务实现类
 * </p>
 *
 * @author linglan
 * @since 2024-05-22
 */
@Service
public class CalTeamServiceImpl extends ServiceImpl<CalTeamMapper, CalTeam> implements ICalTeamService {

    @Override
    public HashMap<Long, CalTeam> getCalTeamMap(List<Long> teamIds) {
        // 计算teamIds去重后数目
        long distinctCount = teamIds.stream().distinct().count();
        // 创建查询条件
        QueryWrapper<CalTeam> queryWrapper = new QueryWrapper<>();
        queryWrapper.in("team_id", teamIds);

        // 从数据库中获取CalTeam对象的列表
        List<CalTeam> calTeams = baseMapper.selectList(queryWrapper);

        // 将列表转换为HashMap
        HashMap<Long, CalTeam> calTeamMap = new HashMap<>(Math.max((int) (distinctCount / .75f) + 1, 16));
        for (CalTeam calTeam : calTeams) {
            calTeamMap.put(calTeam.getTeamId(), calTeam);
        }

        // 检查是否所有的teamId都在calTeamMap中
        if (calTeamMap.size() != distinctCount) {
            throw new RuntimeException("Not all teamIds could be found in the database: "+"find count: "+calTeamMap.size()+", teamIds(distinct) count: "+distinctCount);
        }

        return calTeamMap;
    }
}
