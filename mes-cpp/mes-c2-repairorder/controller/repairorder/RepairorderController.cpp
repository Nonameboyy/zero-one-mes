/*
 * Copyright Zero One Star. All rights reserved.
 *
 * @Author: Heng_Xin
 * @Date: 2024/5/18 16:01:19
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *	  https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * */
#include "stdafx.h"
#include "RepairorderController.h"
#include "../../service/repairorder/RepairorderService.h"
#include "../ApiDeclarativeServicesHelper.h"

// 维修单分页查询数据
RepairorderPageJsonVO::Wrapper RepairorderController::execQueryRepairorder(const RepairorderQuery::Wrapper& query)
{
    // 定义一个Service
    RepairorderService service;
    // 查询数据
    auto result = service.listAll(query);
    // 响应结果
    auto jvo = RepairorderPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

// 维修单详情查询
RepairorderDetailsJsonVO::Wrapper RepairorderController::execQueryDetailsRepairorder(const RepairorderDetailsQuery::Wrapper& id)
{
    // 定义返回数据对象
    auto jvo = RepairorderDetailsJsonVO::createShared();
    // 参数校验
    if (id->repairId <= 0) {
        auto tmp = RepairorderDetailsDTO::createShared();
        tmp->repairId = -1;
        tmp->repairCode = "";
        tmp->repairName = "";
        tmp->machineryCode = "";
        tmp->machineryName = "";
        tmp->machineryBrand = "";
        tmp->requireDate = "";
        tmp->remark = "";
        jvo->init(tmp, RS_PARAMS_INVALID);
        return jvo;
    }
    // 定义一个Service
    RepairorderService service;
    // 执行数据查询
    auto dto = service.getData(id);
    if (dto->repairId == -1)
        jvo->fail(dto);
    else
        jvo->success(dto);
    // 响应结果
    return jvo;
}

// 添加维修单
Uint64JsonVO::Wrapper RepairorderController::execAddRepairorder(const RepairorderDetailsByAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // 定义返回数据对象
    auto jvo = Uint64JsonVO::createShared();

    // 非空校验
    if (!dto->repairCode ||
        !dto->machineryBrand ||
        !dto->machineryCode ||
        !dto->machineryName ||
        !dto->requireDate) {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // 有效值校验
    if (dto->repairCode == "" ||
        dto->machineryId <= 0 ||
        dto->machineryCode == "" ||
        dto->machineryName == "" ||
        dto->requireDate == "") {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }

    // 定义一个Service
    RepairorderService service;
    // 执行数据新增
    uint64_t res = service.saveData(dto, payload);
    if (res > 0) {
        jvo->success(res);
    } else {
        jvo->fail(res);
    }
    // 响应结果
    return jvo;
}

// 修改维修单
Uint64JsonVO::Wrapper RepairorderController::execModifyRepairorder(const RepairorderDetailsDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // 定义返回数据对象
    auto jvo = Uint64JsonVO::createShared();

    // 非空校验
    if (!dto->repairCode ||
        !dto->machineryId ||
        !dto->machineryCode ||
        !dto->machineryName ||
        !dto->requireDate) {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // 有效值校验
    if (dto->repairCode == "" ||
        dto->machineryId <= 0 ||
        dto->machineryCode == "" ||
        dto->machineryName == "" ||
        dto->requireDate == "") {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }

    // 定义一个Service
    RepairorderService service;
    // 执行数据新增
    if (service.updateData(dto, payload)) {
        jvo->success(dto->repairId);
    } else {
        jvo->fail(dto->repairId);
    }
    // 响应结果
    return jvo;
}

// 删除维修单
Uint64JsonVO::Wrapper RepairorderController::execRemoveRepairorder(const DeleteMultipleRepairersDTO::Wrapper& id)
{
    // 定义返回数据对象
    auto jvo = Uint64JsonVO::createShared();

    uint64_t cnt = 0; // 执行成功计数
    // 定义一个Service
    RepairorderService service;
    for (const UInt64& it : *id->repairIdList) { // 不用校验, 失败不管 (隐藏字段, 一般不会有问题)
        if (it > 0) {
            cnt += service.removeData(it);
        }
    }
    jvo->success(cnt);
    // 响应结果
    return jvo;
}
