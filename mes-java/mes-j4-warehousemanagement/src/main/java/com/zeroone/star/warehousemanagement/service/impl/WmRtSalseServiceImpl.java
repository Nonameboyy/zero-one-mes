package com.zeroone.star.warehousemanagement.service.impl;

import com.zeroone.star.project.dto.j4.warehousemanagement.rtsalse.RtSalsesDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.warehousemanagement.constant.Constants;
import com.zeroone.star.warehousemanagement.constant.orderConstant;
import com.zeroone.star.warehousemanagement.entity.WmRtSalse;
import com.zeroone.star.warehousemanagement.mapper.WmRtSalseLineMapper;
import com.zeroone.star.warehousemanagement.mapper.WmRtSalseMapper;
import com.zeroone.star.warehousemanagement.service.IWmRtSalseService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.warehousemanagement.utils.StringUtils;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 产品销售退货单表 服务实现类
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-29
 */
@Service
public class WmRtSalseServiceImpl extends ServiceImpl<WmRtSalseMapper, WmRtSalse> implements IWmRtSalseService {

    @Resource
    private WmRtSalseMapper wmRtSalseMapper;
    @Resource
    private WmRtSalseLineMapper wmRtSalseLineMapper;

    /*
    * 删除销售退货单
    * */
    @Override
    public Long deleteByIds(List<Long> rtSalseIds) {
        return wmRtSalseMapper.deleteByIds(rtSalseIds);
    }

    /**
     * 查询产品销售退货单
     *
     * @param rtId 产品销售退货单主键
     * @return 产品销售退货单
     */
    @Override
    public WmRtSalse selectWmRtSalseByRtId(Long rtId)
    {
        return wmRtSalseMapper.selectWmRtSalseByRtId(rtId);
    }

    /**
     * 查询产品销售退货单列表
     *
     * @param wmRtSalse 产品销售退货单
     * @return 产品销售退货单
     */
    @Override
    public List<WmRtSalse> selectWmRtSalseList(WmRtSalse wmRtSalse)
    {
        return wmRtSalseMapper.selectWmRtSalseList(wmRtSalse);
    }

    @Override
    public String checkUnique(RtSalsesDTO rtSalsesDTO) {
        WmRtSalse wmRtSalse = new WmRtSalse();
        BeanUtils.copyProperties(rtSalsesDTO,wmRtSalse);
        WmRtSalse salse = wmRtSalseMapper.checkUnique(wmRtSalse);
        Long rtId = rtSalsesDTO.getRtId() == null? -1L: rtSalsesDTO.getRtId();
        if(StringUtils.isNotNull(salse) && rtId.longValue() != salse.getRtId().longValue()){
            return Constants.NOT_UNIQUE;
        }
        return Constants.UNIQUE;
    }

    /**
     * 新增产品销售退货单
     *
     * @param rtSalsesDTO 产品销售退货单
     * @return 结果
     */
    @Override
    public int insertWmRtSalse(RtSalsesDTO rtSalsesDTO) {
        rtSalsesDTO.setCreateTime(LocalDateTime.now());
        WmRtSalse wmRtSalse = new WmRtSalse();
        BeanUtils.copyProperties(rtSalsesDTO,wmRtSalse);
        return wmRtSalseMapper.insertWmRtSalse(wmRtSalse);
    }

    /**
     * 修改产品销售退货单
     *
     * @param rtSalsesDTO 产品销售退货单
     * @return 结果
     */
    @Override
    public int updateWmRtSalse(RtSalsesDTO rtSalsesDTO) {
        rtSalsesDTO.setUpdateTime(LocalDateTime.now());
        WmRtSalse wmRtSalse = new WmRtSalse();
        BeanUtils.copyProperties(rtSalsesDTO,wmRtSalse);
        return wmRtSalseMapper.updateWmRtSalse(wmRtSalse);
    }

    @Transactional
    @Override
    public String removes(List<Long> rtIds) {
        for (Long rtId: rtIds
        ) {
            WmRtSalse rtSalse = wmRtSalseMapper.selectWmRtSalseByRtId(rtId);
            if(!orderConstant.ORDER_STATUS_PREPARE.equals(rtSalse.getStatus())){
                return  "只能删除草稿状态单据！";
            }
            wmRtSalseLineMapper.deleteByRtSalseIds(rtId);
        }
        if (wmRtSalseMapper.deleteByIds(rtIds)==0) {
            return "删除失败！";
        }
        return null;
    }
}
