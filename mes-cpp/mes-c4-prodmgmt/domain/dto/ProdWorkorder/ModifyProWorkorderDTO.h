#pragma once
#ifndef _MODIFYPROWORKORDER_DTO_
#define _MODIFYPROWORKORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �޸������������ݴ�������
 */
class ModifyProWorkorderDTO : public oatpp::DTO
{
	DTO_INIT(ModifyProWorkorderDTO, DTO);

	// ���
	DTO_FIELD(UInt64, workorderId);
	DTO_FIELD_INFO(workorderId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderId");
	}
	// �������
	DTO_FIELD(String, workorderCode);
	DTO_FIELD_INFO(workorderCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderCode");
	}
	// ��������
	DTO_FIELD(String, workorderName);
	DTO_FIELD_INFO(workorderName) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderName");
	}
	// ������� ��Դ����
	DTO_FIELD(String, sourceCode);
	DTO_FIELD_INFO(sourceCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.sourceCode");
	}
	// ��ƷID
	DTO_FIELD(UInt64, productId);
	DTO_FIELD_INFO(productId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.productId");
	}
	// ��Ʒ���
	DTO_FIELD(String, productCode);
	DTO_FIELD_INFO(productCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.productCode");
	}
	// ��Ʒ����
	DTO_FIELD(String, productName);
	DTO_FIELD_INFO(productName) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.productName");
	}
	// �ͻ�ID
	DTO_FIELD(UInt64, clientId);
	DTO_FIELD_INFO(clientId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.clientId");
	}
	// �ͻ�����
	DTO_FIELD(String, clientCode);
	DTO_FIELD_INFO(clientCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.clientCode");
	}
	// �ͻ�����
	DTO_FIELD(String, clientName);
	DTO_FIELD_INFO(clientName) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.clientName");
	}
	// ��������
	DTO_FIELD(String, workorderType);
	DTO_FIELD_INFO(workorderType) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderType");
	}
	// ��������
	DTO_FIELD(String, requestDate);
	DTO_FIELD_INFO(requestDate) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.requestDate");
	}

	// ��Դ����
	DTO_FIELD(String, orderSource);
	DTO_FIELD_INFO(orderSource) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.orderSource");
	}
	// ����״̬
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.status");
	}
	// ����ͺ�
	DTO_FIELD(String, productSpc);
	DTO_FIELD_INFO(productSpc) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.productSpc");
	}
	// ��λ
	DTO_FIELD(String, unitOfMeasure);
	DTO_FIELD_INFO(unitOfMeasure) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.unitOfMeasure");
	}
	// �������� ��������
	DTO_FIELD(Float64, quantity);
	DTO_FIELD_INFO(quantity) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.quantity");
	}

	// ���κ�
	DTO_FIELD(String, batchCode);
	DTO_FIELD_INFO(batchCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.batchCode");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.remark");
	}
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_MODIFYPROWORKORDER_DTO_