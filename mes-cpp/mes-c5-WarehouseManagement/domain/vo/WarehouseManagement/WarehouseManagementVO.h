#pragma once

#ifndef _WAREHOUSEMANAGEMENT_VO_
#define _WAREHOUSEMANAGEMENT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/WarehouseManagement/WarehouseManagementDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class WarehouseManagementJsonVO : public JsonVO<WarehouseManagementDTO::Wrapper> {
	DTO_INIT(WarehouseManagementJsonVO, JsonVO<WarehouseManagementDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class WarehouseManagementPageJsonVO : public JsonVO<WarehouseManagementPageDTO::Wrapper> {
	DTO_INIT(WarehouseManagementPageJsonVO, JsonVO<WarehouseManagementPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WAREHOUSEMANAGEMENT_VO_