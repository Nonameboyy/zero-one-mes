#pragma once
#ifndef _DELETEWHSTORAGEORDER_DTO_
#define _DELETEWHSTORAGEORDER_DTO_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个删除用户信息的数据传输模型
 */
class DeleteWhStorageorderDTO : public oatpp::DTO
{
	DTO_INIT(DeleteWhStorageorderDTO, DTO);
	//标识删除入库单行的唯一id（主键）line_id bigint
	API_DTO_FIELD_DEFAULT(UInt64, line_id, ZH_WORDS_GETTER("whstorageorder.field.line_id"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEWHSTORAGEORDER_DTO_
