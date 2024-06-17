#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/17

*/
#ifndef _WORKFIXTURETYPELISTQUERY_H_
#define _WORKFIXTURETYPELISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具/类型设置/获取工装夹具类型列表 条件查询 分页 type
 */
class WorkFixtureTypeListQuery : public PageQuery
{
	DTO_INIT(WorkFixtureTypeListQuery, PageQuery);
	//类型编码
	API_DTO_FIELD_DEFAULT(String, typeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
	//类型名称
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	//保养维护类型 REGULAR定期维护 USAGE按使用次数维护
	API_DTO_FIELD_DEFAULT(String, maintenType, ZH_WORDS_GETTER("workfixture.type.fields.mtype"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WORKFIXTURETYPELISTQUERY_H_