package com.zeroone.star.sysmanagement.mapper;

import com.zeroone.star.sysmanagement.entity.CodeRule;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 编码生成规则表 Mapper 接口
 * </p>
 *
 * @author jm
 * @since 2024-05-19
 */
@Mapper
public interface CodeRuleMapper extends BaseMapper<CodeRule> {

    public List<CodeRule> selectSysAutoCodeResultList(CodeRule param);
}
