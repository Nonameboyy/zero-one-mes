#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/18

*/
#ifndef _WORKFIXTURETYPENAMELISTQUERY_H_
#define _WORKFIXTURETYPENAMELISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具/类型设置/获取工装夹具类型名称列表  type name
 */
class WorkFixtureTypeNameListQuery : public oatpp::DTO
{
	DTO_INIT(WorkFixtureTypeNameListQuery, DTO);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WORKFIXTURETYPELISTNAMEQUERY_H_