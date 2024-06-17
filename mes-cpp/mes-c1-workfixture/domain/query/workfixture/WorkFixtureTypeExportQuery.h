#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/28

*/
#ifndef _EXPORTQUERY_H_
#define _EXPORTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具/类型设置/获取工装夹具类型名称列表  导出
 */
class WorkFixtureTypeExportQuery : public oatpp::DTO
{
	DTO_INIT(WorkFixtureTypeExportQuery, DTO);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTQUERY_H_