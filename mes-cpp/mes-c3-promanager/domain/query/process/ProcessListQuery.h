#pragma once
#ifndef _PROCESSLIST_QUERY_
#define _PROCESSLIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工艺详情查询对象
 */
class ProcessDetailQuery : public PageQuery
{
	DTO_INIT(ProcessDetailQuery, PageQuery);

	// 唯一标识
	DTO_FIELD(UInt32, routeId);
	DTO_FIELD_INFO(routeId) {
		info->description = ZH_WORDS_GETTER("process.field.id");
	}
};

/**
 * 分页查询工艺列表
 */
class ProcessListQuery : public PageQuery
{
	DTO_INIT(ProcessListQuery, PageQuery);
	// 工艺路线编号
	DTO_FIELD(String, routeCode);
	DTO_FIELD_INFO(routeCode) {
		info->description = ZH_WORDS_GETTER("process.field.code");
	}
	// 工艺路线名称
	DTO_FIELD(String, routeName);
	DTO_FIELD_INFO(routeName) {
		info->description = ZH_WORDS_GETTER("process.field.name");
	}
	// 是否启用
	DTO_FIELD(String, enableFlag);
	DTO_FIELD_INFO(enableFlag) {
		info->description = ZH_WORDS_GETTER("process.field.flag");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
