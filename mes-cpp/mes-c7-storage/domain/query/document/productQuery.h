#pragma once
#ifndef _product_QUERY_
#define _product_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ѯ��������
 */
class ProductPageQuery : public PageQuery
{
	DTO_INIT(ProductPageQuery, PageQuery);

	API_DTO_FIELD_DEFAULT(UInt64, recpt_id, ZH_WORDS_GETTER("product.fields.recpt_id"));
	// ��ⵥ���
	API_DTO_FIELD_DEFAULT(String, recpt_code, ZH_WORDS_GETTER("product.fields.recpt_code"));
	// ��ⵥ����
	API_DTO_FIELD_DEFAULT(String, recpt_name, ZH_WORDS_GETTER("product.fields.recpt_name"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, workorder_code, ZH_WORDS_GETTER("product.fields.workorder_code"));
	//�ֿ�����
	API_DTO_FIELD_DEFAULT(String, warehouse_name, ZH_WORDS_GETTER("product.fields.warehouse_name"));

};
class ProductDetailQuery :public oatpp::DTO
{
	DTO_INIT(ProductDetailQuery, DTO);
	API_DTO_FIELD_DEFAULT(UInt64, recpt_id, ZH_WORDS_GETTER("product.fields.recpt_id"));
	// ��ⵥ���
	API_DTO_FIELD_DEFAULT(String, recpt_code, ZH_WORDS_GETTER("product.fields.recpt_code"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_