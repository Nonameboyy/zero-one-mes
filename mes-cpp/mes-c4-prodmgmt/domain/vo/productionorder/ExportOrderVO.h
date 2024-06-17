#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
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
#ifndef _ORDER_VO_
#define _ORDER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/productionorder/ExportOrderDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ExportOrderJsonVO : public JsonVO<ExportOrderDTO::Wrapper> {
	DTO_INIT(ExportOrderJsonVO, JsonVO<ExportOrderDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ExportOrderPageJsonVO : public JsonVO<ExportOrderPageDTO::Wrapper> {
	DTO_INIT(ExportOrderPageJsonVO, JsonVO<ExportOrderPageDTO::Wrapper>);
};
#endif // !_ORDER_VO_