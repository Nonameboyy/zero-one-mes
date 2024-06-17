#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/26 22:29:44

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
#ifndef _IMPORTDEVICEDAO_H_
#define _IMPORTDEVICEDAO_H_

#include "BaseDAO.h"
#include "domain/do/dv_machinery/dvMachineryDO.h"

class ImportDeviceDAO : public BaseDAO
{
public:
	bool insertOne(dvMachineryDO& Do);
};

#endif // !_IMPORTDEVICEDAO_H_