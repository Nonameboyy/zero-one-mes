#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/24 10:27:49

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
#ifndef _REPAIRCONTENT_DAO_
#define _REPAIRCONTENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_repair_line/RepaircontentDO.h"
#include "../../domain/query/repaircontent/RepaircontentQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RepaircontentDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const RepaircontentQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<dv_repair_lineDO> selectWithPage(const RepaircontentQuery::Wrapper& query);
	// ͨ����Ŀ���Ʋ�ѯ����---������ҳ
	list<dv_repair_lineDO> selectByName(const string& name);

	// ͨ����Ŀ���Ʋ�ѯ����--
	list<dvSubjectDO> selectSubject_Name(const uint64_t& id);

	// ��������
	uint64_t insert(const dv_repair_lineDO& iObj);
	// �޸�����
	int update(const dv_repair_lineDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_REPAIRCONTENT_DAO_
