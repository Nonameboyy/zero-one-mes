package com.zeroone.star.warehousemanagement.service;

import com.zeroone.star.project.dto.j4.warehousemanagement.rtsalse.RtSalsesDTO;
import com.zeroone.star.warehousemanagement.entity.WmRtSalse;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 产品销售退货单表 服务类
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-29
 */
public interface IWmRtSalseService extends IService<WmRtSalse> {

    /*
    * 删除销售退货单
    * */
    Long deleteByIds(List<Long> rtSalseIds);

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
     * @param rtSalsesDTO
     */
    public String checkUnique(RtSalsesDTO rtSalsesDTO);

    /**
     * 新增产品销售退货单
     *
     * @param rtSalsesDTO 产品销售退货单
     * @return 结果
     */
    public int insertWmRtSalse(RtSalsesDTO rtSalsesDTO);

    /**
     * 修改产品销售退货单
     *
     * @param rtSalsesDTO 产品销售退货单
     * @return 结果
     */
    public int updateWmRtSalse(RtSalsesDTO rtSalsesDTO);

    /**
     * 删除产品销售退货单
     *
     * @param rtIds 退货单id
     * @return 结果
     */
    String removes(List<Long> rtIds);
}
