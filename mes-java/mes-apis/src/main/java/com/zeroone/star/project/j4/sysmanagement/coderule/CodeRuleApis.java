package com.zeroone.star.project.j4.sysmanagement.coderule;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.sysmanagement.coderule.CodeRuleDTO;
import com.zeroone.star.project.query.j4.sysmanagement.coderule.CodeRuleQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 编码规则接口API定义
 * @author ：酌
 * @version 1.0
 */
public interface CodeRuleApis {

    public JsonVO removeCodeRule(List<String> ruleIds);

    public JsonVO<CodeRuleDTO> queryCodeRule(String ruleId);

    public JsonVO<PageDTO<CodeRuleDTO>> queryCodeRules(CodeRuleQuery sysAutoCodeRuleQuery);

    public JsonVO addCodeRule(CodeRuleDTO sysAutoCodeRuleDTO);

    public JsonVO modifyCodeRule(CodeRuleDTO sysAutoCodeRuleDTO);

    public JsonVO<String> getAutoCode(String ruleCode, String inputCharacter);
}
