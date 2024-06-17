#pragma once

#ifndef _SETSTEPEXPORT_QUERY_
#define _SETSTEPEXPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����赼����ѯ����
 */
class SetStepExportQuery : public PageQuery
{
	DTO_INIT(SetStepExportQuery, PageQuery);
	// ������ID
	DTO_FIELD(UInt64, ContentId);
	DTO_FIELD_INFO(ContentId) {
		info->description = ZH_WORDS_GETTER("setstep.field.code");
	}
	// ������˳��
	DTO_FIELD(UInt32, OrderNum);
	DTO_FIELD_INFO(OrderNum) {
		info->description = ZH_WORDS_GETTER("setstep.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
