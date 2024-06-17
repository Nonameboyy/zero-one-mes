#pragma once

#ifndef _INSPECTIONITEMS_QUERY_
#define _INSPECTIONITEMS_QUERY_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ProinspectQuery : public PageQuery
{
	DTO_INIT(ProinspectQuery, PageQuery);

	DTO_FIELD(Int32, ipqc_id);
	DTO_FIELD_INFO(ipqc_id) {
		info->description = ZH_WORDS_GETTER("processinspection.field.ipqc_id");
	}
	DTO_FIELD(Int32, line_id);
	DTO_FIELD_INFO(line_id) {
		info->description = ZH_WORDS_GETTER("processinspection.field.ipqc_id");
	}
	// ���鵥���
	DTO_FIELD(String, ipqc_code);
	DTO_FIELD_INFO(ipqc_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.ipqc_code");
	}
	// ��������
	DTO_FIELD(String, ipqc_type);
	DTO_FIELD_INFO(ipqc_type) {
		info->description = ZH_WORDS_GETTER("processinspection.field.ipqc_type");
	}
	// �������
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.workorder_code");
	}
	// ��Ʒ���ϱ���
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.item_code");
	}
	// ��Ʒ��������
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("processinspection.field.item_name");
	}
	// �����
	DTO_FIELD(String, check_result);
	DTO_FIELD_INFO(check_result) {
		info->description = ZH_WORDS_GETTER("processinspection.field.check_result");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_INSPECTIONITEMS_QUERY_