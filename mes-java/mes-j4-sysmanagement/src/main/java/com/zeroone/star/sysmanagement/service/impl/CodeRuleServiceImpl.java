package com.zeroone.star.sysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.collection.CollectionUtil;
import com.alibaba.druid.wall.violation.ErrorCode;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.sysmanagement.enums.PartTypeEnum;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.sysmanagement.coderule.CodeRuleDTO;
import com.zeroone.star.project.query.j4.sysmanagement.coderule.CodeRuleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanagement.entity.CodeRule;
import com.zeroone.star.sysmanagement.entity.SysAutoCodePart;
import com.zeroone.star.sysmanagement.mapper.CodeRuleMapper;
import com.zeroone.star.sysmanagement.mapper.MsCodeRuleMapper;
import com.zeroone.star.sysmanagement.mapper.SysAutoCodePartMapper;
import com.zeroone.star.sysmanagement.service.ICodeRuleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.sysmanagement.strategy.AutoCodeUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 编码生成规则表 服务实现类
 * </p>
 *
 * @author jm
 * @since 2024-05-19
 */
@Service
public class CodeRuleServiceImpl extends ServiceImpl<CodeRuleMapper, CodeRule> implements ICodeRuleService {
    @Autowired
    private CodeRuleMapper codeRuleMapper;
    @Resource
    private MsCodeRuleMapper msCodeRuleMapper;
    @Autowired
    private SysAutoCodePartMapper sysAutoCodePartMapper;
    @Autowired
    private AutoCodeUtil autoCodeUtil;
//  删除编码规则（支持批量删除）
    @Override
    public JsonVO removeCodeRule(List<String> ruleIds) {
//        在删除前，先查看是否有编码生成规则组成在使用该编码规则
        QueryWrapper<SysAutoCodePart> queryWrapper = new QueryWrapper<SysAutoCodePart>();
        // 使用in方法来构建查询条件，检查rule_id是否在ruleIds列表中
        queryWrapper.in("rule_id", ruleIds);

        // 执行查询，获取匹配的SysAutoCodePart记录数
        Long count = sysAutoCodePartMapper.selectCount(queryWrapper);

        // 如果有记录匹配，说明存在使用中的规则，可以根据业务需求决定如何处理
        if (count > 0) {
            return JsonVO.create(null, ErrorCode.DELETE_NOT_ALLOW, "存在使用中的规则，无法删除");
        } else {
            codeRuleMapper.deleteBatchIds(ruleIds);
            return JsonVO.success(null);
        }
    }

    /**
     * 分页查询
     * @param codeRuleQuery
     * @return
     */
    @Override
    public PageDTO<CodeRuleDTO> listCodeRules(CodeRuleQuery codeRuleQuery) {
//        构建分页查询对象
        Page<CodeRule> page = new Page<>(codeRuleQuery.getPageIndex(), codeRuleQuery.getPageSize());
//        构建查询条件
        QueryWrapper<CodeRule> wrapper = new QueryWrapper<CodeRule>()
                .like(codeRuleQuery.getRuleName() != null,"rule_name", codeRuleQuery.getRuleName())
                .like(codeRuleQuery.getRuleCode() != null,"rule_code", codeRuleQuery.getRuleCode())
                .eq(codeRuleQuery.getEnableFlag() != null,"enable_flag", codeRuleQuery.getEnableFlag());
//        进行分页查询
        Page<CodeRule> codeRulePage = codeRuleMapper.selectPage(page, wrapper);
//        将do对象转换为dto对象
//        PageDTO<CodeRuleDTO> pageDTO = PageDTO.create(codeRulePage, src -> msCodeRuleMapper.toCodeRuleDTO(src));
        PageDTO<CodeRuleDTO> codeRuleDTOPage = new PageDTO<>();
        /*
        使用BeanUtil.copyProperties来从Page<CodeRule>复制属性到PageDTO<CodeRuleDTO>。这种方法会复制分页信息（如总页数、当前页数等），
        但不会复制数据记录（Page对象中的records属性）。
         */
        BeanUtil.copyProperties(codeRulePage, codeRuleDTOPage);

        List<CodeRuleDTO> recordsDTO = new ArrayList<>();
        for (CodeRule codeRule : codeRulePage.getRecords()) {
            CodeRuleDTO codeRuleDTO = new CodeRuleDTO();
            BeanUtil.copyProperties(codeRule, codeRuleDTO);
            recordsDTO.add(codeRuleDTO);
        }
        codeRuleDTOPage.setRows(recordsDTO);
        return codeRuleDTOPage;
    }

    /**
     * 新增编码规则
     * @param codeRuleDTO 编码规则
     */
    @Override
    public void saveCodeRule(CodeRuleDTO codeRuleDTO) {
//        将dto数据转换为do
//        CodeRule codeRule = msCodeRuleMapper.toCodeRule(codeRuleDTO);
        CodeRule codeRule = new CodeRule();
        BeanUtil.copyProperties(codeRuleDTO, codeRule);
        codeRuleMapper.insert(codeRule);
    }

    /**
     * 修改编码规则
     * @param codeRuleDTO 编码规则
     */
    @Override
    public void updateCodeRule(CodeRuleDTO codeRuleDTO) {
//        将dto数据转换为do
//        CodeRule codeRule = msCodeRuleMapper.toCodeRule(codeRuleDTO);
        CodeRule codeRule = new CodeRule();
        BeanUtil.copyProperties(codeRuleDTO, codeRule);
        codeRuleMapper.updateById(codeRule);
    }

    /**
     * 获取唯一编码
     * @param ruleCode
     * @param inputCharacter
     * @return
     */
    @Override
    public String getAutoCode(String ruleCode, String inputCharacter) {
        return autoCodeUtil.genSerialCode(ruleCode, inputCharacter);
    }

    @Override
    public CodeRule getOne(String ruleCode) {
        CodeRule param = new CodeRule();
        param.setRuleCode(ruleCode);
        List<CodeRule> rules = codeRuleMapper.selectSysAutoCodeResultList(param);
        if(CollectionUtil.isNotEmpty(rules)){
            return rules.get(0);
        }
        return null;
    }

}
