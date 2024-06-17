package com.zeroone.star.teamsettings.service.impl;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.teamsettings.AddTeamDTO;
import com.zeroone.star.project.j5.dto.teamsettings.TeamDTO;
import com.zeroone.star.project.j5.query.teamsettings.TeamQuery;
import com.zeroone.star.teamsettings.entity.CalTeam;
import com.zeroone.star.teamsettings.mapper.CalTeamMapper;
import com.zeroone.star.teamsettings.service.ICalTeamService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsTeamMapper {
    /**
     * 班组实体类转DTO
     * @param calTeam 班组实体类
     * @return 班组DTO
     */
    TeamDTO teamToTeamDTO(CalTeam calTeam);

    /**
     * 班组DTO转实体类
     * @param teamDTO 班组DTO
     * @return 班组实体类
     */
    CalTeam teamDTOToTeam(TeamDTO teamDTO);

    /**
     * 添加班组DTO转实体类
     * @param addTeamDTO
     * @return
     */
    CalTeam addTeamDTOToTeam(AddTeamDTO addTeamDTO);
}

/**
 * <p>
 * 班组表 服务实现类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
@Service
public class CalTeamServiceImpl extends ServiceImpl<CalTeamMapper, CalTeam> implements ICalTeamService {
    @Autowired
    private EasyExcelComponent easyExcelComponent;

    @Override
    public boolean removeTeam(List<Long> ids) {
        return baseMapper.deleteBatchIds(ids) > 0;
    }

    @Resource
    MsTeamMapper msTeamMapper;


    @Override
    public PageDTO<TeamDTO> listAll(TeamQuery condition) {
        // 构建分页对象
        Page<CalTeam> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        // 构建查询条件
        QueryWrapper<CalTeam> wrapper = new QueryWrapper<>();
        wrapper.lambda()
                .like(condition.getTeamCode() != null, CalTeam::getTeamCode, condition.getTeamCode())
                .like(condition.getTeamName() != null, CalTeam::getTeamName, condition.getTeamName())
                .like(condition.getCalendarType() != null, CalTeam::getCalendarType, condition.getCalendarType());
        // 执行分页查询
        Page<CalTeam> result = baseMapper.selectPage(page, wrapper);

        return PageDTO.create(result, msTeamMapper::teamToTeamDTO);
    }

    @Override
    public TeamDTO queryTeamDetails(Long teamId) {
        // 将数据查询出
        CalTeam calTeam = baseMapper.selectById(teamId);
        // 转为DTO并返回
        return msTeamMapper.teamToTeamDTO(calTeam);
    }

    @Override
    public boolean addTeam(AddTeamDTO condition) {
        // DTO 转为 DO
        CalTeam calTeam = msTeamMapper.addTeamDTOToTeam(condition);

        // 保存到数据库并返回结果
        return baseMapper.insert(calTeam) > 0;
    }

    @Override
    public boolean modifyTeam(TeamDTO condition) {
        // 查询是否存在
        CalTeam existCalTeam = baseMapper.selectById(condition.getTeamId());
        if (existCalTeam == null) {
            return false;
        }

        // DTO 转 DO
        CalTeam calTeam = msTeamMapper.teamDTOToTeam(condition);

        // 更新数据库信息
        return baseMapper.updateById(calTeam) > 0;
    }

    @Override
    public ResponseEntity<byte[]> queryTeamListByExcel(TeamQuery condition) {
        // 构建分页对象
        Page<CalTeam> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        // 构建查询条件
        QueryWrapper<CalTeam> wrapper = new QueryWrapper<>();
        wrapper.lambda()
                .like(condition.getTeamCode() != null, CalTeam::getTeamCode, condition.getTeamCode())
                .like(condition.getTeamName() != null, CalTeam::getTeamName, condition.getTeamName())
                .like(condition.getCalendarType() != null, CalTeam::getCalendarType, condition.getCalendarType());
        // 执行分页查询
        Page<CalTeam> result = baseMapper.selectPage(page, wrapper);

        // 讲DO转为DTO，然后存到列表中
        List<TeamDTO> teamDTOList = new ArrayList<>();
        result.getRecords().forEach(calTeam -> {
            teamDTOList.add(msTeamMapper.teamToTeamDTO(calTeam));
        });

        // 判断列表是否为空
        if (teamDTOList.isEmpty()) {
            return ResponseEntity.status(HttpStatus.NO_CONTENT).body("没有可导出的班组设置".getBytes());
        }

        // 输出流对象
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        try {
            easyExcelComponent.export("班组设置列表", out, TeamDTO.class, teamDTOList);
        } catch(IOException e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("导出失败".getBytes());
        }
        // 获取字节数据
        byte[] bytes = out.toByteArray();
        try {
            out.close();
        } catch (IOException e) {
            // 处理关闭流时的异常
            e.printStackTrace();
        }
        // 设置响应头
        HttpHeaders headers = new HttpHeaders();
        String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        // 响应文件给客户端
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }
}
