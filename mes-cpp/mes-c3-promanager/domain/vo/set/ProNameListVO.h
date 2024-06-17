#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xingshoulang
 @Date: 2024.5.21 3:12

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
#ifndef _PRONAMELISTVO_H_
#define _PRONAMELISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/set/ProNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个工序名称列表显示JsonVO对象，用于响应给客户端
 */

class ProNameListJsonVO : public JsonVO<ListDTO::Wrapper>
{
	DTO_INIT(ProNameListJsonVO, JsonVO< ListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _PRONAMELISTVO_H_