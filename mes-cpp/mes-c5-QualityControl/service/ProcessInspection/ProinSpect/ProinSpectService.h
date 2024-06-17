#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _PROINSPECT_SERVICE_
#define _PROINSPECT_SERVICE_
#include <list>
#include "domain/vo/BaseJsonVO.h"
#include "domain/do/ProinSpect/ProinSpectDO.h"
#include "domain/dto/ProcessInspection/ProinSpect/ProinSpectDTO.h"
#include "domain/vo/ProcessInspection/ProinSpect/ProinSpectVO.h"
#include "domain/query/ProcessInspection/ProinSpect/ProinSpectQuery.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class  ProinspectService
{
public:
	// ��������
	uint64_t saveData(const ProinspectDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ProinspectDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const ProinspectDTO::Wrapper& dto);
	// ��ȡ���̼��鵥���б�����+��ҳ��
	ProinspectPageDTO::Wrapper queryProcessInspectionList(const ProinspectQuery::Wrapper& query);
	// ��ȡ���̼��鵥��ȱ���б�����+��ҳ��
	ProinspectPageDTO::Wrapper queryProcessInspectionDefectList(const ProinspectQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_

