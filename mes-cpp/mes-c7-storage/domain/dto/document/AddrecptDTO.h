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
#ifndef _ADDRECPT_DTO_
#define _ADDRECPT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class AddrecptDTO : public oatpp::DTO
{
	DTO_INIT(AddrecptDTO, DTO);
	//// 入库单ID
	//DTO_FIELD(UInt64, recpt_id);
	//DTO_FIELD_INFO(recpt_id) {
	//	info->description = ZH_WORDS_GETTER("recpt.field.id");
	//}
	// 入库单编号
	DTO_FIELD(String, recpt_code);
	DTO_FIELD_INFO(recpt_code) {
		info->description = ZH_WORDS_GETTER("recpt.field.code");
	}
	// 入库单名称
	DTO_FIELD(String, recpt_name);
	DTO_FIELD_INFO(recpt_name) {
		info->description = ZH_WORDS_GETTER("recpt.field.name");
	}
	//// 生产工单id
	//DTO_FIELD(UInt64,workorder_id);
	//DTO_FIELD_INFO(workorder_id) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.id");
	//}
	//生产工单编码
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("warehouse.field.code");
	}
	//生产工单名称
	DTO_FIELD(String,workorder_name);
	DTO_FIELD_INFO(workorder_name) {
		info->description = ZH_WORDS_GETTER("warehouse.field.name");
	}
	//入库日期
	DTO_FIELD(String, recpt_date);
	DTO_FIELD_INFO(recpt_date) {
		info->description = ZH_WORDS_GETTER("recpt.field.date");
	}
	//备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("recpt.field.remark");
	}
	//产品物料id
	DTO_FIELD(UInt64,item_id );
	DTO_FIELD_INFO(item_id) {
		info->description = ZH_WORDS_GETTER("recpt.field.item_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_