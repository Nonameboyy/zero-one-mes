#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/18/ 23:00

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
#ifndef _Repaircontent_QUERY_
#define _Repaircontent_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 维修内容条件分页查询对象
 */
class RepaircontentQuery : public PageQuery
{
	DTO_INIT(RepaircontentQuery, PageQuery);
	
	//行id
	API_DTO_FIELD(UInt64, line_id, ZH_WORDS_GETTER("repaircontent.query.field.line_id"), true, 1);
	// 维修单ID(唯一标识)
	API_DTO_FIELD(UInt64, repair_id, ZH_WORDS_GETTER("repaircontent.query.field.repair_id"), true, 1);
	//项目名称
	API_DTO_FIELD(String, subject_name, ZH_WORDS_GETTER("repaircontent.query.field.repair_name"), true, ZH_WORDS_GETTER("repaircontent.default.subject_name"));
	//项目id
	API_DTO_FIELD(UInt64, subject_id, ZH_WORDS_GETTER("repaircontent.query.field.subject_id"), true, 2);

};

//class RepaircontentDetailsQuery : public PageQuery
//{
//	DTO_INIT(RepaircontentQuery, PageQuery);
//
//	// 维修单ID(唯一标识)
//	API_DTO_FIELD_DEFAULT(UInt64, repair_id, ZH_WORDS_GETTER("repaircontent.query.fields.repair_id"), true, 0LLU);
//
//};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Repaircontent_QUERY_