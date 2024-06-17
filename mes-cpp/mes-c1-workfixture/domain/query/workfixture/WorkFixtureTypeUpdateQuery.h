#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/28

*/
#ifndef _UPDATEQUERY_H_
#define _UPDATEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具/类型设置/获取工装夹具类型名称列表  改
 */
class WorkFixtureTypeUpdateQuery : public oatpp::DTO
{
	DTO_INIT(WorkFixtureTypeUpdateQuery, DTO);
	//唯一标识
	//API_DTO_FIELD_DEFAULT(UInt64, toolTypeID, ZH_WORDS_GETTER("workfixture.fields.tooltypeid"));
	//类型编码
	API_DTO_FIELD_DEFAULT(String, typeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
	//类型名称
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	//是否编码管理N/Y 
	API_DTO_FIELD_DEFAULT(String, codeFlag, ZH_WORDS_GETTER("workfixture.type.fields.codeflag"));
	//保养维护类型 REGULAR定期维护 USAGE按使用次数维护
	//API_DTO_FIELD(String, maintenType, ZH_WORDS_GETTER("workfixture.type.fields.mtype"), true, "NULL");
	//保养周期
	//API_DTO_FIELD(Int32, maintenPriod, ZH_WORDS_GETTER("workfixture.type.fields.mpriod"), true, 0);
	//备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workfixture.type.fields.remark"), true, "");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UPDATEQUERY_H_