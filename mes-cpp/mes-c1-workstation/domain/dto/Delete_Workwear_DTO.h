#pragma once

#ifndef _DELETE_WORKWEAR_DTO
#define _DELETE_WORKWEAR_DTO

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������վ����ģ��
 */
class DeleteWorkwearDTO : public oatpp::DTO
{
	DTO_INIT(DeleteWorkwearDTO, DTO);
	// ��װ�о��Ƿ�ɾ��
	API_DTO_FIELD_DEFAULT(String, Deletetype, ZH_WORDS_GETTER("getlist.fields.workstationCode"));
};


#include OATPP_CODEGEN_END(DTO)

#endif // _USERDTO_H_