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
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class DefectDTO : public oatpp::DTO
{
	DTO_INIT(DefectDTO, DTO);
	// 编号
	DTO_FIELD(String, defect_code);
	DTO_FIELD_INFO(defect_code) {
		info->description = ZH_WORDS_GETTER("defect.field.defect_code");
	}
	// 缺陷描述
	DTO_FIELD(String, defect_name);
	DTO_FIELD_INFO(defect_name) {
		info->description = ZH_WORDS_GETTER("defect.field.defect_name");
	}
	// 检测项类型
	DTO_FIELD(String, index_type);
	DTO_FIELD_INFO(index_type) {
		info->description = ZH_WORDS_GETTER("defect.field.index_type");
	}
	// 缺陷等级
	DTO_FIELD(String, defect_level);
	DTO_FIELD_INFO(defect_level) {
		info->description = ZH_WORDS_GETTER("defect.field.defect_level");
	}
};


/**
 * 示例分页传输对象
 */
class DefectPageDTO : public PageDTO<DefectDTO::Wrapper>
{
	DTO_INIT(DefectPageDTO, PageDTO<DefectDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DEFECT_DTO_