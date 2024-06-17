#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2022/10/25 10:59:38

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _BOM_DTO_
#define _BOM_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ExportBomOrderDTO : public oatpp::DTO
{
	DTO_INIT(ExportBomOrderDTO, DTO);
	API_DTO_FIELD(Int32, itemId, ZH_WORDS_GETTER("productionorder.query.fields.item_id"), true, 0);
	API_DTO_FIELD(Int32, workOrderId, ZH_WORDS_GETTER("productionorder.query.fields.workorder_id"), true, 0);
	API_DTO_FIELD(String, itemName, ZH_WORDS_GETTER("productionorder.query.fields.item_name"), true, "");
	API_DTO_FIELD(String, itemCode, ZH_WORDS_GETTER("productionorder.query.fields.item_code"), true, "");
	API_DTO_FIELD(String, itemSpc, ZH_WORDS_GETTER("productionorder.query.fields.item_spc"), true, "");
	API_DTO_FIELD(String, unitOfMeasure, ZH_WORDS_GETTER("productionorder.query.fields.unit_of_measure"), true, "");
	API_DTO_FIELD(String, itemOrProduct, ZH_WORDS_GETTER("productionorder.query.fields.item_or_product"), true, "");
	API_DTO_FIELD(Float64, quantity, ZH_WORDS_GETTER("productionorder.query.fields.quantity"), true, 0.0);
};

/**
 * 示例分页传输对象
 */
class ExportBomOrderPageDTO : public PageDTO<ExportBomOrderDTO::Wrapper>
{
	DTO_INIT(ExportBomOrderPageDTO, PageDTO<ExportBomOrderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BOM_DTO_
