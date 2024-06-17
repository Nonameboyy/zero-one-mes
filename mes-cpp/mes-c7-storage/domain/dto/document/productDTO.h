#pragma once
#ifndef _product_DTO_
#define _product_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ��ⵥ���б�����ģ��
 */
class ProductDTO : public oatpp::DTO
{
	DTO_INIT(ProductDTO, DTO);
	// ��ⵥid��Ψһ��
	API_DTO_FIELD(UInt64, recpt_id, ZH_WORDS_GETTER("product.fields.recpt_id"), true, 1);
	// ��ⵥ���
	API_DTO_FIELD(String, recpt_code, ZH_WORDS_GETTER("product.fields.recpt_code"), true, "rt_code");
	// ��ⵥ����
	API_DTO_FIELD(String, recpt_name, ZH_WORDS_GETTER("product.fields.recpt_name"), true, "rt_name");
	// ������������
	API_DTO_FIELD(String, workorder_code, ZH_WORDS_GETTER("product.fields.workorder_code"), true, "workorder_code");
	// ��Ʒ����
	API_DTO_FIELD(String, product_code, ZH_WORDS_GETTER("product.fields.product_code"), true, "product_code");
	// ��Ʒ����
	API_DTO_FIELD(String, product_name, ZH_WORDS_GETTER("product.fields.product_name"), true, " product_name");
	//
	API_DTO_FIELD(String, warehouse_name, ZH_WORDS_GETTER("product.fields.warehouse_name"), true, " warehouse_name");
	//
	//�������
	API_DTO_FIELD(String, recpt_date, ZH_WORDS_GETTER("product.fields.recpt_date"), true, "2024-05-17 00:29:30");
	//����״̬
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("product.fields.status"), true, "default");
};

/**
 * �����б��ҳ�������
 */
class ProductPageDTO : public PageDTO<ProductDTO::Wrapper>
{
	DTO_INIT(ProductPageDTO, PageDTO<ProductDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_#pragma once
