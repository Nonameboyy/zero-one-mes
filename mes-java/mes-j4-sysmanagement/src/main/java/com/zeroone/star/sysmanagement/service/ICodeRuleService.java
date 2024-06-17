package com.zeroone.star.sysmanagement.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.sysmanagement.coderule.CodeRuleDTO;
import com.zeroone.star.project.query.j4.sysmanagement.coderule.CodeRuleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanagement.entity.CodeRule;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 编码生成规则表 服务类
 * </p>
 *
 * @author jm
 * @since 2024-05-19
 */
public interface ICodeRuleService extends IService<CodeRule> {

    JsonVO removeCodeRule(List<String> ruleIds);

    PageDTO<CodeRuleDTO> listCodeRules(CodeRuleQuery codeRuleQuery);

    void saveCodeRule(CodeRuleDTO codeRuleDTO);

    void updateCodeRule(CodeRuleDTO codeRuleDTO);

    String getAutoCode(String ruleCode, String inputCharacter);

    public CodeRule getOne(String ruleCode);

}
