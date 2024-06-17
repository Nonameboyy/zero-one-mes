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
#ifndef _GETAREADETAILS_DTO_
#define  _GETAREADETAILS_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//分页查询对象

class GetAreaDetailsDTO : public oatpp::DTO
{
	DTO_INIT(GetAreaDetailsDTO, DTO);
	//库区ID
	API_DTO_FIELD_DEFAULT(UInt64, location_id, ZH_WORDS_GETTER("location.field.location_id"));
	// 库区编码
	API_DTO_FIELD_DEFAULT(String, location_code, ZH_WORDS_GETTER("location.field.location_code"));
	// 库区名称
	API_DTO_FIELD_DEFAULT(String, location_name, ZH_WORDS_GETTER("location.field.location_name"));
};
class GetAreaDetailsPageDTO :public PageDTO<GetAreaDetailsDTO::Wrapper> 
{
	DTO_INIT(GetAreaDetailsPageDTO, PageDTO<GetAreaDetailsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_