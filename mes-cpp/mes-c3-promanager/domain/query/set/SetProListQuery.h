#pragma once
#ifndef _SETPRO_QUERY_
#define _SETPRO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工序设置-获取工序步骤列表接口
 */
class SetProListQuery : public PageQuery
{ 
	DTO_INIT(SetProListQuery, PageQuery);
	//工序ID
	API_DTO_FIELD_DEFAULT(UInt64, processId, ZH_WORDS_GETTER("set.fields.processid"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
