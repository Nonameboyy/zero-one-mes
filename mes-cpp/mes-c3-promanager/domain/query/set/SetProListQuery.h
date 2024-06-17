#pragma once
#ifndef _SETPRO_QUERY_
#define _SETPRO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������-��ȡ�������б�ӿ�
 */
class SetProListQuery : public PageQuery
{ 
	DTO_INIT(SetProListQuery, PageQuery);
	//����ID
	API_DTO_FIELD_DEFAULT(UInt64, processId, ZH_WORDS_GETTER("set.fields.processid"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
