#pragma once
#ifndef _DELETEWHSTORAGEORDER_DTO_
#define _DELETEWHSTORAGEORDER_DTO_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ��ɾ���û���Ϣ�����ݴ���ģ��
 */
class DeleteWhStorageorderDTO : public oatpp::DTO
{
	DTO_INIT(DeleteWhStorageorderDTO, DTO);
	//��ʶɾ����ⵥ�е�Ψһid��������line_id bigint
	API_DTO_FIELD_DEFAULT(UInt64, line_id, ZH_WORDS_GETTER("whstorageorder.field.line_id"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEWHSTORAGEORDER_DTO_
