#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/6/4 22:24:58

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
#ifndef _REPAIRORDER_SERVICE_
#define _REPAIRORDER_SERVICE_
#include <list>
#include "domain/vo/repairorder/RepairorderVO.h" // !
#include "domain/query/repairorder/RepairorderQuery.h"
#include "domain/query/repairorder/RepairorderDetailsQuery.h"
#include "domain/dto/repairorder/RepairorderDTO.h"
#include "domain/dto/repairorder/RepairorderDetailsDTO.h"


/**
 * �豸ά�޵���ѯ����ʵ��
 */
class RepairorderService
{
public:
    // ��ҳ��ѯ��������
    RepairorderPageDTO::Wrapper listAll(const RepairorderQuery::Wrapper& query);
    // ͨ��ID��ѯ��ϸ��Ϣ
    RepairorderDetailsDTO::Wrapper getData(const RepairorderDetailsQuery::Wrapper& id);
    // ��������
    uint64_t saveData(const RepairorderDetailsByAddDTO::Wrapper& dto, const PayloadDTO& payload);
    // �޸�����
    bool updateData(const RepairorderDetailsDTO::Wrapper& dto, const PayloadDTO& payload);
    // ͨ��IDɾ������
    bool removeData(uint64_t id);
};

#endif // !_REPAIRORDER_SERVICE_