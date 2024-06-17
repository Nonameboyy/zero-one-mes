#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xingshoulang
 @Date: 2024.5.20 14:53

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
#ifndef _PROCESS_LIST_QUERY_
#define _PROCESS_LIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 分页查询 工序列表（条件 + 分页）
*/
class ProListQuery : public PageQuery
{
	DTO_INIT(ProListQuery, PageQuery);
	// 工序编码
	API_DTO_FIELD_DEFAULT(String, processCode, ZH_WORDS_GETTER("process.fields.processCode"));
	// 工序名称
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("process.fields.processName"));
	// 是否启用
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("process.fields.enableFlag"), true, "Y");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESS_LIST_QUERY_