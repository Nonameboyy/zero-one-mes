#pragma once
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
#ifndef __MODIFY_PLAN_STATUS_DTO_H_
#define __MODIFY_PLAN_STATUS_DTO_H_
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ModifyPlanStatusDto : public oatpp::DTO
{
	DTO_INIT(ModifyPlanStatusDto, DTO);
	//计划ID
	API_DTO_FIELD(UInt64, id, ZH_WORDS_GETTER("modifyplanstatus.fields.planid"), true, 1);
	//计划状态（停用或启用，可修改）
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("modifyplanstatus.fields.status"), true, nullptr);
	////更新者
	//API_DTO_FIELD(String, updateby, ZH_WORDS_GETTER("modifyplanstatus.fields.updateby"), true, "");
	////更新时间
	//API_DTO_FIELD(String, updatetime, ZH_WORDS_GETTER("modifyplanstatus.fields.updatetime"), true, "");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_