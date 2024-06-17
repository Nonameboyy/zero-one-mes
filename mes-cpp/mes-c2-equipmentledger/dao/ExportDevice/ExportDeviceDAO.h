#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/26 10:33:36

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
#ifndef _EXPORTDEVICEDAO_H_
#define _EXPORTDEVICEDAO_H_

#include "BaseDAO.h"
#include "domain/query/ExportDeviceQuery.h"
#include "domain/do/dv_machinery/dvMachineryDO.h"
#include <list>
#include <vector>

class ExportDeviceDAO : public BaseDAO
{
public:
	// ����query��ѯ���ݣ�������Ҫ����
	std::list<dvMachineryDO> selectAll(const ExportDeviceQuery::Wrapper& query);
};

#endif // !_EXPORTDEVICEDAO_H_