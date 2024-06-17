/*
 * Copyright Zero One Star. All rights reserved.
 *
 * @Author: Heng_Xin
 * @Date: 2024/6/4 22:24:35
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
#include "RepairorderService.h"
#include "../../dao/repairorder/RepairorderDAO.h"
#include "SimpleDateTimeFormat.h"

RepairorderPageDTO::Wrapper RepairorderService::listAll(const RepairorderQuery::Wrapper& query)
{
    // 构建返回对象
    auto pages = RepairorderPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    RepairorderDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0) {
        return pages;
    }

    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    list<DvRepairDO> result = dao.selectWithPage(query);
    // 将DO转换成DTO
    for (const DvRepairDO& sub : result) {
        auto dto = RepairorderDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
            repairId, Repair_id,
            repairCode, Repair_code,
            repairName, Repair_name,
            machineryId, Machinery_id,
            machineryCode, Machinery_code,
            machineryName, Machinery_name,
            requireDate, Require_date,
            finishDate, Finish_date,
            confirmDate, Confirm_date,
            repairResult, Repair_result,
            acceptedBy, Accepted_by,
            confirmBy, Confirm_by,
            status, Status)
        pages->addData(dto);
    }
    return pages;
}

RepairorderDetailsDTO::Wrapper RepairorderService::getData(const RepairorderDetailsQuery::Wrapper& id)
{
    // 构建返回对象
    auto pages = RepairorderDetailsDTO::createShared();

    // 查询数据总条数
    RepairorderDAO dao;
    uint64_t count = dao.count(id);
    if (count <= 0) {
        pages->repairId = -1;
        pages->repairCode = "";
        pages->repairName = "";
        pages->machineryCode = "";
        pages->machineryName = "";
        pages->machineryBrand = "";
        pages->requireDate = "";
        pages->remark = "";
        return pages;
    }

    list<DvRepairDO> result = dao.selectById(id->repairId);

    for (const DvRepairDO& sub : result) {
        ZO_STAR_DOMAIN_DO_TO_DTO(pages, sub,
            repairId, Repair_id,
            repairCode, Repair_code,
            repairName, Repair_name,
            machineryCode, Machinery_code,
            machineryName, Machinery_name,
            machineryBrand, Machinery_brand,
            requireDate, Require_date,
            remark, Remark)
    }

    return pages;
}

uint64_t RepairorderService::saveData(const RepairorderDetailsByAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
    DvRepairDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Repair_code, repairCode,
        Repair_name, repairName,
        Machinery_id, machineryId,
        Machinery_code, machineryCode,
        Machinery_name, machineryName,
        Machinery_brand, machineryBrand,
        Machinery_type_id, machineryTypeId,
        Require_date, requireDate,
        Remark, remark)
    data.setCreate_by(payload.getUsername());
    data.setCreate_time(SimpleDateTimeFormat::format());
    RepairorderDAO dao;
    return dao.insert(data);
}

bool RepairorderService::updateData(const RepairorderDetailsDTO::Wrapper& dto, const PayloadDTO& payload)
{
    DvRepairDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Repair_id, repairId,
        Repair_code, repairCode,
        Repair_name, repairName,
        Machinery_id, machineryId,
        Machinery_code, machineryCode,
        Machinery_name, machineryName,
        Machinery_brand, machineryBrand,
        Machinery_type_id, machineryTypeId,
        Require_date, requireDate,
        Remark, remark)
    data.setUpdate_by(payload.getUsername());
    data.setUpdate_time(SimpleDateTimeFormat::format());
    RepairorderDAO dao;
    return dao.update(data) == 1;
}

bool RepairorderService::removeData(uint64_t id)
{
    RepairorderDAO dao;
    return dao.deleteById(id) == 1;
}
