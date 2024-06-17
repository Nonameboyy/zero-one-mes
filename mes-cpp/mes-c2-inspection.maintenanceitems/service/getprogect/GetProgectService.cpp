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
#include "GetProgectService.h"
#include "../../dao/getprogect/GetProgectDAO.h"
#include "../lib-common/include/ExcelComponent.h"
#include "../lib-common/include/NacosClient.h"
#include "../lib-common/include/FastDfsClient.h"

/*  // ��ҳ��ѯ��������
	GetProgectDTO::Wrapper listAll(const GetProgectQuery::Wrapper& query);

	// ͨ��ID��ѯ��Ŀ����
	bool listSome(const GetProgectDTO::Wrapper& dto);
*/

GetProgectPageDTO::Wrapper GetProgectService::listAll(const GetProgectQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetProgectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	GetProgectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<dvSubjectDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (dvSubjectDO sub : result)
	{
		auto dto = GetProgectDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,pId, SubjectId, pCode, SubjectCode, pType, SubjectType, pContent, SubjectContent, standard, SubjectStandard, enable, EnableFlag, note, Remark)
		pages->addData(dto);

	}
	return pages;
}

//GetProgectDTO::Wrapper listSome(const uint64_t id);
GetProgectDetailDTO::Wrapper GetProgectService::listSome(const GetProgectDetailQuery::Wrapper& query){
	auto pages = GetProgectDetailDTO::createShared();
	GetProgectDAO dao;
	list<dvSubjectDO> result = dao.selectById(query);
	for (dvSubjectDO sub : result)
	{
		auto dto = GetProgectDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pId, SubjectId,pCode, SubjectCode, pName, SubjectName, pType, SubjectType, pContent, SubjectContent, standard, SubjectStandard, enable, EnableFlag)
		//pages->addData(dto);
		return dto;
	}
	return {};
	//return pages;
}/*subjectId,subjectCode,subjectName,subjectType,subjectContent,subjectStandard,enableFlag*/
