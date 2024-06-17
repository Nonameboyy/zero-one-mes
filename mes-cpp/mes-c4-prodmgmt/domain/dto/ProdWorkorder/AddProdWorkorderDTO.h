#pragma once
#ifndef _ADDPRODWORKORDER_DTO_
#define _ADDPRODWORKORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增生成工单传输对象
 */
class AddProdWorkorderDTO : public oatpp::DTO
{
	DTO_INIT(AddProdWorkorderDTO, DTO);
	//工单ID;workorder_id;bigint
	DTO_FIELD(UInt64, workorder_id);
	DTO_FIELD_INFO(workorder_id) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_id");
	}
	//工单编号;workorder_code;varchar
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_code");
	}
	//工单名称;workorder_name;varchar
	DTO_FIELD(String, workorder_name);
	DTO_FIELD_INFO(workorder_name) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_name");
	}
	//来源类型;order_source;varchar
	DTO_FIELD(String, order_source);
	DTO_FIELD_INFO(order_source) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.order_source");
	}
	//单据状态;status;varchar
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.status");
	}
	//工单类型;workorder_type;varchar
	DTO_FIELD(String, workorder_type);
	DTO_FIELD_INFO(workorder_type) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_type");
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
	//需求日期;request_date;datetime
	DTO_FIELD(String, request_date);
	DTO_FIELD_INFO(request_date) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.request_date");
	}
	//批次号;batch_code;varchar
	DTO_FIELD(String, batch_code);
	DTO_FIELD_INFO(batch_code) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.batch_code");
	}
	//备注;remark;varchar
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.remark");
	}
	//产品ID;product_id;bigint
	DTO_FIELD(UInt64, product_id);
	DTO_FIELD_INFO(product_id) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.product_id");
	}
	//所有父节点ID;ancestors;varchar
	DTO_FIELD(String, ancestors);
	DTO_FIELD_INFO(ancestors) {
		info->description = ZH_WORDS_GETTER("addprodworkorder.workorder.ancestors");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDPRODWORKORDER_DTO_