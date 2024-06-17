#pragma once
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具查询对象（条件 + 分页）
 */
class WorkFixtureQuery : public PageQuery
{
	DTO_INIT(WorkFixtureQuery, PageQuery);
	// 工装夹具编码
	API_DTO_FIELD_DEFAULT(String, toolCode, ZH_WORDS_GETTER("workfixture.fields.code"));
	// 工装夹具名称
	API_DTO_FIELD_DEFAULT(String, toolName, ZH_WORDS_GETTER("workfixture.fields.name"));
	// 工装夹具类型ID，编码，名称
	API_DTO_FIELD_DEFAULT(UInt64, toolTypeId, ZH_WORDS_GETTER("workfixture.type.fields.id"));
	API_DTO_FIELD_DEFAULT(String, toolTypeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
	API_DTO_FIELD_DEFAULT(String, toolTypeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	// 品牌
	API_DTO_FIELD_DEFAULT(String, brand, ZH_WORDS_GETTER("workfixture.fields.brand"));
	// 型号
	API_DTO_FIELD_DEFAULT(String, spec, ZH_WORDS_GETTER("workfixture.fields.spec"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("workfixture.fields.status"));
};

#include OATPP_CODEGEN_END(DTO)