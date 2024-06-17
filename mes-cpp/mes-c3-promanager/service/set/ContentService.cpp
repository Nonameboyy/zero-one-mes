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
#include "ContentService.h"
#include "../../dao/set/ProProcessContentDAO.h"

SetProListPageDTO::Wrapper ContentService::listAll(const SetStepExportQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SetProListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProProcessContentDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProProcessContentDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ProProcessContentDO sub : result)
	{
		auto dto = SetProListDTO::createShared();
 		/*dto->contentId = sub.getContentId();
 		dto->orderNum = sub.getOrderNum();
 		dto->contentText = sub.getContentText();
 		dto->device = sub.getDevice();
		dto->material = sub.getMaterial();
		dto->docUrl = sub.getDocurl();
		dto->remark = sub.getRemark();*/
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, contentId, ContentId, orderNum, OrderNum, contentText, ContentText, device, Device,material,Material,docUrl,DocUrl,remark,Remark)
		pages->addData(dto);
		
	}
	return pages;
}

bool ContentService::saveData(const SetProListDTO::Wrapper& dto)
{
	// ��װDO����
	ProProcessContentDO data;
 	data.setContentId(dto->contentId.getValue(1));
	data.setOrderNum(dto->orderNum.getValue(1));
	data.setContentText(dto->contentText.getValue(""));
	data.setDevice(dto->device.getValue(""));
	data.setMaterial(dto->material.getValue(""));
	data.setDocUrl(dto->docUrl.getValue(""));
	data.setRemark(dto->remark.getValue(""));
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
	// ִ���������
	ProProcessContentDAO dao;
	return dao.insert(data);
}


bool ContentService::updateData(const SetProListDTO::Wrapper& dto)
{
	// ��װDO����
	ProProcessContentDO data;
	data.setContentId(dto->contentId.getValue(1));
	data.setOrderNum(dto->orderNum.getValue(1));
	data.setContentText(dto->contentText.getValue(""));
	data.setDevice(dto->device.getValue(""));
	data.setMaterial(dto->material.getValue(""));
	data.setDocUrl(dto->docUrl.getValue(""));
	data.setRemark(dto->remark.getValue(""));
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
	// ִ�������޸�
	ProProcessContentDAO dao;
	return dao.update(data) == 1;
}

bool ContentService::removeData(uint64_t id)
{
	ProProcessContentDAO dao;
	return dao.deleteByprocessId(id) == 1;
}

bool ContentService::removeStep(uint64_t id)
{
	ProProcessContentDAO dao;
	return dao.deleteBycontentId(id) == 1;
}
