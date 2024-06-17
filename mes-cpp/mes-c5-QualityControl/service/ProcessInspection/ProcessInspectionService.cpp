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
#include "ProcessInspectionService.h"
#include "../../domain/dto/ProcessInspection/ProcessInspectionDTO.h"
#include "../../dao/ProcessInspection/ProcessInspectionDAO.h"

bool ProcessInspectionService::updateData(const ProcessInspectionDTO::Wrapper& dto)
{
	// 组装DO数据
	ProcessInspectionDO data;
	/* 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(
		data, dto,
		Id, id,
		Ipqc_Code, ipqc_code,
		Ipqc_Name, ipqc_name,
		Ipqc_Type, ipqc_type,
		Workorder_Code, workorder_code,
		Workorder_Name, workorder_name,
		Workstation_Code, workstation_code,
		Workstation_Name, workstation_name,
		Quantity_Check, quantity_check,
		Item_Code, item_code,
		Item_Name, item_name,
		Unit_Of_Measure, unit_of_measure,
		Specification, specification
	);
		ZO_STAR_DOMAIN_DTO_TO_DO(
			data, dto,
			Process_Code, process_code,
			Process_Name, process_name,
			Task_Code, task_code,
			Task_Name, task_name,
			Quantity_Unqualified, quantity_unqualified,
			Quantity_Qualified, quantity_qualified,
			Cr_Quantity, cr_quantity,
			Maj_Quantity, maj_quantity,
			Min_Quantity, min_quantity,
			Inspect_Date, inspect_date,
			Check_Result, check_result,
			Inspector, inspector,
			Remark, remark
			//Status_Order, status
		);
		data.setStatus_Order(dto->status.getValue(""));
		// 执行数据修改
		ProcessInspectionDAO dao;
	return dao.update(data) == 1;
	//return true;
}

ProcessInspectionQueryPageDTO::Wrapper ProcessInspectionService::listAll(const ProcessInspectionQuery::Wrapper& query)
{
	ProcessInspectionDAO dao;

	auto result = ProcessInspectionQueryPageDTO::createShared();
	//设置分页参数
	result->pageIndex = query->pageIndex;
	result->pageSize = query->pageSize;
	//查看数据是否存在
	auto count = dao.count(query);
	//不存在返回空
	if (count < 1)
		return result;
	//计算所有数据要分多少页
	result->total = count;
	result->calcPages();
	//查询
	auto dos = dao.select(query,0);
	//把list<do>装到QueryPageDTO中
	for (auto x : dos) {
		auto dto = ProcessInspectionQueryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, x, id, Id, ipqc_code, Ipqc_Code, ipqc_type, Ipqc_Type, workorder_code, Workorder_Code, item_code, Item_Code, item_name, Item_Name, specification, Specification, unit_of_measure, Unit_Of_Measure, quantity_check, Quantity_Check, check_result, Check_Result, inspect_date, Inspect_Date, inspector, Inspector, status, Status_Order);
		result->addData(dto);
	}
	return result;
}

bool ProcessInspectionService::remove(uint64_t id)
{
	ProcessInspectionDAO dao;

	return dao.deleteById(id);
}

list<ProcessInspectionDO> ProcessInspectionService::listAllExort(const ProcessInspectionQuery::Wrapper& query)
{
	ProcessInspectionDAO dao;
	//查看数据是否存在
	auto count = dao.count(query);
	//不存在返回空
	if (count < 1)
		return {};
	//查询所有数据
	auto dos = dao.select(query,1);
	return dos;
}

// 获取过程检验单详情
ProcessInspectionDTO::Wrapper ProcessInspectionService::getInspectionDetails(const ProcessInspectionQuery::Wrapper& query) {
	auto resDetails = ProcessInspectionDTO::createShared();
	ProcessInspectionDAO dao;
	std::list<ProcessInspectionDO> result = dao.selectInspectionDetails(query);
	for (ProcessInspectionDO sub : result) {
		auto dto = ProcessInspectionDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, ipqc_code, Ipqc_Code, ipqc_name, Ipqc_Name, ipqc_type, Ipqc_Type, workorder_code, Workorder_Code, workorder_name, Workorder_Name, workstation_code, Workstation_Code, workstation_name, Workstation_Name, quantity_check, Quantity_Check, item_code, Item_Code, item_name, Item_Name, unit_of_measure, Unit_Of_Measure, specification, Specification, process_code, Process_Code);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, process_name, Process_Name, task_code, Task_Code, quantity_unqualified, Quantity_Unqualified, quantity_qualified, Quantity_Qualified, cr_quantity, Cr_Quantity, maj_quantity, Maj_Quantity, min_quantity, Min_Quantity, inspect_date, Inspect_Date, check_result, Check_Result, inspector, Inspector, remark, Remark);
		return dto;
	}
	return ProcessInspectionDTO::createShared();
}

// 确认检验单
bool ProcessInspectionService::updateConfirmOrdersData(const ProcessInspectionDTO::Wrapper& dto) {
	ProcessInspectionDO data;
	dto->status = "CONFIRMED";	// 修改状态为已确认
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Check_Result, check_result, Status_Order, status, Ipqc_Code, ipqc_code);
	ProcessInspectionDAO dao;
	return dao.updateConfirmOrders(data) == 1;
}

// 完成检验单
bool ProcessInspectionService::updateFinishOrdersData(const ProcessInspectionDTO::Wrapper& dto) {
	ProcessInspectionDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Quantity_Check, quantity_check, Quantity_Unqualified, quantity_unqualified, Quantity_Qualified, quantity_qualified, Task_Code, task_code);
	ProcessInspectionDAO dao;
	return dao.updateFinishOrders(data) == 1;
	//return false;
}

uint64_t ProcessInspectionService::saveData(const ProcessInspectionDTO::Wrapper& dto) {
	// 组装DO数据
	ProcessInspectionDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(
		data, dto,
		Ipqc_Code, ipqc_code,
		Ipqc_Name, ipqc_name,
		Ipqc_Type, ipqc_type,
		Task_Code, task_code,
		Task_Name, task_name,
		Workorder_Code, workorder_code,
		Workorder_Name, workorder_name,
		Workstation_Code, workstation_code,
		Workstation_Name, workstation_name,
		Process_Code, process_code,
		Process_Name, process_name,
		Item_Code, item_code,
		Item_Name, item_name,
		Specification, specification,
		Unit_Of_Measure, unit_of_measure
	)
		ZO_STAR_DOMAIN_DTO_TO_DO(
			data, dto,
			Quantity_Check, quantity_check,
			Quantity_Unqualified, quantity_unqualified,
			Quantity_Qualified, quantity_qualified,
			Cr_Quantity, cr_quantity,
			Maj_Quantity, maj_quantity,
			Min_Quantity, min_quantity,
			Check_Result, check_result,
			Inspect_Date, inspect_date,
			Inspector, inspector,
			Remark, remark
		)
		// 执行数据添加
		ProcessInspectionDAO dao;
	return dao.insert(data);
}