#pragma once
#ifndef _storage_QUERY_
#define _storage_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class storageQuery : public PageQuery
{
	DTO_INIT(storageQuery, PageQuery);
	// 产品入库单ID
	DTO_FIELD(UInt64, re_id);
	DTO_FIELD_INFO(re_id) {
		info->description = ZH_WORDS_GETTER("storage.field.re_id");
	}

	//产品入库单编号
	DTO_FIELD(String, re_code);
	DTO_FIELD_INFO(re_code) {
		info->description = ZH_WORDS_GETTER("storage.field.re_code");
	}

	// 产品入库单名称
	DTO_FIELD(String, re_name);
	DTO_FIELD_INFO(re_name) {
		info->description = ZH_WORDS_GETTER("storage.field.re_name");
	}

	//生产工单ID
	DTO_FIELD(UInt64, workorder_id);
	DTO_FIELD_INFO(workorder_id) {
		info->description = ZH_WORDS_GETTER("storage.field.workororder_id");
	}

	// 生产工单编号
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
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

	//产品接收日期
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
#include OATPP_CODEGEN_END(DTO)
#endif 