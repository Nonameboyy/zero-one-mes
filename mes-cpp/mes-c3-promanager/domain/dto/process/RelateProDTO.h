#pragma once
#ifndef _RELATEPRO_DTO_H_
#define _RELATEPRO_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加工艺关联产品传输对象
 */
class AddRelateProDTO : public oatpp::DTO
{
	DTO_INIT(AddRelateProDTO, DTO);

	// 产品物料编码
	API_DTO_FIELD(String, item_code, ZH_WORDS_GETTER("RelatePro.DTO.item_code"), true, "1");
	// 产品物料名称
	API_DTO_FIELD(String, item_name, ZH_WORDS_GETTER("RelatePro.DTO.item_name"), true, "01star");
	// 产品物料单位
	API_DTO_FIELD(String, unit_of_measure, ZH_WORDS_GETTER("RelatePro.DTO.unit_of_measure"), true, "g");
	// 规格型号
	API_DTO_FIELD(String, specification, ZH_WORDS_GETTER("RelatePro.DTO.specification"), true, "null");
	// 备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("RelatePro.DTO.RPmodels"), false, "");
};

/**
 * 修改工艺关联产品传输对象
 */
class ModRelateProDTO : public AddRelateProDTO
{
	DTO_INIT(ModRelateProDTO, AddRelateProDTO);

	// 用料比例
	//API_DTO_FIELD(String, Ratio_of_materials_used, ZH_WORDS_GETTER("RelatePro.DTO.Ratio_of_materials_used"), true, "0:0");
	//记录ID
	API_DTO_FIELD(UInt64, record_id, ZH_WORDS_GETTER("RelatePro.DTO.record_id"), true, 1);
};

class ExportRelateProDTO : public oatpp::DTO
{
	DTO_INIT(ExportRelateProDTO, DTO);

	// 记录ID
	API_DTO_FIELD(UInt64, record_id, ZH_WORDS_GETTER("RelatePro.DTO.record_id"), true, 1);
	// 工艺路线ID
	API_DTO_FIELD(UInt64, route_id, ZH_WORDS_GETTER("RelatePro.DTO.route_id"), true, 1);
	// 产品物料ID
	API_DTO_FIELD(UInt64, item_id, ZH_WORDS_GETTER("RelatePro.DTO.item_id"), true, 1);
	// 产品物料编码
	API_DTO_FIELD(String, item_code, ZH_WORDS_GETTER("RelatePro.DTO.item_code"), true, "null");
	// 产品物料名称
	API_DTO_FIELD(String, item_name, ZH_WORDS_GETTER("RelatePro.DTO.item_name"), true, "01star");
	// 产品物料单位
	API_DTO_FIELD(String, unit_of_measure, ZH_WORDS_GETTER("RelatePro.DTO.unit_of_measure"), true, "g");
	// 规格型号
	API_DTO_FIELD(String, specification, ZH_WORDS_GETTER("RelatePro.DTO.specification"), true, "null");
	// 备注
	API_DTO_FIELD(String, RPmodels, ZH_WORDS_GETTER("RelatePro.DTO.RPmodels"), false, "");
};

#endif // !_RELATEPRO_DTO_