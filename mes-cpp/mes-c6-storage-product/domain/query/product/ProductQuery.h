#pragma once
#ifndef _PRODUCTQUERY_H_
#define _PRODUCTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���������б��ѯ
 */
class ProductQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(ProductQuery, PageQuery);
	//���ϵ����
	API_DTO_FIELD_DEFAULT(String, issue_code, ZH_WORDS_GETTER("product.fields.issue_code"));
	//���ϵ�����
	API_DTO_FIELD_DEFAULT(String, issue_name, ZH_WORDS_GETTER("product.fields.issue_name"));
	//�ֿ�����
	API_DTO_FIELD_DEFAULT(String, warehouse_name, ZH_WORDS_GETTER("product.fields.warehouse_name"));
	//��������
	API_DTO_FIELD_DEFAULT(String, issue_date, ZH_WORDS_GETTER("product.fields.issue_date"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("product.fields.status"));

};
//�����ѯ
class ProductDetailQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(ProductDetailQuery, DTO);
	//���ϵ����
	API_DTO_FIELD_DEFAULT(UInt64, issue_id, ZH_WORDS_GETTER("product.fields.issue_id"));
	

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DEPTQUERY_H_