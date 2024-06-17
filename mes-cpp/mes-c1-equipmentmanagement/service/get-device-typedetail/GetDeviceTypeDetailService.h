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


#ifndef _GETDEVICETYPE_SERVICE_H_
#define _GETDEVICETYPE_SERVICE_H_

#include"../../domain/query/get-device-typedetail/GetDeviceTypeDetailQuery.h"
#include"../../domain/do/equipment-type/EquipmentTypeDO.h"
#include"../../domain/dto/device-typedetail/DeviceTypeDetailDTO.h"
class GetDeviceTypeDetailService
{
public:
	// 通过查询参数查询单条详情数据
	list<EquipmentTypeDO> queryTypeDetail(const GetDeviceTypeDetailQuery::Wrapper& query);
};

#endif 

