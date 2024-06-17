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
#ifndef _QC_DEFECT_SERVICE_
#define _QC_DEFECT_SERVICE_
#include <list>
#include "domain/vo/defect/DefectVO.h"
#include "domain/dto/defect/DefectModifyDTO.h"
#include "domain/query/defect/QcDefectQuery.h"
#include "domain/dto/defect/DefectDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class DefectService
{
public:
	// ��ҳ��ѯ��������
	DefectPageDTO::Wrapper listAll(const QcDefectQuery::Wrapper& query);
	// ��������
	uint64_t insert(const DefectDTO::Wrapper& dto, const PayloadDTO& payload);
	// ɾ������
	uint64_t remove(const std::string ids);
	// �޸�����
	uint64_t modify(const DefectModifyDTO::Wrapper& dto, const std::string& update_by, const std::string& update_time);
};

#endif // !_DEFECT_SERVICE_

