#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/18 23:14

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
#ifndef _DELETE_MULTI_REPAIRCONTENT_DTO_
#define _DELETE_MULTI_REPAIRCONTENT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//删除多个维修单内容  传输对象
class DeleteMultiRepaircontentDTO :public oatpp::DTO
{
	DTO_INIT(DeleteMultiRepaircontentDTO, DTO);


	//(多个)需要删除的行id（主键）
	API_DTO_FIELD_DEFAULT(oatpp::List<oatpp::UInt64>, line_idList, ZH_WORDS_GETTER("repaircontent.field.line_id"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETE_MULTI_REPAIRCONTENT_DTO_