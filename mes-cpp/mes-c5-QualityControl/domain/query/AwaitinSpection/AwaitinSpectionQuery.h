#pragma once
#ifndef _AWAITINSPECTION_QUERY_
#define _AWAITINSPECTION_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class AwaitinSpectionQuery : public PageQuery
{
	DTO_INIT(AwaitinSpectionQuery, PageQuery);
	//���ݱ���
	DTO_FIELD(String, feedback_code);
	DTO_FIELD_INFO(feedback_code) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.feedback_code");
	}
	//��������
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.item_name");
	}
	//�������
	DTO_FIELD(String, feedback_type);
	DTO_FIELD_INFO(feedback_type) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.feedback_type");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_AWAITINSPECTION_QUERY_

