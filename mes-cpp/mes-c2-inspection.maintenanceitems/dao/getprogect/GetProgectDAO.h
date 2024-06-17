#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _GETPROGECT_DAO_
#define _GETPROGECT_DAO_
#include "BaseDAO.h"
#include "../../../mes-c2-equipmentledger/domain/do/dv_subject/dvSubjectDO.h"
#include "../../domain/query/getprogect/GetProgectQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class GetProgectDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const GetProgectQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<dvSubjectDO> selectWithPage(const GetProgectQuery::Wrapper& query);
	
	// ͨ��id��ѯ����
	list<dvSubjectDO> selectById(const GetProgectDetailQuery::Wrapper& query);
	// ͨ��id��ѯ����
	//list<GetProgectIdDO> selectById(const string& pId);


};
#endif // !_SAMPLE_DAO_
