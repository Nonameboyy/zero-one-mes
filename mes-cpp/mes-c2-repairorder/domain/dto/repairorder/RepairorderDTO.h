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
 * ά�޵��������
 */
class RepairorderDTO : public oatpp::DTO
{
    DTO_INIT(RepairorderDTO, DTO);

    // ά�޵�ID(Ψһ��ʶ)
    API_DTO_FIELD(UInt64, repairId, ZH_WORDS_GETTER("repairorder.query.fields.repair_id"), true, 1);
    
    // ά�޵����
    API_DTO_FIELD(String, repairCode, ZH_WORDS_GETTER("repairorder.query.fields.repair_code"), true, "");

    // ά�޵�����
    API_DTO_FIELD(String, repairName, ZH_WORDS_GETTER("repairorder.query.fields.repair_name"), true, "");
    
    // �豸ID
    API_DTO_FIELD(UInt64, machineryId, ZH_WORDS_GETTER("repairorder.query.fields.machinery_id"), true, 1);

    // �豸����
    API_DTO_FIELD(String, machineryCode, ZH_WORDS_GETTER("repairorder.query.fields.machinery_code"), true, "");

    // �豸����
    API_DTO_FIELD(String, machineryName, ZH_WORDS_GETTER("repairorder.query.fields.machinery_name"), true, "");

    // ��������
    API_DTO_FIELD(String, requireDate, ZH_WORDS_GETTER("repairorder.query.fields.require_date"), true, "");

    // ά���������
    API_DTO_FIELD(String, finishDate, ZH_WORDS_GETTER("repairorder.query.fields.finish_date"), true, "");

    // ��������
    API_DTO_FIELD(String, confirmDate, ZH_WORDS_GETTER("repairorder.query.fields.confirm_date"), true, "");

    // ά�޽��
    API_DTO_FIELD(String, repairResult, ZH_WORDS_GETTER("repairorder.query.fields.repair_result"), true, "");

    // ά����Ա
    API_DTO_FIELD(String, acceptedBy, ZH_WORDS_GETTER("repairorder.query.fields.accepted_by"), true, "");

    // ������Ա
    API_DTO_FIELD(String, confirmBy, ZH_WORDS_GETTER("repairorder.query.fields.confirm_by"), true, "");

    // ����״̬
    API_DTO_FIELD(String, status, ZH_WORDS_GETTER("repairorder.query.fields.status"), true, "");
};

/**
 * ά�޵���ҳ�������
 */
class RepairorderPageDTO : public PageDTO<RepairorderDTO::Wrapper>
{
    DTO_INIT(RepairorderPageDTO, PageDTO<RepairorderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRORDER_DTO_