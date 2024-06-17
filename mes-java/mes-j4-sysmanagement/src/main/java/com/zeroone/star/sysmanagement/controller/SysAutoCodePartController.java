package com.zeroone.star.sysmanagement.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.sysmanagement.sysAutoCodePart.SysAutoCodePartDTO;
import com.zeroone.star.project.j4.sysmanagement.sysAutoCodePart.sysAutoCodePartApis;
import com.zeroone.star.project.query.j4.sysmanagement.sysAutoCodePart.sysAutoCodePartQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanagement.service.ISysAutoCodePartService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * <p>
 * 编码生成规则组成表 前端控制器
 * </p>
 *
 * @author jm
 * @since 2024-05-21
 */
@RestController
@RequestMapping("/sysmanagement/sys-auto-code-part")
@Api(tags = "编码生成规则组成表相关接口")
@Slf4j
public class SysAutoCodePartController implements sysAutoCodePartApis {
    @Autowired
    private ISysAutoCodePartService iSysAutoCodePartService;
    /**
     * 添加编码生成规则组成表
     * @param sysAutoCodePartDTO 编码生成规则组成
     * @return 返回值
     */
    @Override
    @ApiOperation("添加编码生成规则组成表")
    @PostMapping("/add-code-rule-part")
    public JsonVO addCodeRulePart(@RequestBody SysAutoCodePartDTO sysAutoCodePartDTO) {
        log.info("添加编码生成规则组成表,{}",sysAutoCodePartDTO);
        iSysAutoCodePartService.addCodeRulePart(sysAutoCodePartDTO);
        return JsonVO.success(null);
    }

    /**
     * 修改编码生成规则组成表
     * @param sysAutoCodePartDTO 编码生成规则组成
     * @return 返回值
     */
    @Override
    @ApiOperation("修改编码生成规则组成表")
    @PutMapping("/modify-code-rule-part")
    public JsonVO modifyCodeRulePart(SysAutoCodePartDTO sysAutoCodePartDTO) {
        log.info("修改编码生成规则组成表,{}",sysAutoCodePartDTO);
        iSysAutoCodePartService.modifyCodeRulePart(sysAutoCodePartDTO);
        return JsonVO.success(null);
    }

    /**
     * 删除编码生成规则组成表
     * @param partIds 分段Id
     * @return 返回值
     */
    @Override
    @ApiOperation("删除编码生成规则组成表")
    @DeleteMapping("/remove-code-rule-part/{partIds}")
    public JsonVO removeCodeRulePart(@PathVariable List<String> partIds) {
        log.info("删除编码生成规则组成表,{}",partIds);
        iSysAutoCodePartService.removeCodeRulePart(partIds);
        return JsonVO.success(null);
    }

    /**
     * 根据分段Id查询编码生成规则组成表
     * @param partId 分段Id
     * @return 返回值
     */
    @Override
    @ApiOperation("根据分段partId查询编码生成规则组成表")
    @GetMapping("/query-code-rule-part/{partId}")
    public JsonVO<SysAutoCodePartDTO> queryCodeRulePart(@PathVariable String partId) {
        log.info("根据分段partId查询编码生成规则组成表,{}",partId);
        SysAutoCodePartDTO sysAutoCodePartDTO = iSysAutoCodePartService.queryCodeRulePart(partId);
        return JsonVO.success(sysAutoCodePartDTO);
    }

    /**
     * 分页查询编码生成规则组成表
     * @param sysAutoCodePartQuery 分页查询条件
     * @return 返回值
     */
    @Override
    @ApiOperation("分页查询编码生成规则组成表")
    @GetMapping("/query-code-rule-parts")
    public JsonVO<PageDTO<SysAutoCodePartDTO>> queryCodeRuleParts(sysAutoCodePartQuery sysAutoCodePartQuery) {
        log.info("分页查询编码生成规则组成表,{}",sysAutoCodePartQuery);
        PageDTO<SysAutoCodePartDTO> pageDTO = iSysAutoCodePartService.queryCodeRuleParts(sysAutoCodePartQuery);
        return JsonVO.success(pageDTO);
    }
}

