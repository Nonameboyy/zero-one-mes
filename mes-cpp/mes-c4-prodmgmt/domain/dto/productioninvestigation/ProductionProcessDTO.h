#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
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
#ifndef _PROCESS_DTO_
#define _PROCESS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ProductionProcessDTO : public oatpp::DTO
{
	DTO_INIT(ProductionProcessDTO, DTO);
	API_DTO_FIELD(String, processName, ZH_WORDS_GETTER("productionprocess.query.fields.process_name"), true, "");
};
/**
 * 示例分页传输对象
 */
class ProductionProcessPageDTO : public PageDTO<ProductionProcessDTO::Wrapper>
{
	DTO_INIT(ProductionProcessPageDTO, PageDTO<ProductionProcessDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESS_DTO_
