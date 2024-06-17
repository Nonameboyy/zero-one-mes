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
#ifndef _PROCESS_QUERY_
#define _PROCESS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class ProcessQuery : public PageQuery
{
	DTO_INIT(ProcessQuery, PageQuery);
	// 工艺路线编号
	DTO_FIELD(String, route_code);
	DTO_FIELD_INFO(route_code) {
		info->description = ZH_WORDS_GETTER("process.field.code");
	}
	// 工艺路线名称
	DTO_FIELD(String, route_name);
	DTO_FIELD_INFO(route_name) {
		info->description = ZH_WORDS_GETTER("process.field.name");
	}
	// 是否启用
	DTO_FIELD(String, enable_flag);
	DTO_FIELD_INFO(enable_flag) {
		info->description = ZH_WORDS_GETTER("process.field.flag");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESS_QUERY_