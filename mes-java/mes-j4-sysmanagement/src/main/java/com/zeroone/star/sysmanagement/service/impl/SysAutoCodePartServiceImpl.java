package com.zeroone.star.sysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.sysmanagement.sysAutoCodePart.SysAutoCodePartDTO;
import com.zeroone.star.project.query.j4.sysmanagement.sysAutoCodePart.sysAutoCodePartQuery;
import com.zeroone.star.sysmanagement.entity.SysAutoCodePart;
import com.zeroone.star.sysmanagement.mapper.SysAutoCodePartMapper;
import com.zeroone.star.sysmanagement.service.ISysAutoCodePartService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 编码生成规则组成表 服务实现类
 * </p>
 *
 * @author jm
 * @since 2024-05-21
 */
@Service
public class SysAutoCodePartServiceImpl extends ServiceImpl<SysAutoCodePartMapper, SysAutoCodePart> implements ISysAutoCodePartService {
    @Autowired
    private SysAutoCodePartMapper sysAutoCodePartMapper;
    /**
     * 添加编码生成规则组成表
     * @param sysAutoCodePartDTO
     */
    @Override
    public void addCodeRulePart(SysAutoCodePartDTO sysAutoCodePartDTO) {
//        将DTO类型转换为实体类型
        SysAutoCodePart sysAutoCodePart = new SysAutoCodePart();
        BeanUtil.copyProperties(sysAutoCodePartDTO,sysAutoCodePart);
//        进行添加
        save(sysAutoCodePart);
    }

    /**
     * 修改编码生成规则组成表
     * @param sysAutoCodePartDTO
     */
    @Override
    public void modifyCodeRulePart(SysAutoCodePartDTO sysAutoCodePartDTO) {
        //        将DTO类型转换为实体类型
        SysAutoCodePart sysAutoCodePart = new SysAutoCodePart();
        BeanUtil.copyProperties(sysAutoCodePartDTO,sysAutoCodePart);
//        进行修改
        updateById(sysAutoCodePart);
    }

    /**
     * 删除编码生成规则组成表
     * @param partIds
     */
    @Override
    public void removeCodeRulePart(List<String> partIds) {
//        删除对应的编码生成规则组成表
        removeByIds(partIds);
    }

    /**
     * 根据分段Id查询编码生成规则组成表
     * @param partId
     * @return
     */
    @Override
    public SysAutoCodePartDTO queryCodeRulePart(String partId) {
        SysAutoCodePart sysAutoCodePart = getById(partId);
//        将DO类型转换为DTO类型
        if (sysAutoCodePart != null) {
            SysAutoCodePartDTO sysAutoCodePartDTO = new SysAutoCodePartDTO();
            BeanUtil.copyProperties(sysAutoCodePart,sysAutoCodePartDTO);
            return sysAutoCodePartDTO;
        }
        return null;
    }

    /**
     * 分页查询编码生成规则组成表
     * @param sysAutoCodePartQuery
     * @return
     */
    @Override
    public PageDTO<SysAutoCodePartDTO> queryCodeRuleParts(sysAutoCodePartQuery sysAutoCodePartQuery) {
//        构建分页查询条件
        Page<SysAutoCodePart> page = new Page<>(sysAutoCodePartQuery.getPageIndex(),sysAutoCodePartQuery.getPageSize());
//        构建查询条件
        QueryWrapper<SysAutoCodePart> wrapper = new QueryWrapper<SysAutoCodePart>()
                .eq(sysAutoCodePartQuery.getPartName() != null, "part_name", sysAutoCodePartQuery.getPartName())
                .eq(sysAutoCodePartQuery.getPartIndex() != null, "part_index", sysAutoCodePartQuery.getPartIndex());
//        进行分页查询
        Page<SysAutoCodePart> sysAutoCodePartPage = page(page, wrapper);
//        将DO对象转换为DTO对象
        PageDTO<SysAutoCodePartDTO> sysAutoCodePartDTOPage = new PageDTO<>();
        BeanUtil.copyProperties(sysAutoCodePartPage,sysAutoCodePartDTOPage);
        List<SysAutoCodePart> records = sysAutoCodePartPage.getRecords();
        List<SysAutoCodePartDTO> sysAutoCodePartDTOList = BeanUtil.copyToList(records, SysAutoCodePartDTO.class);
        sysAutoCodePartDTOPage.setRows(sysAutoCodePartDTOList);
        return sysAutoCodePartDTOPage;
    }

    @Override
    public List<SysAutoCodePart> listPart(SysAutoCodePart sysAutoCodePart) {
        return sysAutoCodePartMapper.selectSysAutoCodePartList(sysAutoCodePart);
    }
}
