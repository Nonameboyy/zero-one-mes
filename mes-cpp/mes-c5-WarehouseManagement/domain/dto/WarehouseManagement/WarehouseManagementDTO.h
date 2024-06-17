#pragma once

#ifndef _WAREHOUSEMANAGEMENT_DTO_
#define _WAREHOUSEMANAGEMENT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 传输对象
 */
class WarehouseManagementDTO : public oatpp::DTO
{
	DTO_INIT(WarehouseManagementDTO, DTO);
	//产品物料ID
	DTO_FIELD(UInt64, item_id);
	DTO_FIELD_INFO(item_id) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.item_id");
	}

	//产品物料编码
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.item_code");
	}

	// 产品物料名称
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.item_name");
	}

	// 入库批次号
	DTO_FIELD(String, batch_code);
	DTO_FIELD_INFO(batch_code) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.batch_code");
	}

	//仓库名称
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.warehouse_name");
	}

	// 供应商编号
	DTO_FIELD(String, vendor_code);
	DTO_FIELD_INFO(vendor_code) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.vendor_code");
	}

	// 供应商名称
	DTO_FIELD(String, vendor_name);
	DTO_FIELD_INFO(vendor_name) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.vendor_name");
	}
};

/**
 * 分页传输对象
 */
class WarehouseManagementPageDTO : public PageDTO<WarehouseManagementDTO::Wrapper>
{
	DTO_INIT(WarehouseManagementPageDTO, PageDTO<WarehouseManagementDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WAREHOUSEMANAGEMENT_DTO_