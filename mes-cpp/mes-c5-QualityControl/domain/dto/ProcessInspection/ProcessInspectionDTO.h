#pragma once
#ifndef _PROCESSINSPECTION_DTO_
#define _PROCESSINSPECTION_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//分页查询的DTO
class ProcessInspectionQueryDTO : public oatpp::DTO
{
	DTO_INIT(ProcessInspectionQueryDTO, DTO);
	// 编号(唯一值)
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("processinspection.field.id");
	}
	// 检验单编号
	DTO_FIELD(String, ipqc_code);
	DTO_FIELD_INFO(ipqc_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.ipqc_code");
	}
	// 检验类型
	DTO_FIELD(String, ipqc_type);
	DTO_FIELD_INFO(ipqc_type) {
		info->description = ZH_WORDS_GETTER("processinspection.field.ipqc_type");
	}
	// 工单编号
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.workorder_code");
	}
	// 产品物料编码
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.item_code");
	}
	// 产品物料名称
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("processinspection.field.item_name");
	}
	// 规格型号
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("processinspection.field.specification");
	}
	// 单位
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("processinspection.field.unit_of_measure");
	}
	// 检测数量
	DTO_FIELD(Float64, quantity_check);
	DTO_FIELD_INFO(quantity_check) {
		info->description = ZH_WORDS_GETTER("processinspection.field.quantity_check");
	}
	// 检测结果
	DTO_FIELD(String, check_result);
	DTO_FIELD_INFO(check_result) {
		info->description = ZH_WORDS_GETTER("processinspection.field.check_result");
	}
	// 检测日期
	DTO_FIELD(String, inspect_date);
	DTO_FIELD_INFO(inspect_date) {
		info->description = ZH_WORDS_GETTER("processinspection.field.inspect_date");
	}
	// 检测人员
	DTO_FIELD(String, inspector);
	DTO_FIELD_INFO(inspector) {
		info->description = ZH_WORDS_GETTER("processinspection.field.inspector");
	}
	// 单据状态
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("processinspection.field.status");
	}
};

/**
 * 过程检验DTO
 */
class ProcessInspectionDTO : public oatpp::DTO
{
	DTO_INIT(ProcessInspectionDTO, DTO);
	// 编号(唯一值)
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("processinspection.field.id");
	}
	// 检验单编号
	DTO_FIELD(String, ipqc_code);
	DTO_FIELD_INFO(ipqc_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.ipqc_code");
	}
	// 检验类型
	DTO_FIELD(String, ipqc_type);
	DTO_FIELD_INFO(ipqc_type) {
		info->description = ZH_WORDS_GETTER("processinspection.field.ipqc_type");
	}
	// 工单编号
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.workorder_code");
	}
	// 产品物料编码
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.item_code");
	}
	// 产品物料名称
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("processinspection.field.item_name");
	}
	// 规格型号
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("processinspection.field.specification");
	}
	// 单位
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("processinspection.field.unit_of_measure");
	}
	// 检测数量
	DTO_FIELD(Float64, quantity_check);
	DTO_FIELD_INFO(quantity_check) {
		info->description = ZH_WORDS_GETTER("processinspection.field.quantity_check");
	}
	// 检测结果
	DTO_FIELD(String, check_result);
	DTO_FIELD_INFO(check_result) {
		info->description = ZH_WORDS_GETTER("processinspection.field.check_result");
	}
	// 检测日期
	DTO_FIELD(String, inspect_date);
	DTO_FIELD_INFO(inspect_date) {
		info->description = ZH_WORDS_GETTER("processinspection.field.inspect_date");
	}
	// 检测人员
	DTO_FIELD(String, inspector);
	DTO_FIELD_INFO(inspector) {
		info->description = ZH_WORDS_GETTER("processinspection.field.inspector");
	}
	// 单据状态
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("processinspection.field.status");
	}
	// 检验单名称
	DTO_FIELD(String, ipqc_name);
	DTO_FIELD_INFO(ipqc_name) {
		info->description = ZH_WORDS_GETTER("processinspection.field.ipqc_name");
	}
	// 工单名称
	DTO_FIELD(String, workorder_name);
	DTO_FIELD_INFO(workorder_name) {
		info->description = ZH_WORDS_GETTER("processinspection.field.workorder_name");
	}
	// 工作站编号
	DTO_FIELD(String, workstation_code);
	DTO_FIELD_INFO(workstation_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.workstation_code");
	}
	// 工作站名称
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("processinspection.field.workstation_name");
	}
	// 工序编码
	DTO_FIELD(String, process_code);
	DTO_FIELD_INFO(process_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.process_code");
	}
	// 工序名称
	DTO_FIELD(String, process_name);
	DTO_FIELD_INFO(process_name) {
		info->description = ZH_WORDS_GETTER("processinspection.field.process_name");
	}
	// 任务编号
	DTO_FIELD(String, task_code);
	DTO_FIELD_INFO(task_code) {
		info->description = ZH_WORDS_GETTER("processinspection.field.task_code");
	}
	// 任务名称
	DTO_FIELD(String, task_name);
	DTO_FIELD_INFO(task_name) {
		info->description = ZH_WORDS_GETTER("processinspection.field.task_name");
	}
	// 不合格数
	DTO_FIELD(Float64, quantity_unqualified);
	DTO_FIELD_INFO(quantity_unqualified) {
		info->description = ZH_WORDS_GETTER("processinspection.field.quantity_unqualified");
	}
	// 合格数
	DTO_FIELD(Float64, quantity_qualified);
	DTO_FIELD_INFO(quantity_qualified) {
		info->description = ZH_WORDS_GETTER("processinspection.field.quantity_qualified");
	}
	// 致命缺陷数量
	DTO_FIELD(Float64, cr_quantity);
	DTO_FIELD_INFO(cr_quantity) {
		info->description = ZH_WORDS_GETTER("processinspection.field.cr_quantity");
	}
	// 严重缺陷数量
	DTO_FIELD(Float64, maj_quantity);
	DTO_FIELD_INFO(maj_quantity) {
		info->description = ZH_WORDS_GETTER("processinspection.field.maj_quantity");
	}
	// 轻微缺陷数量
	DTO_FIELD(Float64, min_quantity);
	DTO_FIELD_INFO(min_quantity) {
		info->description = ZH_WORDS_GETTER("processinspection.field.min_quantity");
	}
	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.remark");
	}
};

/**
 * 过程检测分页传输对象
 */
class ProcessInspectionPageDTO : public PageDTO<ProcessInspectionDTO::Wrapper>
{
	DTO_INIT(ProcessInspectionPageDTO, PageDTO<ProcessInspectionDTO::Wrapper>);
};

class ProcessInspectionQueryPageDTO : public PageDTO<ProcessInspectionQueryDTO::Wrapper>
{
	DTO_INIT(ProcessInspectionQueryPageDTO, PageDTO<ProcessInspectionQueryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSINSPECTION_DTO_