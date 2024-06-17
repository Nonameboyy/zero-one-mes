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
#ifndef _RETURN_SERVICE_
#define _RETURN_SERVICE_
#include <list>
#include "domain/vo/return-ryan/ReturnVO_r.h"
#include "domain/query/return-ryan/ReturnQuery_r.h"
#include "domain/dto/return-ryan/ReturnDTO_r.h"
#include "domain/do/return-ryan/ReturnDO_r.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ReturnService
{
public:
	// ��ҳ��ѯ��������
	ReturnPageDTO_r::Wrapper listAll_r(const ReturnQuery_r::Wrapper& query);
	// ��������
	uint64_t saveData_r(const ReturnDTO_r::Wrapper& dto);
	// �޸�����
	bool updateData(const ReturnDTO_r::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
	// ִ���˻����޸�����״̬��
	bool excuteData(uint64_t id);
	//
	list<ReturnDO_r>listAllExort(const ReturnQuery_r::Wrapper& query);
	//����
	string exportTable(const ReturnQuery_r::Wrapper& query);
};

#endif // !_RETURN_SERVICE_

