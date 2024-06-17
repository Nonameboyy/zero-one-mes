#pragma once

#ifndef _GETWORKFIXTUREFORWORKSTATION_QUERY_H_
#define _GETWORKFIXTUREFORWORKSTATION_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页获取工作站列表
 */
class GetWorkFixtureForWorkStationQuery : public PageQuery
{
	DTO_INIT(GetWorkFixtureForWorkStationQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(String, GetWFForWSTypeName, ZH_WORDS_GETTER("wf_for_ws.fields.typename"));
	API_DTO_FIELD_DEFAULT(UInt64, GetWFForWSAccount, ZH_WORDS_GETTER("wf_for_ws.fields.account"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_