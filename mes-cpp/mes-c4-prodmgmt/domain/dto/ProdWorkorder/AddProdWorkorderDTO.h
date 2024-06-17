#pragma once
#ifndef _ADDPRODWORKORDER_DTO_
#define _ADDPRODWORKORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������ɹ����������
 */
class AddProdWorkorderDTO : public oatpp::DTO
{
	DTO_INIT(AddProdWorkorderDTO, DTO);
	//����ID;workorder_id;bigint
	DTO_FIELD(UInt64, workorder_id);
	DTO_FIELD_INFO(workorder_id) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_id");
	}
	//�������;workorder_code;varchar
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_code");
	}
	//��������;workorder_name;varchar
	DTO_FIELD(String, workorder_name);
	DTO_FIELD_INFO(workorder_name) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_name");
	}
	//��Դ����;order_source;varchar
	DTO_FIELD(String, order_source);
	DTO_FIELD_INFO(order_source) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.order_source");
	}
	//����״̬;status;varchar
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.status");
	}
	//��������;workorder_type;varchar
	DTO_FIELD(String, workorder_type);
	DTO_FIELD_INFO(workorder_type) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_type");
	}
	//��Ʒ���;product_code;varchar
	DTO_FIELD(String, product_code);
	DTO_FIELD_INFO(product_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.product_code");
	}
	//��Ʒ����;product_name;varchar
	DTO_FIELD(String, product_name);
	DTO_FIELD_INFO(product_name) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.product_name");
	}
	//����ͺ�;product_spc;varchar
	DTO_FIELD(String, product_spc);
	DTO_FIELD_INFO(product_spc) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.product_spc");
	}
	//��λ;unit_of_measure;varchar
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.unit_of_measure");
	}
	//��������������������;quantity;double
	DTO_FIELD(Float64, quantity);
	DTO_FIELD_INFO(quantity) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.quantity");
	}
	//��������;request_date;datetime
	DTO_FIELD(String, request_date);
	DTO_FIELD_INFO(request_date) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.request_date");
	}
	//���κ�;batch_code;varchar
	DTO_FIELD(String, batch_code);
	DTO_FIELD_INFO(batch_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.batch_code");
	}
	//��ע;remark;varchar
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.remark");
	}
	//��ƷID;product_id;bigint
	DTO_FIELD(UInt64, product_id);
	DTO_FIELD_INFO(product_id) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.product_id");
	}
	//���и��ڵ�ID;ancestors;varchar
	DTO_FIELD(String, ancestors);
	DTO_FIELD_INFO(ancestors) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.ancestors");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDPRODWORKORDER_DTO_