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
 * 设备维修单查询服务实现
 */
class RepairorderService
{
public:
    // 分页查询所有数据
    RepairorderPageDTO::Wrapper listAll(const RepairorderQuery::Wrapper& query);
    // 通过ID查询详细信息
    RepairorderDetailsDTO::Wrapper getData(const RepairorderDetailsQuery::Wrapper& id);
    // 保存数据
    uint64_t saveData(const RepairorderDetailsByAddDTO::Wrapper& dto, const PayloadDTO& payload);
    // 修改数据
    bool updateData(const RepairorderDetailsDTO::Wrapper& dto, const PayloadDTO& payload);
    // 通过ID删除数据
    bool removeData(uint64_t id);
};

#endif // !_REPAIRORDER_SERVICE_