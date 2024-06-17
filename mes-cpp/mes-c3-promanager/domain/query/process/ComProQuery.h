#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _PROQUERY_H_
#define _PROQUERY_H_


#include "../../GlobalInclude.h"
#include "../../../../lib-oatpp/include/domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 组成工序列表（条件分页）
 */
class ProQuery : public PageQuery
{
	//初始化
	DTO_INIT(ProQuery, PageQuery);
	//工序id
	API_DTO_FIELD_DEFAULT(UInt32, route_id, ZH_WORDS_GETTER("pro.fields.routeId"));
	////工序编码
	//API_DTO_FIELD_DEFAULT(String, process_code, ZH_WORDS_GETTER("pro.fields.proCode"));
	//////工序名称
	//API_DTO_FIELD_DEFAULT(String, process_name, ZH_WORDS_GETTER("pro.fields.proName"));
	////是否为关键工序
	//API_DTO_FIELD_DEFAULT(String, key_flag, ZH_WORDS_GETTER("pro.fields.key_flag"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROQUERY_H_