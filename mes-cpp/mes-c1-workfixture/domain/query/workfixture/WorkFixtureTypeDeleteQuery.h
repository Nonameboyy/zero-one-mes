#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/28

*/
#ifndef _DELETEQUERY_H_
#define _DELETEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具/类型设置/获取工装夹具类型名称列表  删除
 */
class WorkFixtureTypeDeleteQuery : public oatpp::DTO
{
	DTO_INIT(WorkFixtureTypeDeleteQuery, DTO);
	//唯一标识
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("workfixture.type.fields.id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEQUERY_H_