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
#ifndef _ADDDELMOD_DTO_
#define _ADDDELMOD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class AddDelModDTO : public oatpp::DTO
{
	DTO_INIT(AddDelModDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, warehouse_id);
	DTO_FIELD_INFO(warehouse_id) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.warehouse_id");
	}
	// 仓库编码
	DTO_FIELD(String, warehouse_code);
	DTO_FIELD_INFO(warehouse_code) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.warehouse_code");
	}
	// 仓库名称
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.warehouse_name");
	}
	// 位置
	DTO_FIELD(String, location);
	DTO_FIELD_INFO(location) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.location");
	}
	// 面积
	DTO_FIELD(Float64, area);
	DTO_FIELD_INFO(area) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.area");
	}
	// 负责人
	DTO_FIELD(String, charge);
	DTO_FIELD_INFO(charge) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.charge");
	}
	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.remark");
	}
};

/**
 * 示例分页传输对象
 */
class AddDelModPageDTO : public PageDTO<AddDelModDTO::Wrapper>
{
	DTO_INIT(AddDelModPageDTO, PageDTO<AddDelModDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDDELMOD_DTO_