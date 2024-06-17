#pragma once
#ifndef _GETPRODWORKORDERLIST_DTO_
#define _GETPRODWORKORDERLIST_DTO_
#include "../../GlobalInclude.h"
#include "../lib-common/include/tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 生成工单列表传输对象
 */

class GetProdWorkorderListDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(GetProdWorkorderListDTO, DTO);
	//工单ID;workorder_id;bigint
	DTO_FIELD(UInt64, workorder_id);
	DTO_FIELD_INFO(workorder_id) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_id");
	}
	//工单编码;workorder_code;varchar
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_code");
	}
	//工单名称;workorder_name;varchar
	DTO_FIELD(String, workorder_name);
	DTO_FIELD_INFO(workorder_name) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_name");
	}
	//工单类型;workorder_type;varchar
	DTO_FIELD(String, workorder_type);
	DTO_FIELD_INFO(workorder_type) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_type");
	}
	//工单来源;order_source;varchar
	DTO_FIELD(String, order_source);
	DTO_FIELD_INFO(order_source) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.order_source");
	}
	//订单编号;source_code;varchar
	DTO_FIELD(String, source_code);
	DTO_FIELD_INFO(source_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.source_code");
	}
	//产品编号;product_code;varchar
	DTO_FIELD(String, product_code);
	DTO_FIELD_INFO(product_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.product_code");
	}
	//产品名称;product_name;varchar
	DTO_FIELD(String, product_name);
	DTO_FIELD_INFO(product_name) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.product_name");
	}
	//规格型号;product_spc;varchar
	DTO_FIELD(String, product_spc);
	DTO_FIELD_INFO(product_spc) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.product_spc");
	}
	//单位;unit_of_measure;varchar
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.unit_of_measure");
	}
	//工单数量（生产数量）;quantity;double
	DTO_FIELD(Float64, quantity);
	DTO_FIELD_INFO(quantity) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.quantity");
	}
	//调整数量;quantity_changed;double
	DTO_FIELD(Float64, quantity_changed);
	DTO_FIELD_INFO(quantity_changed) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.quantity_changed");
	}
	//已生产数量;quantity_produced;double
	DTO_FIELD(Float64, quantity_produced);
	DTO_FIELD_INFO(quantity_produced) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.quantity_produced");
	}
	//批次号;batch_code;varchar
	DTO_FIELD(String, batch_code);
	DTO_FIELD_INFO(batch_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.batch_code");
	}
	//客户编码;client_code;varchar
	DTO_FIELD(String, client_code);
	DTO_FIELD_INFO(client_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.client_code");
	}
	//客户名称;client_name;varchar
	DTO_FIELD(String, client_name);
	DTO_FIELD_INFO(client_name) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.client_name");
	}
	//需求日期;request_date;datetime
	DTO_FIELD(String, request_date);
	DTO_FIELD_INFO(request_date) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.request_date");
	}
	//单据状态;status;varchar
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.status");
	}
	
	

	// 子菜单
	API_DTO_FIELD(List<GetProdWorkorderListDTO::Wrapper>, children, ZH_WORDS_GETTER("addprodworkorder.workorder.menusub"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<GetProdWorkorderListDTO>(child), Wrapper::Class::getType()));
	}
};

/**
 * 生成工单列表分页传输对象
 */
class GetProdWorkorderListPageDTO : public PageDTO<GetProdWorkorderListDTO::Wrapper>
{
	DTO_INIT(GetProdWorkorderListPageDTO, PageDTO<GetProdWorkorderListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETPRODWORKORDERLIST_DTO_