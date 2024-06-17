#pragma once
#ifndef _DELETEWHSTORAGEORDER_VO_
#define _DELETEWHSTORAGEORDER_VO_

#include "../../../GlobalInclude.h"
#include "../../../dto/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个删除入库单行的JsonVO，用于响应给客户端的Json对象
 */
class DeleteWhStorageorderVO :public JsonVO<DeleteWhStorageorderDTO::Wrapper> {
	DTO_INIT(DeleteWhStorageorderVO, JsonVO<DeleteWhStorageorderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELETEWHSTORAGEORDER_VO_
