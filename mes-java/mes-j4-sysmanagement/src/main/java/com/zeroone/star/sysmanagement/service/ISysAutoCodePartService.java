package com.zeroone.star.sysmanagement.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.sysmanagement.sysAutoCodePart.SysAutoCodePartDTO;
import com.zeroone.star.project.query.j4.sysmanagement.sysAutoCodePart.sysAutoCodePartQuery;
import com.zeroone.star.sysmanagement.entity.SysAutoCodePart;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 编码生成规则组成表 服务类
 * </p>
 *
 * @author jm
 * @since 2024-05-21
 */
public interface ISysAutoCodePartService extends IService<SysAutoCodePart> {

    void addCodeRulePart(SysAutoCodePartDTO sysAutoCodePartDTO);

    void modifyCodeRulePart(SysAutoCodePartDTO sysAutoCodePartDTO);

    void removeCodeRulePart(List<String> partIds);

    SysAutoCodePartDTO queryCodeRulePart(String partId);

    PageDTO<SysAutoCodePartDTO> queryCodeRuleParts(sysAutoCodePartQuery sysAutoCodePartQuery);

    List<SysAutoCodePart> listPart(SysAutoCodePart sysAutoCodePart);
}
