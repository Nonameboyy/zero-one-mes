#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/06/7 18:41:17

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
#ifndef _EXPORTPLANSERVICE_H_
#define _EXPORTPLANSERVICE_H_

#include "domain/query/ExportPlanQuery.h"
#include <list>
#include <string>

/**
 * �����豸service
 * �����ˣ�����
 */
class ExportPlanService
{
public:
	std::string exportPlan(const ExportPlanQuery::Wrapper& query);
};


#endif // !_EXPORTDEVICESERVICE_H_