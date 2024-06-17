#pragma once
/*
* 
*/
#ifndef _PLANSUBJECTQUERY_H_
#define _PLANSUBJECTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 设备点检/保养管理 查询条件对象
 */
class PlanSubjectQuery : public PageQuery
{
	DTO_INIT(PlanSubjectQuery, DTO);

	//项目编号，详细展开
	API_DTO_FIELD_DEFAULT(String, subCode, ZH_WORDS_GETTER("planSubject.fields.subCode"));
	//项目名称
	API_DTO_FIELD_DEFAULT(String, subName, ZH_WORDS_GETTER("planSubject.fields.subName"));
	//项目类型
	API_DTO_FIELD_DEFAULT(String, subType, ZH_WORDS_GETTER("planSubject.fields.subType"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // 
