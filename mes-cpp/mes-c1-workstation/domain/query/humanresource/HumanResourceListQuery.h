#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 11:01:02

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
#ifndef _HUMANRESOURCELISTQUERY_H_
#define _HUMANRESOURCELISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 人力资源查询
 */
class HumanResourceListQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(HumanResourceListQuery, PageQuery);
	// 工作站id
	API_DTO_FIELD_DEFAULT(UInt64, workstationId, ZH_WORDS_GETTER("post.fields.workstationid"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 