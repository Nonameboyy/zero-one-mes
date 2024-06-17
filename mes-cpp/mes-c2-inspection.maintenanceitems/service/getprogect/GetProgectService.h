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
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "../../domain/query/getprogect/GetProgectQuery.h"
#include "../../domain/dto/getprogect/GetProgectDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GetProgectService
{
public:
	// ��ҳ��ѯ��������
	GetProgectPageDTO::Wrapper listAll(const GetProgectQuery::Wrapper& query);

	// ͨ��ID��ѯ��Ŀ����
	//bool listSome(const GetProgectDTO::Wrapper& dto);
	GetProgectDetailDTO::Wrapper listSome(const GetProgectDetailQuery::Wrapper& query);
};

#endif // !_GETPROGECT_SERVICE_

