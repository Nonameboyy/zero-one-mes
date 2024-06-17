package com.zeroone.star.warehousemanagement.mapper;

import com.zeroone.star.warehousemanagement.entity.WmRtSalseLine;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 产品销售退货行表 Mapper 接口
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-29
 */
@Mapper
public interface WmRtSalseLineMapper extends BaseMapper<WmRtSalseLine> {

    /**
     * 根据退货单ID删除所有行
     * @param rtSalseId
     * @return
     */
    @Delete("delete from wm_rt_salse_line where rt_id = #{rtSalseId}")
    int deleteByRtSalseIds(Long rtSalseId);
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
     * @param wmRtSalseLine 产品销售退货行
     * @return 结果
     */
    public int insertWmRtSalseLine(WmRtSalseLine wmRtSalseLine);

    /**
     * 修改产品销售退货行
     *
     * @param wmRtSalseLine 产品销售退货行
     * @return 结果
     */
    public int updateWmRtSalseLine(WmRtSalseLine wmRtSalseLine);

    /**
     * 删除产品销售退货行
     *
     * @param lineId 产品销售退货行主键
     * @return 结果
     */
    public int deleteWmRtSalseLineByLineId(Long lineId);

    /**
     * 批量删除产品销售退货行
     *
     * @param lineIds 需要删除的数据主键集合
     * @return 结果
     */
    public int deleteWmRtSalseLineByLineIds(Long[] lineIds);

}
