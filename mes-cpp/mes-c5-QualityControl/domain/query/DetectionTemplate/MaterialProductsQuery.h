#pragma once
#ifndef _MATERIALPRODUCTS_QUERY_
#define _MATERIALPRODUCTS_QUERY_

#include "../../GlobalInclude.h"
#include "../../dto/DetectionTemplate/MaterialProductsDTO.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class MaterialProductsQuery : public PageQuery
{
	DTO_INIT(MaterialProductsQuery, PageQuery);
	// 记录ID
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.record_id");
	}

	// 产品检测模板ID
	DTO_FIELD(UInt64, template_id);
	DTO_FIELD_INFO(template_id) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.template_id");
	}

	// 产品物料ID
	DTO_FIELD(UInt64, item_id);
	DTO_FIELD_INFO(item_id) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.item_id");
	}
	// 产品物料编码
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.item_code");
	}
	// 产品物料名称
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.item_name");
	}
	// 规格型号
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.specification");
	}
	// 最低检测数
	DTO_FIELD(UInt32, quantity_check);
	DTO_FIELD_INFO(quantity_check) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.quantity_check");
	}
	// 单位
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.unit_of_measure");
	}
	// 最大不合格数
	DTO_FIELD(UInt32, quantity_unqualified);
	DTO_FIELD_INFO(quantity_unqualified) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.quantity_unqualified");
	}
	// 最大致命缺陷率
	DTO_FIELD(Float64, cr_rate);
	DTO_FIELD_INFO(cr_rate) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.cr_rate");
	}
	// 最大严重缺陷率
	DTO_FIELD(Float64, maj_rate);
	DTO_FIELD_INFO(maj_rate) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.maj_rate");
	}
	// 最大轻微缺陷率
	DTO_FIELD(Float64, min_rate);
	DTO_FIELD_INFO(min_rate) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.min_rate");
	}
	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.remark");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_