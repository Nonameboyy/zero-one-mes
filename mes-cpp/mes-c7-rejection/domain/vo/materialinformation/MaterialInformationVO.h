#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 无名氏
 @Date: 2024/05/19 11:34:14

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
#ifndef _MATERIALINFORMATION_VO_
#define _MATERIALINFORMATION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/materialinformation/MaterialInformationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class MaterialInformationJsonVO : public JsonVO<MaterialInformationDTO::Wrapper> {
	DTO_INIT(MaterialInformationJsonVO, JsonVO<MaterialInformationDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MaterialInformationPageJsonVO : public JsonVO<MaterialInformationPageDTO::Wrapper> {
	DTO_INIT(MaterialInformationPageJsonVO, JsonVO<MaterialInformationPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MATERIALINFORMATION_VO_