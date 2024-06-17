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
#include "ProduceWorkService.h"
#include "../../dao/ProduceWork/ProduceWorkDAO.h"


//获取报工详情
ProduceWorkDTO::Wrapper ProduceWorkService::execeQueryDetail(const uint64_t& id)
{
	ProduceWorkDAO dao;
	list<ProduceWorkDO> result = dao.selectByRecord_id(id);

	auto dto = ProduceWorkDTO::createShared();

	ProduceWorkDO sub = result.front();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, Record_id, feedback_type, Feedback_type, workorder_code, Workorder_code, task_code, Task_code, item_code,Item_code,
		item_name, Item_name, unit_of_measure, Unit_of_measure, specification, Specification, quantity_feedback, Quantity_feedback, quantity_uncheck, Quantity_uncheck,
		nick_name, Nick_name, record_nick, Record_nick, feedback_time, Feedback_time, remark, Remark);

	return dto;
}
//
//
//
uint64_t ProduceWorkService::saveData(const ProduceWorkDTO::Wrapper& dto)
{
	// 组装DO数据
	ProduceWorkDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Feedback_type, feedback_type, Workorder_code, workorder_code, Task_code, task_code, Item_code, item_code,
		Item_name, item_name, Unit_of_measure, unit_of_measure, Specification, specification, Quantity_feedback, quantity_feedback, Quantity_uncheck, quantity_uncheck,
		Nick_name, nick_name, Record_nick, record_nick, Feedback_time, feedback_time, Remark, remark);
		// 执行数据添加
		ProduceWorkDAO dao;
	return dao.insert(data);
}
//
bool ProduceWorkService::updateData(const ProduceWorkDTO::Wrapper& dto)
{
	// 组装DO数据
	ProduceWorkDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Record_id,record_id, Feedback_type, feedback_type, Workorder_code, workorder_code, Task_code, task_code, Item_code, item_code,
		Item_name, item_name, Unit_of_measure, unit_of_measure, Specification, specification, Quantity_feedback, quantity_feedback, Quantity_uncheck, quantity_uncheck,
		Nick_name, nick_name, Record_nick, record_nick, Feedback_time, feedback_time, Remark, remark)
		// 执行数据修改
		ProduceWorkDAO dao;
	return dao.update(data) == 1;
}
