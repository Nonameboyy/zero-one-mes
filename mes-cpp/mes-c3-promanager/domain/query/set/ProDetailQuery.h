#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xingshoulang
 @Date: 2024.5.21 3:34

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
#ifndef _PROCESS_DETAIL_QUERY_
#define _PROCESS_DETAIL_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工序详情 查询
 */
class ProDetailQuery : public oatpp::DTO
{
	DTO_INIT(ProDetailQuery, DTO);
	// 工序编码
	API_DTO_FIELD_DEFAULT(UInt64, processId, ZH_WORDS_GETTER("process.fields.processId"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESS_DETAIL_QUERY_