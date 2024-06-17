#pragma once
#ifndef _PRODUCTDTO_H_
#define _PRODUCTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//�������ϵ��б�����ģ��
class ProductTableDTO :public oatpp::DTO
{
	DTO_INIT(ProductTableDTO, DTO);
	//Ψһ��ʶ���ϵ�id ����
	API_DTO_FIELD(UInt64, issue_id, ZH_WORDS_GETTER("product.fields.issue_id"), true, 1);
	//���ϵ����
	API_DTO_FIELD(String, issue_code, ZH_WORDS_GETTER("product.fields.issue_code"), true, "");
	//���ϵ�����
	API_DTO_FIELD(String, issue_name, ZH_WORDS_GETTER("product.fields.issue_name"), true, "");
	//��������
	API_DTO_FIELD(String, workorder_code, ZH_WORDS_GETTER("product.fields.workorder_code"), true, "");
	//�ͻ����
	API_DTO_FIELD(String, client_code, ZH_WORDS_GETTER("product.fields.client_code"), true, "");
	//�ͻ�����
	API_DTO_FIELD(String, client_name, ZH_WORDS_GETTER("product.fields.client_name"), true, "");
	//��������
	API_DTO_FIELD(String, issue_date, ZH_WORDS_GETTER("product.fields.issue_date"), true, "");
	//����״̬
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("product.fields.status"), true, "");
};
//������������ģ��
class ProductDetailDTO :public ProductTableDTO
{
	DTO_INIT(ProductDetailDTO, ProductTableDTO);
	//���ϲֿ�
	API_DTO_FIELD(String, warehouse_name, ZH_WORDS_GETTER("product.fields.warehouse_name"), true, "");
	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("product.fields.remark"), true, "");

};
class ProductPageDTO :public PageDTO<ProductTableDTO::Wrapper> {
	DTO_INIT(ProductPageDTO, PageDTO<ProductTableDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif