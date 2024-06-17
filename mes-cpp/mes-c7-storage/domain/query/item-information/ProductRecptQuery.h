#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _PRODUCT_RECPT_QUERY_
#define _PRODUCT_RECPT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 产品入库分页查询对象:(recpt_code,recpt_name,workorder_code,warehouse_name)
 */
class ProductRecptQuery : public PageQuery
{
	DTO_INIT(ProductRecptQuery, PageQuery);
	// 入库单编号
	DTO_FIELD(String, recpt_code);
	DTO_FIELD_INFO(recpt_code) {
		info->description = ZH_WORDS_GETTER("product-recpt.field.recpt_code");
	}
	// 入库单名称
	DTO_FIELD(String, recpt_name);
	DTO_FIELD_INFO(recpt_name) {
		info->description = ZH_WORDS_GETTER("product-recpt.field.recpt_name");
	}
	// 生产工单编码
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("product-recpt.field.workorder_code");
	}
	// 仓库名称
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("product-recpt.field.warehouse_name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRODUCT_RECPT_QUERY_