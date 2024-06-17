package com.zeroone.star.sysmanagement.controller;


import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.sysmanagement.coderule.CodeRuleDTO;
import com.zeroone.star.project.j4.sysmanagement.coderule.CodeRuleApis;
import com.zeroone.star.project.query.j4.sysmanagement.coderule.CodeRuleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanagement.annotation.Log;
import com.zeroone.star.sysmanagement.constant.BusinessType;
import com.zeroone.star.sysmanagement.entity.CodeRule;
import com.zeroone.star.sysmanagement.mapper.MsCodeRuleMapper;
import com.zeroone.star.sysmanagement.service.ICodeRuleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 编码生成规则表 前端控制器
 * </p>
 *
 * @author jm
 * @since 2024-05-19
 */
@RestController
@RequestMapping("/sysmanagement")
@Slf4j
@Api(tags = "编码生成规则表相关接口")
public class CodeRuleController implements CodeRuleApis {
    @Autowired
    ICodeRuleService iCodeRuleService;
    @Resource
    MsCodeRuleMapper msCodeRuleMapper;

    //删除编码规则(支持批量删除)用路径参数 delete

    @DeleteMapping("/remove-code-rule/{ruleIds}")
    @ApiOperation("删除编码规则")
    @Override
    public JsonVO removeCodeRule(@PathVariable List<String> ruleIds) {
        log.info("删除编码规则,{}",ruleIds);
        return iCodeRuleService.removeCodeRule(ruleIds);
    }
    //  根据ruleId查询单个编码规则 get
    @GetMapping("/query-code-rule/{ruleId}")
    @ApiOperation("查询单个编码规则")
    @Override
    public JsonVO<CodeRuleDTO> queryCodeRule(@PathVariable("ruleId") String ruleId) {
        log.info("查询单个编码规则,{}",ruleId);
        CodeRule codeRule = iCodeRuleService.getById(ruleId);
        if (codeRule != null) {
//            CodeRuleDTO codeRuleDTO = msCodeRuleMapper.toCodeRuleDTO(codeRule);
//            使用beanutil转换
            CodeRuleDTO codeRuleDTO = new CodeRuleDTO();
            BeanUtil.copyProperties(codeRule,codeRuleDTO);
            return JsonVO.success(codeRuleDTO);
        }
        return JsonVO.fail(null);
    }

    /**
     * 分页查询
     * @param codeRuleQuery 查询条件
     * @return 返回结果
     */
    @GetMapping("/query-code-rules")
    @ApiOperation("分页查询")
    @Override
    public JsonVO<PageDTO<CodeRuleDTO>> queryCodeRules(CodeRuleQuery codeRuleQuery) {
        log.info("编码规则的分页查询,{}",codeRuleQuery);
        PageDTO<CodeRuleDTO> pageDTO = iCodeRuleService.listCodeRules(codeRuleQuery);
        return JsonVO.success(pageDTO);
    }

    /**
     * 新增编码规则
     * @param CodeRuleDTO 编码规则
     * @return 返回结果
     */
    @PostMapping("/add-code-rule")
    @ApiOperation("新增编码规则")
    @Override
    public JsonVO addCodeRule(@RequestBody CodeRuleDTO CodeRuleDTO) {
        log.info("新增编码规则,{}",CodeRuleDTO);
        iCodeRuleService.saveCodeRule(CodeRuleDTO);
        return JsonVO.success(null);
    }

    /**
     * 修改编码规则
     * @param CodeRuleDTO 编码规则
     * @return 返回结果
     */
    @PutMapping("/modify-code-rule")
    @ApiOperation("修改编码规则")
    @Override
    public JsonVO modifyCodeRule(CodeRuleDTO CodeRuleDTO) {
        log.info("修改编码规则,{}",CodeRuleDTO);
        iCodeRuleService.updateCodeRule(CodeRuleDTO);
        return JsonVO.success(null);
    }

    /**
     * 获取唯一编码
     *
     * @param ruleCode
     * @param inputCharacter
     * @return
     */
    @GetMapping("/get-auto-code/{ruleCode}")
    @ApiOperation("获取唯一编码")
    @Override
    @Log(title = "生成业务编号",businessType = BusinessType.INSERT)
    public JsonVO<String> getAutoCode(@ApiParam(value = "规则编码", example = "CLIENT_CODE") @PathVariable("ruleCode") String ruleCode,
                                      @ApiParam(value = "输入字符", example = "SERIALNO") @RequestParam(name = "inputCharacter",required = false) String inputCharacter) {
        log.info("获取唯一编码,{},{}",ruleCode,inputCharacter);
        String autoCode = iCodeRuleService.getAutoCode(ruleCode, inputCharacter);
        return JsonVO.success(autoCode);
    }
}

