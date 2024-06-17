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
#ifndef _ADD_DTO_H_
#define _ADD_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 项目列表
 */
class AddDTO : public oatpp::DTO
{
	DTO_INIT(AddDTO, DTO);
	// 计划编码
	API_DTO_FIELD_DEFAULT(String, planCode, ZH_WORDS_GETTER("add-mj.fields.pid"));
	//计划名称
	API_DTO_FIELD_DEFAULT(String, planName, ZH_WORDS_GETTER("add-mj.fields.pname"));
	//计划类型
	API_DTO_FIELD_DEFAULT(String, planType, ZH_WORDS_GETTER("add-mj.fields.ptype"));

	//频率
	API_DTO_FIELD_DEFAULT(String, cycleType, ZH_WORDS_GETTER("add-mj.fields.ctype"));
	//次数
	API_DTO_FIELD_DEFAULT(UInt32, cycleCount, ZH_WORDS_GETTER("add-mj.fields.ccount"));
	//开始日期
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("add-mj.fields.sdate"));
	//结束日期
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("add-mj.fields.edate"));
	//状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("add-mj.fields.status"));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("add-mj.fields.remark"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_