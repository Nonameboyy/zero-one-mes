#pragma once
#ifndef _GETPRODWORKORDERLIST_VO_
#define _GETPRODWORKORDERLIST_VO_
#include "../../GlobalInclude.h"
#include "../../dto/ProdWorkorder/GetProdWorkorderListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ���������б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetProdWorkorderListJsonVO : public JsonVO<oatpp::List<GetProdWorkorderListDTO::Wrapper>> {
	DTO_INIT(GetProdWorkorderListJsonVO, JsonVO<List<GetProdWorkorderListDTO::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	GetProdWorkorderListJsonVO() {
		this->data = {};
	}
};

/**
 * ��ȡ���������б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetProdWorkorderListPageJsonVO : public JsonVO<GetProdWorkorderListPageDTO::Wrapper> {
	DTO_INIT(GetProdWorkorderListPageJsonVO, JsonVO<GetProdWorkorderListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETPRODWORKORDERLIST_VO_