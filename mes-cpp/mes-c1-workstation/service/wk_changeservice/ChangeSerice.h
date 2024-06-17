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
#ifndef _CHANGE_SERVICE_
#define _CHANGE_SERVICE_
#include <list>
#include "domain/vo/Workwear_Delete_VO.h"
#include "domain/query/workwear/Workwear_Change_Query.h"
#include "domain/dto/Change_Workwear_DTO.h"

/*
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ChangeService
{
public:
	// ��ҳ��ѯ��������
	ChangeWorkwearDTO::Wrapper listAll(const ChangeQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ChangeWorkwearDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ChangeWorkwearDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

