package com.zeroone.star.wmoutsourcerecpt.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecptLine.WmOutsourceRecptLineDTO;
import com.zeroone.star.project.query.j4.whsmanagement.wmoutSourceRecptLine.WmOutsourceRecptLineQuery;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecpt;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecptLine;
import com.zeroone.star.wmoutsourcerecpt.mapper.WmOutsourceRecptLineMapper;
import com.zeroone.star.wmoutsourcerecpt.service.IWmOutsourceRecptLineService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.wmoutsourcerecpt.utils.StringUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 外协入库单行表 服务实现类
 * </p>
 *
 * @author jingzi
 * @since 2024-05-29
 */
@Service
public class WmOutsourceRecptLineServiceImpl extends ServiceImpl<WmOutsourceRecptLineMapper, WmOutsourceRecptLine> implements IWmOutsourceRecptLineService {

    @Resource
    private WmOutsourceRecptLineMapper wmOutsourceRecptLineMapper;

    @Override
    public PageDTO<WmOutsourceRecptLine> listWmOutsourceRecptLine(WmOutsourceRecptLineQuery query) {
        Page<WmOutsourceRecptLine> pageLineInfo = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<WmOutsourceRecptLine> queryWrapper = new QueryWrapper<>();
        Page<WmOutsourceRecptLine> page = wmOutsourceRecptLineMapper.selectPage(pageLineInfo, queryWrapper);
        return PageDTO.create(page);
    }

    @Override
    public WmOutsourceRecptLine getWmOutsourceRecptLine(Long recptLineId) {
        return wmOutsourceRecptLineMapper.selectById(recptLineId);
    }

    @Override
    public List<WmOutsourceRecptLine> listWmOutsourceRecptLineByRecptId(Long recptId) {
        return wmOutsourceRecptLineMapper.selectWmOutsourceRecptLineByRecptId(recptId);
    }

    @Override
    public Long saveWmOutsourceRecptLine(WmOutsourceRecptLineDTO save) {
        WmOutsourceRecptLine wmOutsourceRecptLine = new WmOutsourceRecptLine();
        BeanUtil.copyProperties(save, wmOutsourceRecptLine);
        wmOutsourceRecptLineMapper.insert(wmOutsourceRecptLine);
        return wmOutsourceRecptLine.getLineId();
    }

    @Override
    public Integer removeWmOutsourceRecptLine(List<Long> recptLineIds) {
        return wmOutsourceRecptLineMapper.deleteBatchIds(recptLineIds);
    }

    @Override
    public Boolean modifyWmOutsourceRecptLine(WmOutsourceRecptLineDTO modify) {
        WmOutsourceRecptLine wmOutsourceRecptLine = new WmOutsourceRecptLine();
        BeanUtil.copyProperties(modify, wmOutsourceRecptLine);
        return wmOutsourceRecptLineMapper.updateById(wmOutsourceRecptLine) > 0;
    }
}
