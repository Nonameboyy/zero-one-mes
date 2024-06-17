#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _PRODORDER_VO_
#define _PRODORDER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ProdOrder/ProdOrderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示生产任务列表JsonVO，用于响应给客户端的Json对象
 */
class ProdOrderAddJsonVO : public JsonVO<ProdOrderDTO::Wrapper> {
	DTO_INIT(ProdOrderAddJsonVO, JsonVO<ProdOrderDTO::Wrapper>);
};

/**
 * 分页显示生产任务列表JsonVO，用于响应给客户端的Json对象
 */
class ProdOrderPageJsonVO : public JsonVO<ProdOrderQueryDTO::Wrapper> {
	DTO_INIT(ProdOrderPageJsonVO, JsonVO<ProdOrderQueryDTO::Wrapper>);
};

//显示生产任务列表树JsonVO
class ProdOrderQueryTreeJsonVO : public JsonVO<List<ProdOrderQueryTreeDTO::Wrapper>>
{
	DTO_INIT(ProdOrderQueryTreeJsonVO, JsonVO<List<ProdOrderQueryTreeDTO::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	ProdOrderQueryTreeJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PRODORDER_VO_