package com.zeroone.star.warehousemanagement.service.impl;

import com.zeroone.star.project.dto.j4.warehousemanagement.rtsalseLine.RtSalseLineDTO;
import com.zeroone.star.warehousemanagement.entity.WmRtSalseLine;
import com.zeroone.star.warehousemanagement.mapper.WmRtSalseLineMapper;
import com.zeroone.star.warehousemanagement.service.IWmRtSalseLineService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.BeanUtils;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 产品销售退货行表 服务实现类
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-29
 */
@Service
public class WmRtSalseLineServiceImpl extends ServiceImpl<WmRtSalseLineMapper, WmRtSalseLine> implements IWmRtSalseLineService {

    @Resource
    private WmRtSalseLineMapper wmRtSalseLineMapper;
    /**
     * 查询产品销售退货行
     *
     * @param lineId 产品销售退货行主键
     * @return 产品销售退货行
     */
    @Override
    public WmRtSalseLine selectWmRtSalseLineByLineId(Long lineId)
    {
        return wmRtSalseLineMapper.selectWmRtSalseLineByLineId(lineId);
    }

    /**
     * 查询产品销售退货行列表
     *
     * @param wmRtSalseLine 产品销售退货行
     * @return 产品销售退货行
     */
    @Override
    public List<WmRtSalseLine> selectWmRtSalseLineList(WmRtSalseLine wmRtSalseLine)
    {
        return wmRtSalseLineMapper.selectWmRtSalseLineList(wmRtSalseLine);
    }

    /**
     * 新增产品销售退货行
     *
     * @param rtSalseLineDTO 产品销售退货行
     * @return 结果
     */
    @Override
    public int insertWmRtSalseLine(RtSalseLineDTO rtSalseLineDTO) {
        rtSalseLineDTO.setCreateTime(LocalDateTime.now());
        WmRtSalseLine wmRtSalseLine = new WmRtSalseLine();
        BeanUtils.copyProperties(rtSalseLineDTO,wmRtSalseLine);
        return wmRtSalseLineMapper.insertWmRtSalseLine(wmRtSalseLine);
    }

    /**
     * 修改产品销售退货行
     *
     * @param rtSalseLineDTO 产品销售退货行
     * @return 结果
     */
    @Override
    public int updateWmRtSalseLine(RtSalseLineDTO rtSalseLineDTO)
    {
        rtSalseLineDTO.setUpdateTime(LocalDateTime.now());
        WmRtSalseLine wmRtSalseLine = new WmRtSalseLine();
        BeanUtils.copyProperties(rtSalseLineDTO,wmRtSalseLine);
        return wmRtSalseLineMapper.updateWmRtSalseLine(wmRtSalseLine);
    }

    /**
     * 批量删除产品销售退货行
     *
     * @param lineIds 需要删除的产品销售退货行主键
     * @return 结果
     */
    @Override
    public int deleteWmRtSalseLineByLineIds(Long[] lineIds)
    {
        return wmRtSalseLineMapper.deleteWmRtSalseLineByLineIds(lineIds);
    }

    /**
     * 删除产品销售退货行信息
     *
     * @param lineId 产品销售退货行主键
     * @return 结果
     */
    @Override
    public int deleteWmRtSalseLineByLineId(Long lineId)
    {
        return wmRtSalseLineMapper.deleteWmRtSalseLineByLineId(lineId);
    }

    @Override
    public int deleteByRtId(Long rtId) {
        return wmRtSalseLineMapper.deleteByRtSalseIds(rtId);
    }
}
