#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/25 13:50:32

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
#ifndef _REPAIRORDER_DAO_
#define _REPAIRORDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_repair/DvRepairDO.h"
#include "../../domain/query/repairorder/RepairorderQuery.h"
#include "../../domain/query/repairorder/RepairorderDetailsQuery.h"

/**
 * �豸ά�޵������ݿ����ʵ��
 */
class RepairorderDAO : public BaseDAO
{
public:
    // ͳ����������
    uint64_t count(const RepairorderQuery::Wrapper& query);
    uint64_t count(const RepairorderDetailsQuery::Wrapper& query);
    // ��ҳ��ѯ����
    list<DvRepairDO> selectWithPage(const RepairorderQuery::Wrapper& query);
    // ͨ��id��ѯ����
    list<DvRepairDO> selectById(const uint64_t& id);
    // ��������
    uint64_t insert(const DvRepairDO& iObj);
    // �޸�����
    int update(const DvRepairDO& uObj);
    // ͨ��IDɾ������
    int deleteById(uint64_t id);
};
#endif // !_REPAIRORDER_DAO_