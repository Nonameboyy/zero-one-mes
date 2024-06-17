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

// ά�޵���ҳ��ѯ����
RepairorderPageJsonVO::Wrapper RepairorderController::execQueryRepairorder(const RepairorderQuery::Wrapper& query)
{
    // ����һ��Service
    RepairorderService service;
    // ��ѯ����
    auto result = service.listAll(query);
    // ��Ӧ���
    auto jvo = RepairorderPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

// ά�޵������ѯ
RepairorderDetailsJsonVO::Wrapper RepairorderController::execQueryDetailsRepairorder(const RepairorderDetailsQuery::Wrapper& id)
{
    // ���巵�����ݶ���
    auto jvo = RepairorderDetailsJsonVO::createShared();
    // ����У��
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
    // ����һ��Service
    RepairorderService service;
    // ִ�����ݲ�ѯ
    auto dto = service.getData(id);
    if (dto->repairId == -1)
        jvo->fail(dto);
    else
        jvo->success(dto);
    // ��Ӧ���
    return jvo;
}

// ���ά�޵�
Uint64JsonVO::Wrapper RepairorderController::execAddRepairorder(const RepairorderDetailsByAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // ���巵�����ݶ���
    auto jvo = Uint64JsonVO::createShared();

    // �ǿ�У��
    if (!dto->repairCode ||
        !dto->machineryBrand ||
        !dto->machineryCode ||
        !dto->machineryName ||
        !dto->requireDate) {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // ��ЧֵУ��
    if (dto->repairCode == "" ||
        dto->machineryId <= 0 ||
        dto->machineryCode == "" ||
        dto->machineryName == "" ||
        dto->requireDate == "") {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }

    // ����һ��Service
    RepairorderService service;
    // ִ����������
    uint64_t res = service.saveData(dto, payload);
    if (res > 0) {
        jvo->success(res);
    } else {
        jvo->fail(res);
    }
    // ��Ӧ���
    return jvo;
}

// �޸�ά�޵�
Uint64JsonVO::Wrapper RepairorderController::execModifyRepairorder(const RepairorderDetailsDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // ���巵�����ݶ���
    auto jvo = Uint64JsonVO::createShared();

    // �ǿ�У��
    if (!dto->repairCode ||
        !dto->machineryId ||
        !dto->machineryCode ||
        !dto->machineryName ||
        !dto->requireDate) {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // ��ЧֵУ��
    if (dto->repairCode == "" ||
        dto->machineryId <= 0 ||
        dto->machineryCode == "" ||
        dto->machineryName == "" ||
        dto->requireDate == "") {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }

    // ����һ��Service
    RepairorderService service;
    // ִ����������
    if (service.updateData(dto, payload)) {
        jvo->success(dto->repairId);
    } else {
        jvo->fail(dto->repairId);
    }
    // ��Ӧ���
    return jvo;
}

// ɾ��ά�޵�
Uint64JsonVO::Wrapper RepairorderController::execRemoveRepairorder(const DeleteMultipleRepairersDTO::Wrapper& id)
{
    // ���巵�����ݶ���
    auto jvo = Uint64JsonVO::createShared();

    uint64_t cnt = 0; // ִ�гɹ�����
    // ����һ��Service
    RepairorderService service;
    for (const UInt64& it : *id->repairIdList) { // ����У��, ʧ�ܲ��� (�����ֶ�, һ�㲻��������)
        if (it > 0) {
            cnt += service.removeData(it);
        }
    }
    jvo->success(cnt);
    // ��Ӧ���
    return jvo;
}
