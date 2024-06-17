#pragma once
#ifndef _WAREHOUSE_INBOUND_VO_
#define _WAREHOUSE_INBOUND_VO_

#include "../../GlobalInclude.h"
#include "../../dto/WarehouseInbound/WarehouseInboundDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
	报工类型显示JsonVO，用于响应给客户端的Json对象

 */
class WarehouseInboundVO : public JsonVO<WarehouseInboundDTO::Wrapper> {
	DTO_INIT(WarehouseInboundVO, JsonVO<WarehouseInboundDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WAREHOUSE_INBOUND_VO_