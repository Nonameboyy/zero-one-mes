#pragma once
#ifndef _MATERIAL_DTO_
#define _MATERIAL_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 物料信息的传输对象
 */
class MaterialDTO : public oatpp::DTO
{
	DTO_INIT(MaterialDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, line_id);
	DTO_FIELD_INFO(line_id) {
		info->description = ZH_WORDS_GETTER("Material.field.id");
	}
	// 领料单ID
	DTO_FIELD(UInt64, issue_id);
	DTO_FIELD_INFO(issue_id) {
		info->description = ZH_WORDS_GETTER("Material.field.issue_id");
	}
	// 产品物料ID
	DTO_FIELD(UInt64, item_id);
	DTO_FIELD_INFO(item_id) {
		info->description = ZH_WORDS_GETTER("Material.field.item_id");
	}
	// 产品物料编码
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("Material.field.item_code");
	}
	// 产品物料名称
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("Material.field.item_name");
	}
	// 规格型号
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("Material.field.specification");
	}

	// 单位
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("Material.field.unit_of_measure");
	}

	// 领料数量
	DTO_FIELD(Float64, quantity_issued);
	DTO_FIELD_INFO(quantity_issued) {
		info->description = ZH_WORDS_GETTER("Material.field.quantity_issued");
	}
	// 批次号
	DTO_FIELD(String, batch_code);
	DTO_FIELD_INFO(batch_code) {
		info->description = ZH_WORDS_GETTER("Material.field.batch_code");
	}
	// 仓库名称
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("Material.field.warehouse_name");
	}
	// 库区名称
	DTO_FIELD(String, location_name);
	DTO_FIELD_INFO(location_name) {
		info->description = ZH_WORDS_GETTER("Material.field.location_name");
	}
	// 库位名称
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("Material.field.area_name");
	}
	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("Material.field.remark");
	}
};

/**
 * 示例分页传输对象
 */
class MaterialPageDTO : public PageDTO<MaterialDTO::Wrapper>
{
	DTO_INIT(MaterialPageDTO, PageDTO<MaterialDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MATERIAL_DTO_