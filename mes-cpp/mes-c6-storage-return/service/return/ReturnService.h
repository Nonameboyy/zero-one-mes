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
#include "domain/vo/return/ReturnVO.h"
#include "domain/query/return/ReturnQuery.h"
#include "domain/dto/return-ryan/ReturnDTO_r.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ReturnService
{
public:
	// ��ҳ��ѯ��������
	ReturnPageDTO::Wrapper listAll(const ReturnQuery::Wrapper& query);
	// ��ѯ��һ����
	ReturnDetailDTO::Wrapper getDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery);
	// ��������
	uint64_t saveData(const ReturnAdd::Wrapper& dto);
	// �޸�����
	bool updateData(const ReturnDTO_r::Wrapper& dto);
	// ͨ��IDɾ������
	// bool removeData(uint64_t id);
};

#endif // !_RETURN_SERVICE_

