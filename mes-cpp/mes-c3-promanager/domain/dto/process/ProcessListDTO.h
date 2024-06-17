#pragma once
#ifndef _PROCESSLIST_DTO_
#define _PROCESSLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加工艺流程传输对象
 */
class ProcessAddDTO : public oatpp::DTO
{
	DTO_INIT(ProcessAddDTO, DTO);

	// 路线编号
	DTO_FIELD(String, routeCode);
	DTO_FIELD_INFO(routeCode) {
		info->description = ZH_WORDS_GETTER("process.field.code");
	}
	// 路线名称
	DTO_FIELD(String, routeName);
	DTO_FIELD_INFO(routeName) {
		info->description = ZH_WORDS_GETTER("process.field.name");
	}
	// 路线说明
	DTO_FIELD(String, routeDesc);
	DTO_FIELD_INFO(routeDesc) {
		info->description = ZH_WORDS_GETTER("process.field.desc");
	}
	// 是否启用
	DTO_FIELD(String, enableFlag);
	DTO_FIELD_INFO(enableFlag) {
		info->description = ZH_WORDS_GETTER("process.field.flag");
	}
	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("process.field.remark");
	}
};
/**
 * 工艺列表传输对象,与获取工艺详情一样
 */
class ProcessDTO : public ProcessAddDTO
{
	DTO_INIT(ProcessDTO, ProcessAddDTO);

	// 唯一标识
	DTO_FIELD(UInt64, routeId);
	DTO_FIELD_INFO(routeId) {
		info->description = ZH_WORDS_GETTER("process.field.id");
	}

};

/**
 * 工艺列表分页传输对象
 */
class ProcessListDTO : public PageDTO<ProcessDTO::Wrapper>
{
	DTO_INIT(ProcessListDTO, PageDTO<ProcessDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
