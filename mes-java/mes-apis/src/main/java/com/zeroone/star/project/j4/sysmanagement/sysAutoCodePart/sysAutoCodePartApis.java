package com.zeroone.star.project.j4.sysmanagement.sysAutoCodePart;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.sysmanagement.sysAutoCodePart.SysAutoCodePartDTO;
import com.zeroone.star.project.query.j4.sysmanagement.sysAutoCodePart.sysAutoCodePartQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @version 1.0
 * @Description: 编码生成规则组成表API定义
 * @Author: jm
 * @Date: 2024/5/21 20:11
 */
public interface sysAutoCodePartApis {
//    增加规则组成
    public JsonVO addCodeRulePart(SysAutoCodePartDTO sysAutoCodePartDTO);
//    修改规则组成
    public JsonVO modifyCodeRulePart(SysAutoCodePartDTO sysAutoCodePartDTO);
//    删除规则组成(支出批量删除)
    public JsonVO removeCodeRulePart(List<String> partIds);
//    根据partId查询规则组成
    public JsonVO<SysAutoCodePartDTO> queryCodeRulePart(String partId);
//    查询规则组成列表(条件加分页)
    public JsonVO<PageDTO<SysAutoCodePartDTO>> queryCodeRuleParts(sysAutoCodePartQuery sysAutoCodePartQuery);
}
