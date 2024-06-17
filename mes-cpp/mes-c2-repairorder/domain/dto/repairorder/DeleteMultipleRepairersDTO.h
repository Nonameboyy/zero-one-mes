#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/18 22:06:43

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
#ifndef _DELETE_MULTIPLE_REPAIRERS_DTO_
#define _DELETE_MULTIPLE_REPAIRERS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 删除多个维修单 传输对象
 */
class DeleteMultipleRepairersDTO : public oatpp::DTO
{
    DTO_INIT(DeleteMultipleRepairersDTO, DTO);

    // (多个)维修单ID(唯一标识)
    API_DTO_FIELD_DEFAULT(oatpp::List<oatpp::UInt64>, repairIdList, ZH_WORDS_GETTER("repairorder.query.fields.repair_id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETE_MULTIPLE_REPAIRERS_DTO_