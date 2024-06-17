package com.zeroone.star.warehousemanagement.mapper;

import com.zeroone.star.warehousemanagement.entity.WmRtSalse;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 产品销售退货单表 Mapper 接口
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-29
 */
@Mapper
public interface WmRtSalseMapper extends BaseMapper<WmRtSalse> {

    /**
     * 查询产品销售退货单
     *
     * @param rtId 产品销售退货单主键
     * @return 产品销售退货单
     */
    public WmRtSalse selectWmRtSalseByRtId(Long rtId);

    /**
     * 查询产品销售退货单列表
     *
     * @param wmRtSalse 产品销售退货单
     * @return 产品销售退货单集合
     */
    public List<WmRtSalse> selectWmRtSalseList(WmRtSalse wmRtSalse);

    /**
     * 检查编号唯一性
     * @return
     */
    public WmRtSalse checkUnique(WmRtSalse wmRtSalse);

    /**
     * 新增产品销售退货单
     *
     * @param wmRtSalse 产品销售退货单
     * @return 结果
     */
    public int insertWmRtSalse(WmRtSalse wmRtSalse);

    /**
     * 修改产品销售退货单
     *
     * @param wmRtSalse 产品销售退货单
     * @return 结果
     */
    public int updateWmRtSalse(WmRtSalse wmRtSalse);


    /**
     * 删除产品销售退货单
     *
     * @param rtSalseIds 产品销售退货单主键集合
     * @return 结果
     */
    Long deleteByIds(List<Long> rtSalseIds);
}
