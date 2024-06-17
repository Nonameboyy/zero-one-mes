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
#include "AddDeviceService.h"
#include "../../dao/adddevice/AddDeviceDAO.h"
#include"../lib-common/include/SimpleDateTimeFormat.h"

uint64_t AddDeviceService::saveData(const AddDeviceDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ¡Á¨¦¡Á¡ãDO????
	Dv_check_machineryDO  data;
	data.setPlan_id(dto->planId.getValue(1));
	//data.setMachineryCode(dto->eCode.getValue(""));
	AddDeviceDAO dao;

	std::stringstream ss(dto->machineryId.getValue(""));
	data.setCreate_by(payload.getUsername());
	data.setCreate_time(SimpleDateTimeFormat::format());
	std::string id;
	while (std::getline(ss, id, ',')) {
		data.setMachinery_id(stoi(id));
		dao.insert(data);

	}


	return 1;
}


