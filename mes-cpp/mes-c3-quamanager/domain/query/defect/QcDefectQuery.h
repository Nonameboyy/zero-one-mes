#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _QC_DEFECT_QUERY_
#define _QC_DEFECT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class QcDefectQuery : public PageQuery
{
	DTO_INIT(QcDefectQuery, PageQuery);
	// 缺陷描述
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

#include OATPP_CODEGEN_END(DTO)
#endif // !_DEFECT_QUERY_