#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _WAREHOUSE_AREA_DTO_
#define _WAREHOUSE_AREA_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 库区列表传输对象,每个对象对应一条列表项
 */
class warehouseAreaListDTO : public oatpp::DTO
{
	DTO_INIT(warehouseAreaListDTO, DTO);
	//库区ID-必填
	API_DTO_FIELD(UInt64, area_id, ZH_WORDS_GETTER("warehouse-area.field.id"), true, 1);
	//编码-必填
	API_DTO_FIELD(String, area_code, ZH_WORDS_GETTER("warehouse-area.field.code"), true, "default code");
	//名称-必填
	API_DTO_FIELD(String, area_name, ZH_WORDS_GETTER("warehouse-area.field.name"), true,"default name");
	//关联的仓库ID-必填
	API_DTO_FIELD(UInt64, warehouse_id, ZH_WORDS_GETTER("warehouse-area.field.warehouse-id"), true, 1);
	//面积
	API_DTO_FIELD_DEFAULT(Int32, area, ZH_WORDS_GETTER("warehouse-area.field.area"));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("warehouse-area.field.remark"));
	////使用demo/sample里的定义方式
	////库区编号
	//DTO_FIELD(UInt64, area_id);
	//DTO_FIELD_INFO(area_id){ info->description = ZH_WORDS_GETTER("warehouse.field.id"); }
	////编码
	//DTO_FIELD(String, area_code);
	//DTO_FIELD_INFO(area_code) { info->description = ZH_WORDS_GETTER("warehouse.field.code"); }
	////名称
	//DTO_FIELD(String, area_name);
	//DTO_FIELD_INFO(area_name) { info->description = ZH_WORDS_GETTER("warehouse.field.name"); }
	////面积
	//DTO_FIELD(Int32, area);
	//DTO_FIELD_INFO(area) { info->description = ZH_WORDS_GETTER("warehouse.field.area"); }
	////备注
	//DTO_FIELD(String, remark);
	//DTO_FIELD_INFO(remark) { info->description = ZH_WORDS_GETTER("warehouse.field.remark"); }
};
/**
 * 库区分页传输对象
 */
class warehousePageDTO : public PageDTO<warehouseAreaListDTO::Wrapper>
{
	DTO_INIT(warehousePageDTO, PageDTO<warehouseAreaListDTO::Wrapper>);
};

/**
 * 用于删除库区时传输多个库区id
 */
//class deleteIdsDTO :public oatpp::DTO
//{
//	DTO_INIT(deleteIdsDTO, DTO);
//	//库区ID列表:至少要传一个id
//	API_DTO_FIELD(list<UInt64>, area_ids, ZH_WORDS_GETTER("warehouse-area.field.id"),true, std::list<UInt64>{1})
//};
#include OATPP_CODEGEN_END(DTO)
#endif // 
