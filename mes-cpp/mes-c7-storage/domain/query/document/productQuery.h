#pragma once
#ifndef _product_QUERY_
#define _product_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询条件对象
 */
class ProductPageQuery : public PageQuery
{
	DTO_INIT(ProductPageQuery, PageQuery);

	API_DTO_FIELD_DEFAULT(UInt64, recpt_id, ZH_WORDS_GETTER("product.fields.recpt_id"));
	// 入库单编号
	API_DTO_FIELD_DEFAULT(String, recpt_code, ZH_WORDS_GETTER("product.fields.recpt_code"));
	// 入库单名称
	API_DTO_FIELD_DEFAULT(String, recpt_name, ZH_WORDS_GETTER("product.fields.recpt_name"));
	// 生产工单
	API_DTO_FIELD_DEFAULT(String, workorder_code, ZH_WORDS_GETTER("product.fields.workorder_code"));
	//仓库名称
	API_DTO_FIELD_DEFAULT(String, warehouse_name, ZH_WORDS_GETTER("product.fields.warehouse_name"));

};
class ProductDetailQuery :public oatpp::DTO
{
	DTO_INIT(ProductDetailQuery, DTO);
	API_DTO_FIELD_DEFAULT(UInt64, recpt_id, ZH_WORDS_GETTER("product.fields.recpt_id"));
	// 入库单编号
	API_DTO_FIELD_DEFAULT(String, recpt_code, ZH_WORDS_GETTER("product.fields.recpt_code"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_