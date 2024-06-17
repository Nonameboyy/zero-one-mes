#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/18 14:58:34

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
#ifndef _REPAIRORDER_DTO_
#define _REPAIRORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 维修单传输对象
 */
class RepairorderDTO : public oatpp::DTO
{
    DTO_INIT(RepairorderDTO, DTO);

    // 维修单ID(唯一标识)
    API_DTO_FIELD(UInt64, repairId, ZH_WORDS_GETTER("repairorder.query.fields.repair_id"), true, 1);
    
    // 维修单编号
    API_DTO_FIELD(String, repairCode, ZH_WORDS_GETTER("repairorder.query.fields.repair_code"), true, "");

    // 维修单名称
    API_DTO_FIELD(String, repairName, ZH_WORDS_GETTER("repairorder.query.fields.repair_name"), true, "");
    
    // 设备ID
    API_DTO_FIELD(UInt64, machineryId, ZH_WORDS_GETTER("repairorder.query.fields.machinery_id"), true, 1);

    // 设备编码
    API_DTO_FIELD(String, machineryCode, ZH_WORDS_GETTER("repairorder.query.fields.machinery_code"), true, "");

    // 设备名称
    API_DTO_FIELD(String, machineryName, ZH_WORDS_GETTER("repairorder.query.fields.machinery_name"), true, "");

    // 报修日期
    API_DTO_FIELD(String, requireDate, ZH_WORDS_GETTER("repairorder.query.fields.require_date"), true, "");

    // 维修完成日期
    API_DTO_FIELD(String, finishDate, ZH_WORDS_GETTER("repairorder.query.fields.finish_date"), true, "");

    // 验收日期
    API_DTO_FIELD(String, confirmDate, ZH_WORDS_GETTER("repairorder.query.fields.confirm_date"), true, "");

    // 维修结果
    API_DTO_FIELD(String, repairResult, ZH_WORDS_GETTER("repairorder.query.fields.repair_result"), true, "");

    // 维修人员
    API_DTO_FIELD(String, acceptedBy, ZH_WORDS_GETTER("repairorder.query.fields.accepted_by"), true, "");

    // 验收人员
    API_DTO_FIELD(String, confirmBy, ZH_WORDS_GETTER("repairorder.query.fields.confirm_by"), true, "");

    // 单据状态
    API_DTO_FIELD(String, status, ZH_WORDS_GETTER("repairorder.query.fields.status"), true, "");
};

/**
 * 维修单分页传输对象
 */
class RepairorderPageDTO : public PageDTO<RepairorderDTO::Wrapper>
{
    DTO_INIT(RepairorderPageDTO, PageDTO<RepairorderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRORDER_DTO_