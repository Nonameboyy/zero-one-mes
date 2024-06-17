#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/18 15:24:36

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
#ifndef _REPAIRORDER_VO_
#define _REPAIRORDER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/repairorder/RepairorderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

///**
// * 维修单显示JsonVO，用于响应给客户端的Json对象
// */
//class RepairorderJsonVO : public JsonVO<RepairorderDTO::Wrapper> {
//    DTO_INIT(RepairorderJsonVO, JsonVO<RepairorderDTO::Wrapper>);
//};

/**
 * 维修单分页显示JsonVO，用于响应给客户端的Json对象
 */
class RepairorderPageJsonVO : public JsonVO<RepairorderPageDTO::Wrapper> {
    DTO_INIT(RepairorderPageJsonVO, JsonVO<RepairorderPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REPAIRORDER_VO_