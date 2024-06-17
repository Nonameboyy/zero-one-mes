#pragma once

#ifndef _CHANGE_WORKWEAR_DTO_
#define _CHANGE_WORKWEAR_DTO_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增工作站数据模型
 */
class ChangeWorkwearDTO : public oatpp::DTO
{
	DTO_INIT(ChangeWorkwearDTO, DTO);
	// 工装夹具id
	API_DTO_FIELD_DEFAULT(UInt64, workwearId, ZH_WORDS_GETTER("getlist.fields.workwearId"));
	// 工装夹具类型名称
	API_DTO_FIELD_DEFAULT(String, workweartype, ZH_WORDS_GETTER("getlist.fields.workwearType"));
	// 工装夹具数量
	API_DTO_FIELD_DEFAULT(UInt64, workwearsum, ZH_WORDS_GETTER("getlist.fields.workwearsum"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // _USERDTO_H_