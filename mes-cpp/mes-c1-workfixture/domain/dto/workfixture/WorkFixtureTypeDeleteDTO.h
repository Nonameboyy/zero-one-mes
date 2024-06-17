#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/17

*/
#ifndef _DELETEDTO_H_
#define _DELETEDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具/类型设置 删
 */
class WorkFixtureTypeDeleteDTO : public oatpp::DTO
{
	DTO_INIT(WorkFixtureTypeDeleteDTO, DTO);
	//唯一标识
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("workfixture.type.fields.id"));;
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEDTO_H_