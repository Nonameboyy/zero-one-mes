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
#ifndef _ORDER_DTO_
#define _ORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ExportOrderDTO : public oatpp::DTO
{
	DTO_INIT(ExportOrderDTO, DTO);
	API_DTO_FIELD(String, workOrderCode, ZH_WORDS_GETTER("productionorder.query.fields.workorder_code"),true,"");
	API_DTO_FIELD(String, workOrderName, ZH_WORDS_GETTER("productionorder.query.fields.workorder_name"), true, "");
	API_DTO_FIELD(String, workOrderType, ZH_WORDS_GETTER("productionorder.query.fields.workorder_type"), true, "");
	API_DTO_FIELD(String, orderSource, ZH_WORDS_GETTER("productionorder.query.fields.order_source"), true, "");
	API_DTO_FIELD(String, sourceCode, ZH_WORDS_GETTER("productionorder.query.fields.source_code"), true, "");
	API_DTO_FIELD(Int32, productId, ZH_WORDS_GETTER("productionorder.query.fields.product_id"),true,0);
	API_DTO_FIELD(String, productCode, ZH_WORDS_GETTER("productionorder.query.fields.product_code"),true,"");
	API_DTO_FIELD(String, productName, ZH_WORDS_GETTER("productionorder.query.fields.product_name"),true,"");
	API_DTO_FIELD(String, productSpc, ZH_WORDS_GETTER("productionorder.query.fields.product_spc"), true, "");
	API_DTO_FIELD(String, unitOfMeasure, ZH_WORDS_GETTER("productionorder.query.fields.unit_of_measure"), true, "");
	API_DTO_FIELD(String, batchCode, ZH_WORDS_GETTER("productionorder.query.fields.batch_code"), true, "");
	API_DTO_FIELD(Float64, pQuantity, ZH_WORDS_GETTER("productionorder.query.fields.pquantity"),true,0.00);
	API_DTO_FIELD(Float64, quantityProduced, ZH_WORDS_GETTER("productionorder.query.fields.quantity_produced"), true, 0.00);
	API_DTO_FIELD(Float64, quantityChanged, ZH_WORDS_GETTER("productionorder.query.fields.quantity_changed"), true, 0.00);
	API_DTO_FIELD(Float64, quantityScheduled, ZH_WORDS_GETTER("productionorder.query.fields.quantity_scheduled"), true, 0.00);
	API_DTO_FIELD(Int32, clientId, ZH_WORDS_GETTER("productionorder.query.fields.client_id"), true, 0);
	API_DTO_FIELD(String, clientCode, ZH_WORDS_GETTER("productionorder.query.fields.client_code"), true, "");
	API_DTO_FIELD(String, clientName, ZH_WORDS_GETTER("productionorder.query.fields.client_name"), true, "");
	API_DTO_FIELD(Int32, vendorId, ZH_WORDS_GETTER("productionorder.query.fields.vendor_id"), true, 0);
	API_DTO_FIELD(String, vendorCode, ZH_WORDS_GETTER("productionorder.query.fields.vendor_code"), true, "");
	API_DTO_FIELD(String, vendorName, ZH_WORDS_GETTER("productionorder.query.fields.vendor_name"), true, "");
	API_DTO_FIELD(String, finishDate, ZH_WORDS_GETTER("productionorder.query.fields.finish_date"), true, "");
	API_DTO_FIELD(String, requestDate, ZH_WORDS_GETTER("productionorder.query.fields.request_date"), true, "");
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("productionorder.query.fields.status"), true, "");
};

/**
 * 示例分页传输对象
 */
class ExportOrderPageDTO : public PageDTO<ExportOrderDTO::Wrapper>
{
	DTO_INIT(ExportOrderPageDTO, PageDTO<ExportOrderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDER_DTO_
