package com.zeroone.star.scheduleplan.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.shiftplan.ShiftPlanAddDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.shiftplan.ShiftPlanDTO;
import com.zeroone.star.project.j5.dto.scheduleplan.shiftplan.ShiftPlanModifyDTO;
import com.zeroone.star.project.j5.query.scheduleplan.shiftplan.ShiftPlanQuery;
import com.zeroone.star.scheduleplan.entity.CalPlan;
import com.zeroone.star.scheduleplan.entity.CalShift;
import com.zeroone.star.scheduleplan.mapper.CalPlanMapper;
import com.zeroone.star.scheduleplan.mapper.CalShiftMapper;
import com.zeroone.star.scheduleplan.service.ICalShiftService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 计划班次表 服务实现类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */

@Mapper(componentModel = "spring")
interface msCalShiftPlanMapper{
    /**
     * 添加班次DTO转实体类
     * @param shiftPlanAddDTO 添加班次DTO
     * @return  班次实体类
     */
    CalShift addShiftPlanToShiftPlan(ShiftPlanAddDTO shiftPlanAddDTO);

    /**
     * 修改班次DTO转实体类
     * @param shiftPlanModifyDTO 修改班次DTO
     * @return  班次实体类
     */
    CalShift modifyShiftPlanToShiftPlan(ShiftPlanModifyDTO shiftPlanModifyDTO);

    /**
     * 班次实体类转DTO
     * @param shiftPlan 班次实体类
     * @return  ShiftPlanDTO班次DTO
     */
    ShiftPlanDTO shiftPlanToShiftPlanDTO(CalShift shiftPlan);
}

@Service
public class CalShiftServiceImpl extends ServiceImpl<CalShiftMapper, CalShift> implements ICalShiftService {

    @Resource
    msCalShiftPlanMapper msCalShiftPlanMapper;
    @Resource
    CalPlanMapper calPlanMapper;

    @Override
    public PageDTO<ShiftPlanDTO> queryShiftPlanByPlanId(ShiftPlanQuery shiftPlanQuery) {
        Page<CalShift> page = new Page<>(shiftPlanQuery.getPageIndex(), shiftPlanQuery.getPageSize());
        QueryWrapper<CalShift> wrapper = new QueryWrapper<>();
        wrapper.eq("plan_id", shiftPlanQuery.getPlanId());
        Page<CalShift> result = baseMapper.selectPage(page, wrapper);
        // 返回封装后的pageDTO
        return PageDTO.create(result, msCalShiftPlanMapper::shiftPlanToShiftPlanDTO);
    }

    @Override
    public int addShiftPlan(ShiftPlanAddDTO shiftPlanAddDto) {
        //根据planId查找calPlan表
        CalPlan existingCalPlan = calPlanMapper.selectById(shiftPlanAddDto.getPlanId());
        //根据shiftId查找calShift表shiftList
        List<CalShift> calShiftList = baseMapper.selectList(new QueryWrapper<CalShift>().eq("plan_id", shiftPlanAddDto.getPlanId()));

        //统计calShiftList的数量
        int count = calShiftList.size();

        //1、判断查询对象是否存在
        if(existingCalPlan == null){
            throw new RuntimeException("排班计划为空，无法添加");
        }

        //查询calPlan表的shiftType
        String shiftType = existingCalPlan.getShiftType();
        System.out.println(shiftType);

        //2、判断排班计划的排班种类是否为空
        // 2.1、判断shiftType是否与count数量对应
        if(shiftType == null){
            throw new RuntimeException("排班种类为空，无法添加");
        }else if (shiftType.equals("SINGLE") && count>0){
            throw new RuntimeException("轮班方式为 白班 时只能有一个班次！");
        } else if (shiftType.equals("SHIFT_TWO") && count>1){
            throw new RuntimeException("轮班方式为 两班倒 时只能有两个班次！");
        } else if (shiftType.equals("SHIFT_THREE") && count>2){
            throw new RuntimeException("轮班方式为 三班倒 时只能有三个班次！");
        }

        //3、判断添加的orderNum是否在对应calPlan下已经存在
        for(CalShift calShift : calShiftList){
            if(calShift.getOrderNum().equals(shiftPlanAddDto.getOrderNum())) {
                throw new RuntimeException("班次序号已存在，请更换编号");
            }
        }

        //执行添加数据
        CalShift calShift = msCalShiftPlanMapper.addShiftPlanToShiftPlan(shiftPlanAddDto);

//        更新planCount数量
//        if(updateCalPlanShiftCount(calShift.getPlanId()) < 1){
//            throw new RuntimeException("更新班次数量失败");
//        }

        //调用更新
        return baseMapper.insert(calShift);
    }

    @Override
    public int modifyShiftPlan(ShiftPlanModifyDTO shiftPlanModifyDto) {
        //修改数据
        CalShift calShift = msCalShiftPlanMapper.modifyShiftPlanToShiftPlan(shiftPlanModifyDto);
        UpdateWrapper<CalShift> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("shift_id", calShift.getShiftId())
                .eq("plan_id", calShift.getPlanId());
        //返回修改的行数
        return baseMapper.update(calShift, updateWrapper);
    }

    @Override
    public int removeShiftPlan(List<Long> shiftIds) {
        int deletedRow = 0;
        for(Long shiftId : shiftIds){
            int changeRow = baseMapper.delete(new QueryWrapper<CalShift>().eq("shift_id", shiftId));
            if(changeRow < 1){
                throw new RuntimeException("删除失败");
            }
            deletedRow += changeRow;
        }
        return deletedRow;
    }

}
