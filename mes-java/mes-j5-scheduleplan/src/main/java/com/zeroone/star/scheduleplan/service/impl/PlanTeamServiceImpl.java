package com.zeroone.star.scheduleplan.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.planteam.AddPlanTeamDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.planteam.PlanTeamDTO;
import com.zeroone.star.project.j5.query.scheduleplan.planteam.AddPlanTeamQuery;
import com.zeroone.star.project.j5.query.scheduleplan.planteam.PlanTeamQuery;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.scheduleplan.entity.CalPlanTeam;
import com.zeroone.star.scheduleplan.entity.CalTeam;
import com.zeroone.star.scheduleplan.mapper.CalPlanTeamMapper;
import com.zeroone.star.scheduleplan.service.ICalPlanService;
import com.zeroone.star.scheduleplan.service.ICalTeamService;
import com.zeroone.star.scheduleplan.service.IPlanTeamService;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：Sample对应MapStructMapper接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
interface MsCalPlanTeamMapper {
    /**
     * 将 SampleDO 转换成 SampleDTO
     * @param calPlanTeam do对象
     * @return 转换后的结果
     */
    PlanTeamDTO calPlanTeamToPlanTeamDTO(CalPlanTeam calPlanTeam);

    /**
     * 将 AddPlanTeamDTO 转换成 CalPlanTeam
     * @param addPlanTeamDTO dto对象
     * @return 转换后的结果
     */
    CalPlanTeam addPlanTeamDTOToCalPlanTeam(AddPlanTeamDTO addPlanTeamDTO);
}

/**
 * <p>
 * 演示示例表 服务实现类
 * </p>
 * @author awei
 * @since 2024-05-10
 */
@Service
public class PlanTeamServiceImpl extends ServiceImpl<CalPlanTeamMapper, CalPlanTeam> implements IPlanTeamService {

    @Resource
    private MsCalPlanTeamMapper msCalPlanTeamMapper;

    private final ICalTeamService calTeamService;
    private final ICalPlanService calPlanService;

    @Autowired
    public PlanTeamServiceImpl(ICalTeamService calTeamService, ICalPlanService calPlanService) {
        this.calTeamService = calTeamService;
        this.calPlanService = calPlanService;
    }

    @Override
    public PageDTO<PlanTeamDTO> listAll(PlanTeamQuery query) {
        // 构建分页查询对象
        Page<CalPlanTeam> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<CalPlanTeam> wrapper = new QueryWrapper<>();
        wrapper.eq("plan_id", query.getPlanId());
        // 执行分页查询
        Page<CalPlanTeam> result = baseMapper.selectPage(page, wrapper);
        // 结果转换成DTO
        return PageDTO.create(result, src -> msCalPlanTeamMapper.calPlanTeamToPlanTeamDTO(src));
    }

    /**
     * 通过teamId查询Team表获取Team信息,绑定对应PlanId,创建AddPlanTeamDTO
     * @param addPlanTeamQueries 查询条件
     * @return 结果
     */
    List<AddPlanTeamDTO> creatTeamPlanWithQuery(List<AddPlanTeamQuery> addPlanTeamQueries){
        // 单独取出TeamId List
        List<Long> teamIds = addPlanTeamQueries.stream()
                .map(AddPlanTeamQuery::getTeamId)
                .collect(Collectors.toList());

        // 通过teamIds查询Team表获取CalTeam Map
         HashMap<Long, CalTeam> calTeamMap = calTeamService.getCalTeamMap(teamIds);

        // 通过Team信息绑定对应PlanId,创建AddPlanTeamDTO List
        return addPlanTeamQueries.stream()
                .map(addPlanTeamQuery -> {
                    // 如果PlanId不存在对应的Plan信息,抛出异常
                    if (calPlanService.getById(addPlanTeamQuery.getPlanId()) == null){
                        throw new RuntimeException("PlanId not found in the database: " + addPlanTeamQuery.getPlanId());
                    }

                    // 通过Team信息绑定对应PlanId,创建AddPlanTeamDTO
                    AddPlanTeamDTO addPlanTeamDTO = new AddPlanTeamDTO();
                    addPlanTeamDTO.setPlanId(addPlanTeamQuery.getPlanId());
                    addPlanTeamDTO.setTeamId(addPlanTeamQuery.getTeamId());
                    addPlanTeamDTO.setTeamCode(calTeamMap.get(addPlanTeamQuery.getTeamId()).getTeamCode());
                    addPlanTeamDTO.setTeamName(calTeamMap.get(addPlanTeamQuery.getTeamId()).getTeamName());
                    addPlanTeamDTO.setCreateTime(LocalDateTime.now());
                    return addPlanTeamDTO;
                })
                .collect(Collectors.toList());
    }
    @Transactional(
            rollbackFor = {Exception.class}
    )
    @Override
    public Integer addPlanTeam(List<AddPlanTeamQuery> addPlanTeamQueries) {
        // 判断数据库中是否已经存在对应的记录(TeamId与绑定的PlanId)
        QueryWrapper<CalPlanTeam> queryWrapper = new QueryWrapper<>();
        for (AddPlanTeamQuery query : addPlanTeamQueries) {
            queryWrapper.or().eq("team_id", query.getTeamId()).eq("plan_id", query.getPlanId());
        }
        List<CalPlanTeam> list = baseMapper.selectList(queryWrapper);
        if (!list.isEmpty()) {
            String existingPairs = list.stream()
                    .map(calPlanTeam -> "team_id: " + calPlanTeam.getTeamId() + ", plan_id: " + calPlanTeam.getPlanId())
                    .collect(Collectors.joining("; "));
            throw new RuntimeException("Existing team_id-plan_id pairs found: " + existingPairs);
        }

        // 通过teamId查询Team表获取Team信息,绑定对应PlanId,创建AddPlanTeamDTO
        List<AddPlanTeamDTO> addPlanTeamDTOs =creatTeamPlanWithQuery(addPlanTeamQueries);

        List<CalPlanTeam> addlist = addPlanTeamDTOs.stream()
                .map(msCalPlanTeamMapper::addPlanTeamDTOToCalPlanTeam)
                .collect(Collectors.toList());
        boolean res = saveBatch(addlist, addlist.size());
        return res ? 1 : 0;
    }

    @Override
    public Integer deletePlanTeam(Long recordId) {
        int res = baseMapper.deleteById(recordId);
        return res > 0 ? 1 : 0;
    }
}
