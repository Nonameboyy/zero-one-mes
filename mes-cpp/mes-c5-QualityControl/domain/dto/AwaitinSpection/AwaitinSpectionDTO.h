#pragma once
#ifndef _AWAITINSPECTION_DTO_
#define _AWAITINSPECTION_DTO_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class AwaitinSpectionDTO : public oatpp::DTO
{
	DTO_INIT(AwaitinSpectionDTO, DTO);
	//记录ID
	DTO_FIELD(Int64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.record_id");
	}
	//单据编码
	DTO_FIELD(String, feedback_code);
	DTO_FIELD_INFO(feedback_code) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.feedback_code");
	}
	//检测项型
	DTO_FIELD(String, feedback_type);
	DTO_FIELD_INFO(feedback_type) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.feedback_type");
	}
	//物资编码
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.item_code");
	}
	//物资名称
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.item_name");
	}
	//待检数量
	DTO_FIELD(Float64, quantity_uncheck);
	DTO_FIELD_INFO(quantity_uncheck) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.quantity_uncheck");
	}
	//位置
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.workstation_name");
	}

};

//分页传输对象
class AwaitinSpectionPageDTO : public PageDTO<AwaitinSpectionDTO::Wrapper>
{
	DTO_INIT(AwaitinSpectionPageDTO, PageDTO<AwaitinSpectionDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_AWAITINSPECTION_DTO_

