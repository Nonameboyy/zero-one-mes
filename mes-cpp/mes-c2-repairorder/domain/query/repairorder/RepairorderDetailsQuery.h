#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/18 17:09:24

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
#ifndef _REPAIRORDER_DETAILS_QUERY_
#define _REPAIRORDER_DETAILS_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 维修单详情查询对象
 */
class RepairorderDetailsQuery : public oatpp::DTO
{
    DTO_INIT(RepairorderDetailsQuery, DTO);

    // 维修单ID(唯一标识)
    API_DTO_FIELD(UInt64, repairId, ZH_WORDS_GETTER("repairorder.query.fields.repair_id"), true, 1);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRORDER_DETAILS_QUERY_