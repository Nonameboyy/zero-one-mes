#pragma once

#ifndef _WAREHOUSEMANAGEMENT_VO_
#define _WAREHOUSEMANAGEMENT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/WarehouseManagement/WarehouseManagementDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class WarehouseManagementJsonVO : public JsonVO<WarehouseManagementDTO::Wrapper> {
	DTO_INIT(WarehouseManagementJsonVO, JsonVO<WarehouseManagementDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class WarehouseManagementPageJsonVO : public JsonVO<WarehouseManagementPageDTO::Wrapper> {
	DTO_INIT(WarehouseManagementPageJsonVO, JsonVO<WarehouseManagementPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WAREHOUSEMANAGEMENT_VO_