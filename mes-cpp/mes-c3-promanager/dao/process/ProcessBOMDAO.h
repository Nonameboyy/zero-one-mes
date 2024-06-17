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
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteProductBomDO.h"
#include"../../lib-oatpp/include/domain/dto/PayloadDTO.h"
class ProcessBOMDAO : public BaseDAO
{
public:
	// 通过ID删除数据
	int deleteById(uint64_t id);
	uint64_t insert(const ProRouteProductBomDO& iObj, const PayloadDTO& payload);
	int update(const ProRouteProductBomDO& iObj, const PayloadDTO& payload);
};
#endif // !_SAMPLE_DAO_