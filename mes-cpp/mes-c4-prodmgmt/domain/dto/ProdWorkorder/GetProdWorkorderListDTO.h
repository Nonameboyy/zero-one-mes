#pragma once
#ifndef _GETPRODWORKORDERLIST_DTO_
#define _GETPRODWORKORDERLIST_DTO_
#include "../../GlobalInclude.h"
#include "../lib-common/include/tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ɹ����б������
 */

class GetProdWorkorderListDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(GetProdWorkorderListDTO, DTO);
	//����ID;workorder_id;bigint
	DTO_FIELD(UInt64, workorder_id);
	DTO_FIELD_INFO(workorder_id) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_id");
	}
	//��������;workorder_code;varchar
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_code");
	}
	//��������;workorder_name;varchar
	DTO_FIELD(String, workorder_name);
	DTO_FIELD_INFO(workorder_name) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_name");
	}
	//��������;workorder_type;varchar
	DTO_FIELD(String, workorder_type);
	DTO_FIELD_INFO(workorder_type) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_type");
	}
	//������Դ;order_source;varchar
	DTO_FIELD(String, order_source);
	DTO_FIELD_INFO(order_source) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.order_source");
	}
	//�������;source_code;varchar
	DTO_FIELD(String, source_code);
	DTO_FIELD_INFO(source_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.source_code");
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
	//��������;quantity_changed;double
	DTO_FIELD(Float64, quantity_changed);
	DTO_FIELD_INFO(quantity_changed) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.quantity_changed");
	}
	//����������;quantity_produced;double
	DTO_FIELD(Float64, quantity_produced);
	DTO_FIELD_INFO(quantity_produced) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.quantity_produced");
	}
	//���κ�;batch_code;varchar
	DTO_FIELD(String, batch_code);
	DTO_FIELD_INFO(batch_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.batch_code");
	}
	//�ͻ�����;client_code;varchar
	DTO_FIELD(String, client_code);
	DTO_FIELD_INFO(client_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.client_code");
	}
	//�ͻ�����;client_name;varchar
	DTO_FIELD(String, client_name);
	DTO_FIELD_INFO(client_name) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.client_name");
	}
	//��������;request_date;datetime
	DTO_FIELD(String, request_date);
	DTO_FIELD_INFO(request_date) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.request_date");
	}
	//����״̬;status;varchar
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.status");
	}
	
	

	// �Ӳ˵�
	API_DTO_FIELD(List<GetProdWorkorderListDTO::Wrapper>, children, ZH_WORDS_GETTER("addprodworkorder.workorder.menusub"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<GetProdWorkorderListDTO>(child), Wrapper::Class::getType()));
	}
};

/**
 * ���ɹ����б��ҳ�������
 */
class GetProdWorkorderListPageDTO : public PageDTO<GetProdWorkorderListDTO::Wrapper>
{
	DTO_INIT(GetProdWorkorderListPageDTO, PageDTO<GetProdWorkorderListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETPRODWORKORDERLIST_DTO_