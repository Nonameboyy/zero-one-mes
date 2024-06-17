#pragma once
#ifndef _PROCESSINSPECTION_QUERY_
#define _PROCESSINSPECTION_QUERY_

#include "../../GlobalInclude.h"
#include "../../dto/ProcessInspection/ProcessInspectionDTO.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class ProcessInspectionQuery : public PageQuery
{
	DTO_INIT(ProcessInspectionQuery, PageQuery);
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
	// 检测结果
	DTO_FIELD(String, check_result);
	DTO_FIELD_INFO(check_result) {
		info->description = ZH_WORDS_GETTER("processinspection.field.check_result");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSINSPECTION_QUERY_