#pragma once
#ifndef _PROCESSPRODUCTS_DTO_
#define _PROCESSPRODUCTS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class ProcessProductsDTO : public oatpp::DTO
{
	DTO_INIT(ProcessProductsDTO, DTO);

	// 唯一标识
	DTO_FIELD(UInt64, routeid);
	DTO_FIELD_INFO(routeid) {
		info->description = ZH_WORDS_GETTER("product.field.routeid");
	}
	// 产品物料编码
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("product.field.id");
	}
	// 产品物料名称
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("product.field.name");
	}
	// 规格型号
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("product.field.size");
	}
	// 单位
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("product.field.unit");
	}

};
/**
 * 工艺关联产品列表分页传输对象
 */
class ProductsPageDTO : public PageDTO<ProcessProductsDTO::Wrapper>
{
	DTO_INIT(ProductsPageDTO, PageDTO<ProcessProductsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
