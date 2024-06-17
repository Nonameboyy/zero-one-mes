#pragma once

#ifndef _RECEIPTVO_VO_H
#define _RECEIPTVO_VO_H

#include "../../GlobalInclude.h"
#include "../../dto/Receipt/ReceiptDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 定义一个获取单据列表的显示VO
*/
class ReceiptPageTableJsonVO : public JsonVO<ReceiptPageTableDTO::Wrapper>
{
	DTO_INIT(ReceiptPageTableJsonVO, JsonVO<ReceiptPageTableDTO::Wrapper>);
};

/**
* 定义一个获取单据详情的显示VO
*/
class ReceiptDetailJsonVO : public JsonVO<ReceiptDetailDTO::Wrapper>
{
	DTO_INIT(ReceiptDetailJsonVO, JsonVO<ReceiptDetailDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // _RECEIPTVO_VO_H