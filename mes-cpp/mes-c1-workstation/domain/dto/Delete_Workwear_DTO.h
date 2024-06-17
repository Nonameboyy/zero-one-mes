#pragma once

#ifndef _DELETE_WORKWEAR_DTO
#define _DELETE_WORKWEAR_DTO

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增工作站数据模型
 */
class DeleteWorkwearDTO : public oatpp::DTO
{
	DTO_INIT(DeleteWorkwearDTO, DTO);
	// 工装夹具是否删除
	API_DTO_FIELD_DEFAULT(String, Deletetype, ZH_WORDS_GETTER("getlist.fields.workstationCode"));
};


#include OATPP_CODEGEN_END(DTO)

#endif // _USERDTO_H_