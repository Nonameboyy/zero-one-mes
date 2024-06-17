#pragma once
#ifndef Single_Defect_QUERY_
#define Single_Defect_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SingleQuery :public PageQuery
{
	DTO_INIT(SingleQuery, PageQuery);

	// 检验单ID
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("single.iqc_id"));

};

class DefectQuery :public PageQuery
{
	DTO_INIT(DefectQuery, PageQuery);

	// 检验单行ID
	API_DTO_FIELD_DEFAULT(UInt64, line_id, ZH_WORDS_GETTER("single.line"));

};

//
#include OATPP_CODEGEN_END(DTO)
#endif // !Single_Defect_QUERY_
