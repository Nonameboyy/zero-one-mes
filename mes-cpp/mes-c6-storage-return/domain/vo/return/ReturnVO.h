#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _RETURNVO_H_
#define _RETURNVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/return/ReturnDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个单据简要信息显示JsonVO对象，用于响应给客户端
 */
class ReturnJsonVO : public JsonVO<ReturnDTO::Wrapper>
{
	DTO_INIT(ReturnJsonVO, JsonVO<ReturnDTO::Wrapper>);
};
/**
* 定义一个单据详细信息显示JsonVO对象
*/
class ReturnDetailJsonVO : public JsonVO<ReturnDetailDTO::Wrapper>
{
	DTO_INIT(ReturnDetailJsonVO, JsonVO<ReturnDetailDTO::Wrapper>);
};
/**
 * 定义一个单据信息分页显示JsonVO对象，用于响应给客户端
 */
class ReturnPageJsonVO : public JsonVO<ReturnPageDTO::Wrapper>
{
	DTO_INIT(ReturnPageJsonVO, JsonVO<ReturnPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 