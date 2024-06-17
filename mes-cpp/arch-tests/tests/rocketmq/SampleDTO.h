#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/09 15:25:20

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
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class SampleDTO : public oatpp::DTO
{
	DTO_INIT(SampleDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, id);
	// 姓名
	DTO_FIELD(String, name);
	// 年龄
	DTO_FIELD(Int32, age);
	// 性别
	DTO_FIELD(String, sex);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_