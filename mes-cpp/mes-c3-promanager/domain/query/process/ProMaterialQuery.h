#pragma once
#ifndef _PROMATERIAL_QUERY_H_
#define _PROMATERIAL_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取产品制程物料BOM列表分页查询对象
 */
class ProMaterialQuery : public PageQuery
{
	DTO_INIT(ProMaterialQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(UInt64, route_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.route_id"));
	API_DTO_FIELD_DEFAULT(UInt64, process_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.process_id"));
	API_DTO_FIELD_DEFAULT(UInt64, product_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.product_id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROMATERIALQUERY_H_