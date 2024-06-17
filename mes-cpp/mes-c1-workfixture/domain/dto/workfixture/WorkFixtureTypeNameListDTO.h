#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/18

*/
#ifndef _WORKFIXTURETYPENAMELISTDTO_H_
#define _WORKFIXTURETYPENAMELISTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具/类型设置/工装夹具类型列表DTO type name
 */
class WorkFixtureTypeNameListDTO : public oatpp::DTO
{
	DTO_INIT(WorkFixtureTypeNameListDTO, DTO);
	//唯一标识
	API_DTO_FIELD_DEFAULT(UInt64, toolTypeID, ZH_WORDS_GETTER("workfixture.type.fields.id"));
	//类型名称
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	//类型编码
	API_DTO_FIELD_DEFAULT(String, typeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WORKFIXTURETYPENAMELISTDTO_H_