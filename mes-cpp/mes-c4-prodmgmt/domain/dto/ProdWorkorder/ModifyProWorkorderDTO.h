#pragma once
#ifndef _MODIFYPROWORKORDER_DTO_
#define _MODIFYPROWORKORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改生产工单数据传输类型
 */
class ModifyProWorkorderDTO : public oatpp::DTO
{
	DTO_INIT(ModifyProWorkorderDTO, DTO);

	// 编号
	DTO_FIELD(UInt64, workorderId);
	DTO_FIELD_INFO(workorderId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderId");
	}
	// 工单编号
	DTO_FIELD(String, workorderCode);
	DTO_FIELD_INFO(workorderCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderCode");
	}
	// 工单名称
	DTO_FIELD(String, workorderName);
	DTO_FIELD_INFO(workorderName) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderName");
	}
	// 订单编号 来源单据
	DTO_FIELD(String, sourceCode);
	DTO_FIELD_INFO(sourceCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.sourceCode");
	}
	// 产品ID
	DTO_FIELD(UInt64, productId);
	DTO_FIELD_INFO(productId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.productId");
	}
	// 产品编号
	DTO_FIELD(String, productCode);
	DTO_FIELD_INFO(productCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.productCode");
	}
	// 产品名称
	DTO_FIELD(String, productName);
	DTO_FIELD_INFO(productName) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.productName");
	}
	// 客户ID
	DTO_FIELD(UInt64, clientId);
	DTO_FIELD_INFO(clientId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.clientId");
	}
	// 客户编码
	DTO_FIELD(String, clientCode);
	DTO_FIELD_INFO(clientCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.clientCode");
	}
	// 客户名称
	DTO_FIELD(String, clientName);
	DTO_FIELD_INFO(clientName) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.clientName");
	}
	// 工单类型
	DTO_FIELD(String, workorderType);
	DTO_FIELD_INFO(workorderType) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderType");
	}
	// 需求日期
	DTO_FIELD(String, requestDate);
	DTO_FIELD_INFO(requestDate) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.requestDate");
	}

	// 来源类型
	DTO_FIELD(String, orderSource);
	DTO_FIELD_INFO(orderSource) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.orderSource");
	}
	// 单据状态
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.status");
	}
	// 规格型号
	DTO_FIELD(String, productSpc);
	DTO_FIELD_INFO(productSpc) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.productSpc");
	}
	// 单位
	DTO_FIELD(String, unitOfMeasure);
	DTO_FIELD_INFO(unitOfMeasure) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.unitOfMeasure");
	}
	// 生产数量 工单数量
	DTO_FIELD(Float64, quantity);
	DTO_FIELD_INFO(quantity) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.quantity");
	}

	// 批次号
	DTO_FIELD(String, batchCode);
	DTO_FIELD_INFO(batchCode) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.batchCode");
	}
	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.remark");
	}
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_MODIFYPROWORKORDER_DTO_