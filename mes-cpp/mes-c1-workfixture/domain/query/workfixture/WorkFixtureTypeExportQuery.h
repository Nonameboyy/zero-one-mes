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
 * ��װ�о�/��������/��ȡ��װ�о����������б�  ����
 */
class WorkFixtureTypeExportQuery : public oatpp::DTO
{
	DTO_INIT(WorkFixtureTypeExportQuery, DTO);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTQUERY_H_