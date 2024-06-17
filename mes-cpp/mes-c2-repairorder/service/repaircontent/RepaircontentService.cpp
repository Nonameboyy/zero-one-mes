/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/24 11:13:11

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
#include "stdafx.h"
#include "RepaircontentService.h"
#include "../../dao/dv_repair_line/RepaircontentDAO.h"
#include "../../domain/do/dv_repair_line/RepaircontentDO.h"
#include "SimpleDateTimeFormat.h"


RepaircontentPageDTO::Wrapper RepaircontentService::listAll(const RepaircontentQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepaircontentPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	
	// 查询数据总条数
	RepaircontentDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<dv_repair_lineDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (dv_repair_lineDO sub : result)
	{
		auto dto = RepaircontentDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, 
			subject_name, subject_Name, 
			malfunction, Malfunction, 
			malfunction_url,Malfunction_url, 
			repair_des, repair_Des,
			subject_code, subject_Code,
			subject_type, subject_Type,
			subject_content, subject_Content,
			create_by, Create_by,
			create_time, Create_time,
			update_by, Update_by,
			update_time, Update_time)
			pages->addData(dto);

	}
	return pages;
}
//查询
RepaircontentDTO::Wrapper RepaircontentService::getData(const RepaircontentQuery::Wrapper& id)
{
	// 构建返回对象
	auto pages = RepaircontentDTO::createShared();

	// 查询数据总条数
	RepaircontentDAO dao;
	uint64_t count = dao.count(id);
	if (count <= 0) {
		return pages;
	}

	list<dv_repair_lineDO> result = dao.selectByName(id->subject_name);

	for (const dv_repair_lineDO& sub : result) {
		ZO_STAR_DOMAIN_DO_TO_DTO(pages, sub,
			subject_name, subject_Name, 
			malfunction, Malfunction, 
			malfunction_url, Malfunction_url, 
			repair_des, repair_Des,
			subject_code, subject_Code,
			subject_type, subject_Type,
			subject_content, subject_Content,
			create_by, Create_by,
			create_time, Create_time,
			update_by,Update_by,
			update_time,Update_time)
	}

	return pages;
}

uint64_t RepaircontentService::saveData(const AddRepaircontentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	dv_repair_lineDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		repair_Id,repair_id,
		subject_Id, subject_id, 
		Malfunction, malfunction, 
		Malfunction_url, malfunction_url, 
		repair_Des, repair_des
	)
	data.setCreate_by(payload.getUsername());
	data.setCreate_time(SimpleDateTimeFormat::format());
		// 执行数据添加
		RepaircontentDAO dao;
	return dao.insert(data);
}

bool RepaircontentService::updateData(const ModifyRepaircontentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	dv_repair_lineDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, 
		subject_Id, subject_id, 
		Malfunction, malfunction, 
		Malfunction_url, malfunction_url, 
		repair_Des, repair_des,
		line_Id,line_id
		)
	data.setUpdate_by(payload.getUsername());
	data.setUpdate_time(SimpleDateTimeFormat::format());
		RepaircontentDAO dao;
	return dao.update(data) == 1;
}

bool RepaircontentService::removeData(uint64_t id)
{
	RepaircontentDAO dao;
	return dao.deleteById(id) == 1;
}
