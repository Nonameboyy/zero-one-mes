package com.zeroone.star.warehousemanagement.service;

import com.zeroone.star.project.dto.j4.warehousemanagement.rtsalseLine.RtSalseLineDTO;
import com.zeroone.star.warehousemanagement.entity.WmRtSalseLine;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 产品销售退货行表 服务类
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-29
 */
public interface IWmRtSalseLineService extends IService<WmRtSalseLine> {
    /**
     * 查询产品销售退货行
     *
     * @param lineId 产品销售退货行主键
     * @return 产品销售退货行
     */
    public WmRtSalseLine selectWmRtSalseLineByLineId(Long lineId);

    /**
     * 查询产品销售退货行列表
     *
     * @param wmRtSalseLine 产品销售退货行
     * @return 产品销售退货行集合
     */
    public List<WmRtSalseLine> selectWmRtSalseLineList(WmRtSalseLine wmRtSalseLine);

    /**
     * 新增产品销售退货行
     *
     * @param rtSalseLineDTO 产品销售退货行
     * @return 结果
     */
    public int insertWmRtSalseLine(RtSalseLineDTO rtSalseLineDTO);

    /**
     * 修改产品销售退货行
     *
     * @param rtSalseLineDTO 产品销售退货行
     * @return 结果
     */
    public int updateWmRtSalseLine(RtSalseLineDTO rtSalseLineDTO);

    /**
     * 批量删除产品销售退货行
     *
     * @param lineIds 需要删除的产品销售退货行主键集合
     * @return 结果
     */
    public int deleteWmRtSalseLineByLineIds(Long[] lineIds);

    /**
     * 删除产品销售退货行信息
     *
     * @param lineId 产品销售退货行主键
     * @return 结果
     */
    public int deleteWmRtSalseLineByLineId(Long lineId);

    /**
     * 根据退货单ID删除所有行
     * @param rtId
     * @return
     */
    public int deleteByRtId(Long rtId);
}
