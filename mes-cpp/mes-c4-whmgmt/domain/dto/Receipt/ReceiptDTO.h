#pragma once

#ifndef _RECEIPT_DTO_H
#define _RECEIPT_DTO_H

#include "../../GlobalInclude.h"
#include "../../dto/Receipt/ReceiptDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* �����б�����ģ��
*/
class ReceiptDTO : public oatpp::DTO
{
	DTO_INIT(ReceiptDTO, DTO);
	// ���ݿ�ı� wm_item_recpt 

	// ��ⵥID
	API_DTO_FIELD_DEFAULT(Int32, recptId, ZH_WORDS_GETTER("receipt.query.fields.recptId"));

	// ��ⵥ���
	API_DTO_FIELD_DEFAULT(String, recptCode, ZH_WORDS_GETTER("receipt.query.fields.recptCode"));

	// ��ⵥ����
	API_DTO_FIELD_DEFAULT(String, recptName, ZH_WORDS_GETTER("receipt.query.fields.recptName"));

	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendorName, ZH_WORDS_GETTER("receipt.query.fields.vendorName"));

	// �������
	API_DTO_FIELD_DEFAULT(String, poCode, ZH_WORDS_GETTER("receipt.query.fields.poCode"));

	// ������� 
	API_DTO_FIELD_DEFAULT(String, recptDate, ZH_WORDS_GETTER("receipt.query.fields.recptDate"));

	// ����״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("receipt.query.fields.status"));

};

/**
* �����б�����ģ��(��ҳ�������)
*/
class ReceiptPageTableDTO : public PageDTO<ReceiptDTO::Wrapper>
{
	DTO_INIT(ReceiptPageTableDTO, PageDTO<ReceiptDTO::Wrapper>);
};

/**
* �����б���������
*/
class ReceiptDetailDTO : public ReceiptDTO
{
	DTO_INIT(ReceiptDetailDTO, DTO);
	// ���ݿ�ı� wm_item_recpt
	
	// ���ֿ�
	API_DTO_FIELD_DEFAULT(String, warehouseName, ZH_WORDS_GETTER("receipt.query.fields.warehouseName"));

	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("receipt.query.fields.remark"));


};

#include OATPP_CODEGEN_END(DTO)

#endif // _RECEIPT_DTO_H