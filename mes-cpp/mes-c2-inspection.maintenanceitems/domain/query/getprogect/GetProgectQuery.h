#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ksw12355
 @Date: 2024/5/20

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
#ifndef _GETPROGECTQUERY_H_
#define _GETPROGECTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取点检/保养项目列表（条件+分页）
 */
class GetProgectQuery : public  PageQuery
{
	DTO_INIT(GetProgectQuery, PageQuery);
	//项目编码
	API_DTO_FIELD_DEFAULT(String, pCode, ZH_WORDS_GETTER("project.fields.pcode"));
	//项目名称
	API_DTO_FIELD_DEFAULT(String, pName, ZH_WORDS_GETTER("project.fields.pname"));
	//项目类型
	API_DTO_FIELD_DEFAULT(String, pType, ZH_WORDS_GETTER("project.fields.ptype"));

};

/**
 * 获取项目详情
 */
class GetProgectDetailQuery : public  oatpp::DTO
{
	DTO_INIT(GetProgectDetailQuery, DTO);
	//项目id
	API_DTO_FIELD(UInt64, pId, ZH_WORDS_GETTER("project.fields.pid"), true, 1);

};


#include OATPP_CODEGEN_END(DTO)
#endif 


