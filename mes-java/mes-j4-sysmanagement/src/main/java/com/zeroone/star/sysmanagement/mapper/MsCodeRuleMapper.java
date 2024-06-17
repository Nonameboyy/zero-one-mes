package com.zeroone.star.sysmanagement.mapper;

import com.zeroone.star.project.dto.j4.sysmanagement.coderule.CodeRuleDTO;
import com.zeroone.star.sysmanagement.entity.CodeRule;
import org.mapstruct.Mapper;

/**
 * @version 1.0
 * @Description: null
 * @Author: jm
 * @Date: 2024/5/19 17:06
 */


@Mapper(componentModel = "spring")
public interface MsCodeRuleMapper{
    //    将CodeRule实体类转换为CodeRuleDTO
    CodeRuleDTO toCodeRuleDTO(CodeRule codeRule);
    //    将CodeRuleDTO转换为CodeRule
    CodeRule  toCodeRule(CodeRuleDTO codeRuleDTO);

}
