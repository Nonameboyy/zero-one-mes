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
#ifndef _WAREHOUSE_AREA_QUERY_
#define _WAREHOUSE_AREA_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 库区分页查询对象:将传给后端的查询封装成查询类,包含属性：库区名称
 */
class WarehouseAreaQuery : public PageQuery
{
	DTO_INIT(WarehouseAreaQuery, PageQuery);
	//定义库区名称,不带默认值
	API_DTO_FIELD_DEFAULT(String, warehouseAreaName, ZH_WORDS_GETTER("warehouse-area.field.name"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif 