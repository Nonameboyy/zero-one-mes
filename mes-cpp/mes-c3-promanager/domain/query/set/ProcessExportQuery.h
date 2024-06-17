#pragma once
#ifndef _PROCESSEXPORT_QUERY_
#define _PROCESSEXPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���򵼳���ѯ����
 */
class ProcessExportQuery : public PageQuery
{
	DTO_INIT(ProcessExportQuery, PageQuery);
	// ������
	DTO_FIELD(String, processCode);
	DTO_FIELD_INFO(processCode) {
		info->description = ZH_WORDS_GETTER("set.fields.processcode");
	}
	// ��������
	DTO_FIELD(String, processName);
	DTO_FIELD_INFO(processName) {
		info->description = ZH_WORDS_GETTER("set.fields.processname");
	}
	// �Ƿ�����
	DTO_FIELD(String, enableFlag);
	DTO_FIELD_INFO(enableFlag) {
		info->description = ZH_WORDS_GETTER("set.fields.enableflag");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
