#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/18 17:17:51

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
#ifndef _REPAIRORDER_DETAILS_DTO_
#define _REPAIRORDER_DETAILS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ά�޵������ѯ�������
 */
class RepairorderDetailsDTO : public oatpp::DTO
{
    DTO_INIT(RepairorderDetailsDTO, DTO);

    // ά�޵�ID(Ψһ��ʶ)
    API_DTO_FIELD(UInt64, repairId, ZH_WORDS_GETTER("repairorder.query.fields.repair_id"), true, 1);
    
    // ά�޵����
    API_DTO_FIELD(String, repairCode, ZH_WORDS_GETTER("repairorder.query.fields.repair_code"), true, "REP20248120");

    // ά�޵�����
    API_DTO_FIELD(String, repairName, ZH_WORDS_GETTER("repairorder.query.fields.repair_name"), false, ZH_WORDS_GETTER("repairorder.query.fields.repair_name"));

    // �豸ID
    API_DTO_FIELD(UInt64, machineryId, ZH_WORDS_GETTER("repairorder.query.fields.machinery_id"), true, 1);

    // �豸���� / �豸���(ͬһ����˼)
    API_DTO_FIELD(String, machineryCode, ZH_WORDS_GETTER("repairorder.query.fields.machinery_code"), true, "M0048");

    // �豸����
    API_DTO_FIELD(String, machineryName, ZH_WORDS_GETTER("repairorder.query.fields.machinery_name"), true, ZH_WORDS_GETTER("repairorder.query.example.machinery_name"));

    // Ʒ��
    API_DTO_FIELD(String, machineryBrand, ZH_WORDS_GETTER("repairorder.query.fields.machinery_brand"), false, ZH_WORDS_GETTER("repairorder.query.example.machinery_brand"));

    // �豸����ID 
    API_DTO_FIELD(UInt64, machineryTypeId, ZH_WORDS_GETTER("repairorder.query.fields.machinery_type_id"), false, 1);

    // ��������
    API_DTO_FIELD(String, requireDate, ZH_WORDS_GETTER("repairorder.query.fields.require_date"), true, "1970-01-01 00:00:00");

    // ��ע
    API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repairorder.query.fields.remark"), false, ZH_WORDS_GETTER("repairorder.query.fields.remark"));
};

/**
 * ����ά�޵��괫�����
 */
class RepairorderDetailsByAddDTO : public oatpp::DTO
{
    DTO_INIT(RepairorderDetailsByAddDTO, DTO);

    // ά�޵����
    API_DTO_FIELD(String, repairCode, ZH_WORDS_GETTER("repairorder.query.fields.repair_code"), true, "REP20248120");

    // ά�޵�����
    API_DTO_FIELD(String, repairName, ZH_WORDS_GETTER("repairorder.query.fields.repair_name"), false, ZH_WORDS_GETTER("repairorder.query.fields.repair_name"));

    // �豸ID
    API_DTO_FIELD(UInt64, machineryId, ZH_WORDS_GETTER("repairorder.query.fields.machinery_id"), true, 1);

    // �豸���� / �豸���(ͬһ����˼)
    API_DTO_FIELD(String, machineryCode, ZH_WORDS_GETTER("repairorder.query.fields.machinery_code"), true, "M0048");

    // �豸����
    API_DTO_FIELD(String, machineryName, ZH_WORDS_GETTER("repairorder.query.fields.machinery_name"), true, ZH_WORDS_GETTER("repairorder.query.example.machinery_name"));

    // Ʒ��
    API_DTO_FIELD(String, machineryBrand, ZH_WORDS_GETTER("repairorder.query.fields.machinery_brand"), false, ZH_WORDS_GETTER("repairorder.query.example.machinery_brand"));

    // �豸����ID 
    API_DTO_FIELD(UInt64, machineryTypeId, ZH_WORDS_GETTER("repairorder.query.fields.machinery_type_id"), false, 1);

    // ��������
    API_DTO_FIELD(String, requireDate, ZH_WORDS_GETTER("repairorder.query.fields.require_date"), true, "1970-01-01 00:00:00");

    // ��ע
    API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repairorder.query.fields.remark"), false, ZH_WORDS_GETTER("repairorder.query.fields.remark"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRORDER_DETAILS_DTO_