#pragma once
#ifndef _GETPRODWORKORDERLIST_VO_
#define _GETPRODWORKORDERLIST_VO_
#include "../../GlobalInclude.h"
#include "../../dto/ProdWorkorder/GetProdWorkorderListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取生产工单列表显示JsonVO，用于响应给客户端的Json对象
 */
class GetProdWorkorderListJsonVO : public JsonVO<oatpp::List<GetProdWorkorderListDTO::Wrapper>> {
	DTO_INIT(GetProdWorkorderListJsonVO, JsonVO<List<GetProdWorkorderListDTO::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	GetProdWorkorderListJsonVO() {
		this->data = {};
	}
};

/**
 * 获取生产工单列表分页显示JsonVO，用于响应给客户端的Json对象
 */
class GetProdWorkorderListPageJsonVO : public JsonVO<GetProdWorkorderListPageDTO::Wrapper> {
	DTO_INIT(GetProdWorkorderListPageJsonVO, JsonVO<GetProdWorkorderListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETPRODWORKORDERLIST_VO_