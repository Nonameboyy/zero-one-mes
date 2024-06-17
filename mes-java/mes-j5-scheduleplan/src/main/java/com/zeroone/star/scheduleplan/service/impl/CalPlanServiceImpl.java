package com.zeroone.star.scheduleplan.service.impl;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.AddPlanDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.PlanDTO;
import com.zeroone.star.project.j5.query.scheduleplan.PlanPageQuery;
import com.zeroone.star.project.j5.vo.scheduleplan.PlanListVO;
import com.zeroone.star.project.j5.vo.scheduleplan.PlanVO;
import com.zeroone.star.scheduleplan.entity.CalPlan;
import com.zeroone.star.scheduleplan.mapper.CalPlanMapper;
import com.zeroone.star.scheduleplan.service.ICalPlanService;
import org.mapstruct.Mapper;
import com.zeroone.star.project.j5.dto.scheduleplan.PlanStatusDTO;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.RequestBody;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsPlanMapper {
    /**
     * 实体类转DTO
     *
     * @param calPlan 计划do对象
     * @return 计划dto对象
     */
    PlanDTO planToPlanDTO(CalPlan calPlan);

    /**
     * 计划DTO转实体类
     *
     * @param planDTO
     * @return
     */
    CalPlan PlanDTOToplan(PlanDTO planDTO);

    CalPlan PlanStatusDTOToplan(PlanStatusDTO planDTO);

    /**
     * 计划实体类转计划详情VO
     * @param calPlan 计划实体类
     * @return PlanVO 计划详情VO
     */
    PlanVO planToPlanVO(CalPlan calPlan);

    /**
     * 计划实体类转计划列表VO
     * @param calPlan 计划实体类
     * @return PlanListVO 计划列表VO
     */
    PlanListVO planToPlanListVO(CalPlan calPlan);

    /**
     * 添加计划DTO转计划实体类
     * @param addPlanDTO
     * @return CalPlan 计划实体类
     */
    CalPlan addPlanDTOToPlan(AddPlanDTO addPlanDTO);

    /**
     * 计划DTO转计划实体类
     * @param planDTO
     * @return CalPlan 计划实体类
     */
    CalPlan PlanDTOToPlan(PlanDTO planDTO);
}
/**
 * <p>
 * 排班计划表 服务实现类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
@Service
public class CalPlanServiceImpl extends ServiceImpl<CalPlanMapper, CalPlan> implements ICalPlanService {

    @Resource
    MsPlanMapper msPlanMapper;

    @Override
    public PageDTO<PlanListVO> queryPlanList(PlanPageQuery condition) {
        //1.构建分页对象
        Page<CalPlan> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        //2.构建查询条件
        LambdaQueryWrapper<CalPlan> wrapper = new LambdaQueryWrapper<>();
        wrapper
                .like(condition.getPlanCode() != null,CalPlan::getPlanCode,condition.getPlanCode())
                .like(condition.getPlanName() != null,CalPlan::getPlanName,condition.getPlanName())
                .eq(condition.getCalendarType()!= null, CalPlan::getCalendarType,condition.getCalendarType())
                .ge(condition.getStartDate() != null, CalPlan::getStartDate, condition.getStartDate())
                .le(condition.getEndDate() != null, CalPlan::getEndDate, condition.getEndDate());
        //3.执行分页查询
        Page<CalPlan> calPlanPage = baseMapper.selectPage(page, wrapper);
        //转为PlanListVO
        return PageDTO.create(calPlanPage,msPlanMapper::planToPlanListVO);
    }

    @Override
    public PlanVO queryPlanDetails(Long planId) {
        CalPlan calPlan = baseMapper.selectById(planId);
        return msPlanMapper.planToPlanVO(calPlan);
    }


    @Override
    public boolean addPlan(AddPlanDTO condition) {
        CalPlan plan = msPlanMapper.addPlanDTOToPlan(condition);
        return baseMapper.insert(plan) > 0;
    }

    @Override
    public boolean modifyPlan(PlanDTO planDTO) {
        CalPlan calPlan = baseMapper.selectById(planDTO.getPlanId());
        if(calPlan == null){
            return false;
        }
        CalPlan plan = msPlanMapper.PlanDTOToPlan(planDTO);
        int rows = baseMapper.updateById(plan);
        return rows > 0;
    }

    @Resource
    EasyExcelComponent excel;
    /**
     * 删除排班计划(可批量删除)
     *
     * @param rems 删除数据的id集合
     * @return
     */
    @Override
    public boolean removeSchPlan(List<Long> rems) {
        return baseMapper.deleteBatchIds(rems) > 0;
    }

    @Override
    public boolean modifySchPlanStatus(PlanStatusDTO condition) {
        //1.查询当前数据是否存在
        CalPlan modifyPlan = baseMapper.selectById(condition.getPlanId());
        //2.数据不存在,修改失败,返回false
        if (modifyPlan == null) {
            return false;
        }
        //3.存在则执行修改操作---将DTO转为DO
        CalPlan calPlan = msPlanMapper.PlanStatusDTOToplan(condition);

        return baseMapper.updateById(calPlan) > 0;
    }

    @Override
    public ResponseEntity<byte[]> exportSchPlan(List<Long> ids) throws IOException {
        //数据列表
        List<CalPlan> planlist = new ArrayList<>();
        //查询封装数据
        for (Long id : ids) {
            CalPlan plan = baseMapper.selectById(id);
            if (plan != null) {
                planlist.add(plan);
            }
        }
        //如果导出后没有数据->返回一个404 Not Found的HTTP响应
        if (planlist.isEmpty()) {
            return ResponseEntity.notFound().build();
        }
        //输出流，用于将数据写入到一个字节数组中,捕获 EasyExcel 导出操作生成的Excel文件的字节数据
        ByteArrayOutputStream out=new ByteArrayOutputStream();
        excel.export("计划列表",out,CalPlan.class, planlist);
        //获取字节数据
        byte[] bytes=out.toByteArray();
        out.close();

        //构建响应头
        HttpHeaders header = new HttpHeaders();
        String filename = "scheduleplans-" + DateTime.now().toString("yyyyMMddHHmmss") + ".xlsx";
        //指定响应体应该如何被处理,"attachment" 表示响应体应该被下载为一个文件
        header.setContentDispositionFormData("attachment", filename);
        // 设置响应头，指示响应体是一个二进制流，通常用于文件下载。
        header.setContentType(MediaType.APPLICATION_OCTET_STREAM);

        //响应文件给客户端
        return new ResponseEntity<>(bytes, header, HttpStatus.CREATED);

   /*     try (ByteArrayOutputStream os = new ByteArrayOutputStream();) {
            EasyExcelComponent easyExcelComponent = new EasyExcelComponent();
            //使用easyExcelComponent的export方法将clientList中的数据导出到输出流中
            easyExcelComponent.export("计划列表", os, CalPlan.class, planlist);
            byte[] bytes = os.toByteArray();




        } catch (IOException e) {
            // 记录日志并返回错误信息
            log.error("导出Excel文件时发生错误", e);
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR)
                    .body(("导出Excel文件时发生错误：" + e.getMessage()).getBytes());
        }*/
    }
}
