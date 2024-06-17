#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/18 14:25:49

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
#ifndef _REPAIRORDER_QUERY_
#define _REPAIRORDER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ά�޵���ҳ��ѯ����
 */
class RepairorderQuery : public PageQuery
{
    DTO_INIT(RepairorderQuery, PageQuery);

    // ά�޵����
    API_DTO_FIELD_DEFAULT(String, repairCode, ZH_WORDS_GETTER("repairorder.query.fields.repair_code"));

    // ά�޵�����
    API_DTO_FIELD_DEFAULT(String, repairName, ZH_WORDS_GETTER("repairorder.query.fields.repair_name"));

    // �豸����
    API_DTO_FIELD_DEFAULT(String, machineryCode, ZH_WORDS_GETTER("repairorder.query.fields.machinery_code"));

    // �豸����
    API_DTO_FIELD_DEFAULT(String, machineryName, ZH_WORDS_GETTER("repairorder.query.fields.machinery_name"));

    // ά�޽��
    API_DTO_FIELD_DEFAULT(String, repairResult, ZH_WORDS_GETTER("repairorder.query.fields.repair_result"));

    // ����״̬
    API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("repairorder.query.fields.status"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRORDER_QUERY_