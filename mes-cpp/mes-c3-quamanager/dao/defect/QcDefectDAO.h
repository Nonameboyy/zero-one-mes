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
#ifndef _QC_DEFECT_DAO_
#define _QC_DEFECT_DAO_
#include "BaseDAO.h"
#include "domain/do/qc/QcDefectDO.h"
#include "domain/dto/defect/DefectModifyDTO.h"
#include "domain/query/defect/QcDefectExportQuery.h"
#include "domain/query/defect/QcDefectQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class QcDefectDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const QcDefectQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<QcDefectDO> selectWithPage(const QcDefectQuery::Wrapper& query);
	// ͨ��ȱ��������ѯ����
	list<QcDefectDO> selectByName(const string& name);
	// ͨ����������Ͳ�ѯ����
	list<QcDefectDO> selectByType(const string& Type);
	// ͨ��ȱ�ݵȼ���ѯ����
	list<QcDefectDO> selectByLevel(const string& Level);
	// ��������
	uint64_t insert(const QcDefectDO& iObj);
	// ɾ������
	uint64_t remove(const string& ids);
	// ��������
	uint64_t modify(const DefectModifyDTO::Wrapper& dto, const string& update_by, const string& update_time);
};
#endif // !_QC_DEFECT_DAO_
