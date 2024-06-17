package com.zeroone.star.wmoutsourcerecpt.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt.OutsourceRecptTxBean;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptDTO;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptQuery;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecpt;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.wmoutsourcerecpt.mapper.WmOutsourceRecptMapper;
import com.zeroone.star.wmoutsourcerecpt.service.IWmOutsourceRecptService;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang.StringUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 外协入库单表 服务实现类
 * </p>
 *
 * @author jingzi
 * @since 2024-05-27
 */
@Slf4j
@Service
public class WmOutsourceRecptServiceImpl extends ServiceImpl<WmOutsourceRecptMapper, WmOutsourceRecpt> implements IWmOutsourceRecptService {

    @Resource
    private WmOutsourceRecptMapper wmOutsourceRecptMapper;


    @Override
    public PageDTO<WmOutsourceRecpt> listWmOutsourceRecpt(WmOutsourceRecptQuery query) {
        //构建分页查询对象
        Page<WmOutsourceRecpt> pageInfo = new Page<>(query.getPageIndex(), query.getPageSize());

        //构建查询条件
        QueryWrapper<WmOutsourceRecpt> wrapper = new QueryWrapper<>();
        if (StringUtils.isNotBlank(query.getRecptCode()))
            wrapper.like("recpt_code", query.getRecptCode());
        if (StringUtils.isNotBlank(query.getWorkorderCode()))
            wrapper.like("workorder_code", query.getWorkorderCode());
        if (StringUtils.isNotBlank(query.getVendorName()))
            wrapper.like("vendor_name", query.getVendorName());
        if (query.getRecptDate() != null) wrapper.eq("recpt_date", query.getRecptDate());

        //执行查询
        Page<WmOutsourceRecpt> result = wmOutsourceRecptMapper.selectPage(pageInfo, wrapper);
        return PageDTO.create(result);
    }

    @Override
    public WmOutsourceRecpt getWmOutsourceRecpt(Long recptId) {
        return wmOutsourceRecptMapper.selectById(recptId);
    }

    @Override
    public Long saveWmOutsourceRecpt(WmOutsourceRecptDTO save) {
        WmOutsourceRecpt wmOutsourceRecpt = new WmOutsourceRecpt();
        BeanUtil.copyProperties(save, wmOutsourceRecpt);
        wmOutsourceRecptMapper.insert(wmOutsourceRecpt);
        return wmOutsourceRecpt.getRecptId();
    }

    @Override
    public Integer removeWmOutsourceRecpt(List<Long> recptIds) {
        return wmOutsourceRecptMapper.deleteBatchIds(recptIds);
    }

    @Override
    public Boolean modifyWmOutsourceRecpt(WmOutsourceRecptDTO modify) {
        WmOutsourceRecpt wmOutsourceRecpt = new WmOutsourceRecpt();
        BeanUtil.copyProperties(modify, wmOutsourceRecpt);
        //执行修改
        return wmOutsourceRecptMapper.updateById(wmOutsourceRecpt) > 0;
    }

    @Override
    public List<OutsourceRecptTxBean> getTxBeans(Long recptId) {
        return wmOutsourceRecptMapper.selectTxBeans(recptId);
    }


}
