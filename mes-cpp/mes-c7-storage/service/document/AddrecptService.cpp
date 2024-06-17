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
#include "AddrecptService.h"
#include "../../dao/document/AddrecptDAO.h"


uint64_t AddrecptService::saveData(const AddrecptDTO::Wrapper& dto)//注意dto还包含id但是并没有用到！
{
	// 组装DO数据
	Wm_product_recptDO data;
	data.setRecpt_code(dto->recpt_code.getValue(""));
 	data.setRecpt_date(dto->recpt_date.getValue(""));
	data.setRecpt_name(dto->recpt_name.getValue(""));
	data.setRemark(dto->remark.getValue(""));
	data.setWorkorder_code(dto->workorder_code.getValue(""));
	data.setWorkorder_name(dto->workorder_name.getValue(""));
	data.setItem_id(dto->item_id.getValue(0));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Recpt_code,recpt_code,Recpt_date,recpt_date,Recpt_name,recpt_name,Remark,remark,Workorder_code,workorder_code,Workorder_name,workorder_name,Item_id,item_id)//data.setName(dto.name)...
		// 执行数据添加
		AddrecptDAO dao;
	return dao.insert(data);
}

//bool SampleService::updateData(const SampleDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	SampleDO data;
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
//		// 执行数据修改
//		SampleDAO dao;
//	return dao.update(data) == 1;
//}

