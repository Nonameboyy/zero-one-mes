#pragma once

#ifndef _CHANGE_WORKWEAR_DTO_
#define _CHANGE_WORKWEAR_DTO_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������վ����ģ��
 */
class ChangeWorkwearDTO : public oatpp::DTO
{
	DTO_INIT(ChangeWorkwearDTO, DTO);
	// ��װ�о�id
	API_DTO_FIELD_DEFAULT(UInt64, workwearId, ZH_WORDS_GETTER("getlist.fields.workwearId"));
	// ��װ�о���������
	API_DTO_FIELD_DEFAULT(String, workweartype, ZH_WORDS_GETTER("getlist.fields.workwearType"));
	// ��װ�о�����
	API_DTO_FIELD_DEFAULT(UInt64, workwearsum, ZH_WORDS_GETTER("getlist.fields.workwearsum"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // _USERDTO_H_