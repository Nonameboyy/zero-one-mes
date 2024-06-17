/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "DeleteService.h"
#include "../../dao/deletedao/DeleteDAO.h"
#include "../mes-c1-workstation/domain/do/workstation/WorkStationDO.h"

bool DeleteService::removeData(uint64_t id)
{
	DeleteDAO dao;
	return dao.deleteById(id) == 1;
}
