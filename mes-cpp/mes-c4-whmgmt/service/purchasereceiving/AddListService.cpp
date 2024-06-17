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
#include "AddListService.h"
#include "../../dao/purchasereceiving/purchasereceivingDAO.h"


uint64_t AddListService::saveData(const AddListDTO::Wrapper& dto)
{
	// ��װDO����
	AddListDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Recptcode, recptcode, Recptname, recptname, Recptdate, recptdate, Pocode, pocode, Status, status, Vendorid, vendorid, Warehousename, warehousename, Remark, remark)
		// ִ���������

		purchasereceivingDAO dao;
	return dao.insert(data);
}