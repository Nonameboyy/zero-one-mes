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
#include "ProinSpectService.h"
#include "dao/ProinSpect/ProinSpectDAO.h"



uint64_t  ProinspectService::saveData(const ProinspectDTO::Wrapper& dto)
{
	// ��װDO����
	ProinspectDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Record_id, record_id, Qc_type, qc_type, Qc_id, qc_id, Line_id, line_id, Defect_name, defect_name, Defect_level, defect_level, Remark, remark, Defect_quantity, defect_quantity)
		// ִ���������
	ProinspectDAO dao;
	return dao.insert(data);
}

bool ProinspectService::updateData(const ProinspectDTO::Wrapper& dto)
{
	// ��װDO����
	ProinspectDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Record_id, record_id, Qc_type, qc_type, Qc_id, qc_id, Line_id, line_id, Defect_name, defect_name, Defect_level, defect_level, Remark, remark, Defect_quantity, defect_quantity)
		// ִ�������޸�
		ProinspectDAO dao;
	return dao.update(data) == 1;
}

bool ProinspectService::removeData(const ProinspectDTO::Wrapper& dto)
{
	ProinspectDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Record_id, record_id, Qc_type, qc_type, Qc_id, qc_id, Line_id, line_id, Defect_name, defect_name, Defect_level, defect_level, Remark, remark, Defect_quantity, defect_quantity)
		ProinspectDAO dao;
	return dao.deleteById(data) == 1;
}

ProinspectPageDTO::Wrapper ProinspectService::queryProcessInspectionList(const ProinspectQuery::Wrapper& query) {
	// �������ض���
	auto pages = ProinspectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProinspectDAO dao;
	uint64_t count = dao.count1(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProinspectDO> result = dao.selectByIpqc_id(query);
	// ��DOת����DTO
	for (ProinspectDO sub : result)
	{
		auto dto = ProinspectDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, index_name, Index_name, index_type, Index_type,
			qc_tool, Qc_tool, check_method, Check_method, stander_val, Stander_val,
			unit_of_measure, Unit_of_measure, threshold_max, Threshold_max, threshold_min, Threshold_min,
			cr_quantity, Cr_quantity, maj_quantity, Maj_quantity, min_quantity, Min_quantity)
		pages->addData(dto);

	}
	return pages;
}

ProinspectPageDTO::Wrapper ProinspectService::queryProcessInspectionDefectList(const ProinspectQuery::Wrapper& query) {
	// �������ض���
	auto pages = ProinspectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProinspectDAO dao;
	uint64_t count = dao.count2(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProinspectDO> result = dao.selectByLine_id(query);
	// ��DOת����DTO
	for (ProinspectDO sub : result)
	{
		auto dto = ProinspectDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qc_type, Qc_type, qc_id, Qc_id, line_id, Line_id, defect_name, Defect_name,
			defect_level, Defect_level, remark, Remark, defect_quantity, Defect_quantity)
			pages->addData(dto);

	}
	return pages;
}