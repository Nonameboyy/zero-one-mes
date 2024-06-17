/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "QcDefectService.h"
#include "../../dao/defect/QcDefectDAO.h"
#include "SimpleDateTimeFormat.h"

DefectPageDTO::Wrapper DefectService::listAll(const QcDefectQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DefectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	QcDefectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<QcDefectDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (QcDefectDO sub : result)
	{
		auto dto = DefectDTO::createShared();
		// 		dto->id = sub.getId();
		//	    dto->defect_name = sub.getDefectName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, defect_code, DefectCode, defect_name, DefectName, index_type, IndexType, defect_level, DefectLevel)
			pages->addData(dto);

	}
	return pages;
}

uint64_t DefectService::insert(const DefectDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	string username = payload.getUsername();
	string time = SimpleDateTimeFormat().format();
	QcDefectDO data;
	data.setDefectCode(dto->defect_code.getValue(""));
	data.setDefectName(dto->defect_name.getValue(""));
	data.setIndexType(dto->index_type.getValue(""));
	data.setDefectLevel(dto->defect_level.getValue(""));
	data.setCreateBy(username);
	data.setCreateTime(time);
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, DefectCode, defect_code, DefectName, defect_name, IndexType, index_type, DefectLevel, defect_level);
	// 执行数据添加
	QcDefectDAO dao;
	return dao.insert(data);
}
uint64_t DefectService::remove(const std::string ids)
{
	return QcDefectDAO().remove(ids);
}

uint64_t DefectService::modify(const DefectModifyDTO::Wrapper& dto, const std::string& update_by, const std::string& update_time)
{
	return QcDefectDAO().modify(dto, update_by, update_time);
}