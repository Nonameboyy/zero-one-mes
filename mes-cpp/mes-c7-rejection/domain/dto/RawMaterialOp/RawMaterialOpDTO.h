#pragma once
#ifndef _RawMaterialOp_DTO_
#define _RawMaterialOp_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 生产退料物料信息传输对象
 */
class RawMaterialOpDTO : public oatpp::DTO
{
	DTO_INIT(RawMaterialOpDTO, DTO);
	// 退料单ID
	DTO_FIELD(UInt64, rt_id);
	DTO_FIELD_INFO(rt_id) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.rt_id");
	}

	//退料单编号
	DTO_FIELD(String, rt_code);
	DTO_FIELD_INFO(rt_code) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.rt_code");
	}

	// 退料单名称
	DTO_FIELD(String, rt_name);
	DTO_FIELD_INFO(rt_name) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.rt_name");
	}

	//生产工单ID
	DTO_FIELD(UInt64, workororder_id);
	DTO_FIELD_INFO(workororder_id) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.workororder_id");
	}
	// 生产工单编号
	DTO_FIELD(String, workororder_code);
	DTO_FIELD_INFO(workororder_code) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.workororder_code");
	}


	// 接收仓库ID
	DTO_FIELD(UInt64, warehouse_id);
	DTO_FIELD_INFO(warehouse_id) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.warehouse_id");
	}
	// 接收仓库编码
	DTO_FIELD(String, warehouse_code);
	DTO_FIELD_INFO(warehouse_code) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.warehouse_code");
	}
	// 接收仓库名称
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.warehouse_name");
	}

	// 库区ID
	DTO_FIELD(UInt64, location_id);
	DTO_FIELD_INFO(location_id) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.location_id");
	}
	// 库区编码
	DTO_FIELD(String, location_code);
	DTO_FIELD_INFO(location_code) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.location_code");
	}
	// 库区名称
	DTO_FIELD(String, location_name);
	DTO_FIELD_INFO(location_name) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.location_name");
	}

	// 库位ID
	DTO_FIELD(UInt64, area_id);
	DTO_FIELD_INFO(area_id) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.area_id");
	}
	// 库位编码
	DTO_FIELD(String, area_code);
	DTO_FIELD_INFO(area_code) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.area_code");
	}
	// 库位名称
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.area_name");
	}

	//退料日期
	DTO_FIELD(String, rt_date);
	DTO_FIELD_INFO(rt_date) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.rt_date");
	}
	//备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.remark");
	}

};

/**
 * 示例分页传输对象
 */
class RawMaterialOpPageDTO : public PageDTO<RawMaterialOpDTO::Wrapper>
{
	DTO_INIT(RawMaterialOpPageDTO, PageDTO<RawMaterialOpDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RawMaterialOp_DTO_