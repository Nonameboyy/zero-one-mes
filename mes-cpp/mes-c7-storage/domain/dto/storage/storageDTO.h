#pragma once
#ifndef _storage_DTO_
#define _storage_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 接收产品单据信息传输对象
 */
class storageDTO : public oatpp::DTO
{
	DTO_INIT(storageDTO, DTO);
	// 接收单据ID
	DTO_FIELD(UInt64, re_id);
	DTO_FIELD_INFO(re_id) {
		info->description = ZH_WORDS_GETTER("storage.field.re_id");
	}

	//产品接收单编号
	DTO_FIELD(String, re_code);
	DTO_FIELD_INFO(re_code) {
		info->description = ZH_WORDS_GETTER("storage.field.re_code");
	}

	// 产品接收单名称
	DTO_FIELD(String, re_name);
	DTO_FIELD_INFO(re_name) {
		info->description = ZH_WORDS_GETTER("storage.field.re_name");
	}

	//生产工单ID
	DTO_FIELD(UInt64, workororder_id);
	DTO_FIELD_INFO(workororder_id) {
		info->description = ZH_WORDS_GETTER("storage.field.workororder_id");
	}
	// 生产工单编号
	DTO_FIELD(String, workororder_code);
	DTO_FIELD_INFO(workororder_code) {
		info->description = ZH_WORDS_GETTER("storage.field.workororder_code");
	}


	// 接收仓库ID
	DTO_FIELD(UInt64, warehouse_id);
	DTO_FIELD_INFO(warehouse_id) {
		info->description = ZH_WORDS_GETTER("storage.field.warehouse_id");
	}
	// 接收仓库编码
	DTO_FIELD(String, warehouse_code);
	DTO_FIELD_INFO(warehouse_code) {
		info->description = ZH_WORDS_GETTER("storage.field.warehouse_code");
	}
	// 接收仓库名称
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("storage.field.warehouse_name");
	}

	// 库区ID
	DTO_FIELD(UInt64, location_id);
	DTO_FIELD_INFO(location_id) {
		info->description = ZH_WORDS_GETTER("storage.field.location_id");
	}
	// 库区编码
	DTO_FIELD(String, location_code);
	DTO_FIELD_INFO(location_code) {
		info->description = ZH_WORDS_GETTER("storage.field.location_code");
	}
	// 库区名称
	DTO_FIELD(String, location_name);
	DTO_FIELD_INFO(location_name) {
		info->description = ZH_WORDS_GETTER("storage.field.location_name");
	}

	// 库位ID
	DTO_FIELD(UInt64, area_id);
	DTO_FIELD_INFO(area_id) {
		info->description = ZH_WORDS_GETTER("storage.field.area_id");
	}
	// 库位编码
	DTO_FIELD(String, area_code);
	DTO_FIELD_INFO(area_code) {
		info->description = ZH_WORDS_GETTER("storage.field.area_code");
	}
	// 库位名称
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("storage.field.area_name");
	}

	//接收日期
	DTO_FIELD(String, re_date);
	DTO_FIELD_INFO(re_date) {
		info->description = ZH_WORDS_GETTER("storage.field.re_date");
	}
	//备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("storage.field.remark");
	}

};

/**
 * 示例分页传输对象
 */
class storagePageDTO : public PageDTO<storageDTO::Wrapper>
{
	DTO_INIT(storagePageDTO, PageDTO<storageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_storage_DTO_