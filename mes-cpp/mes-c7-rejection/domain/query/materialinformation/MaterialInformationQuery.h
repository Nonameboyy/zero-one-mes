#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 无名氏
 @Date: 2024/05/19 11:36:29

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
#ifndef _MATERIALINFORMATION_QUERY_
#define _MATERIALINFORMATION_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class MaterialInformationQuery : public PageQuery
{
	DTO_INIT(MaterialInformationQuery, PageQuery);
	// 退料单ID
	DTO_FIELD(UInt64, rt_id);
	DTO_FIELD_INFO(rt_id) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.rt_id");
	}
	//退料单编号
	DTO_FIELD(String, rt_code);
	DTO_FIELD_INFO(rt_code) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.rt_code");
	}
	// 退料单名称
	DTO_FIELD(String, rt_name);
	DTO_FIELD_INFO(rt_name) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.rt_name");
	}

	//生产工单ID
	DTO_FIELD(UInt64, workorder_id);
	DTO_FIELD_INFO(workorder_id) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.workororder_id");
	}
	// 生产工单编号
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.workororder_code");
	}


	// 接收仓库ID
	DTO_FIELD(UInt64, warehouse_id);
	DTO_FIELD_INFO(warehouse_id) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.warehouse_id");
	}
	// 接收仓库编码
	DTO_FIELD(String, warehouse_code);
	DTO_FIELD_INFO(warehouse_code) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.warehouse_code");
	}
	// 接收仓库名称
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.warehouse_name");
	}

	// 库区ID
	DTO_FIELD(UInt64, location_id);
	DTO_FIELD_INFO(location_id) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.location_id");
	}
	// 库区编码
	DTO_FIELD(String, location_code);
	DTO_FIELD_INFO(location_code) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.location_code");
	}
	// 库区名称
	DTO_FIELD(String, location_name);
	DTO_FIELD_INFO(location_name) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.location_name");
	}

	// 库位ID
	DTO_FIELD(UInt64, area_id);
	DTO_FIELD_INFO(area_id) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.area_id");
	}
	// 库位编码
	DTO_FIELD(String, area_code);
	DTO_FIELD_INFO(area_code) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.area_code");
	}
	// 库位名称
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.area_name");
	}

	//退料日期
	DTO_FIELD(String, rt_date);
	DTO_FIELD_INFO(rt_date) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.rt_date");
	}
	//备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("materialinformation.field.remark");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MATERIALINFORMATION_QUERY_