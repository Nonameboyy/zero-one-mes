#pragma once

#ifndef _RECEIPTVO_VO_H
#define _RECEIPTVO_VO_H

#include "../../GlobalInclude.h"
#include "../../dto/Receipt/ReceiptDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ����һ����ȡ�����б����ʾVO
*/
class ReceiptPageTableJsonVO : public JsonVO<ReceiptPageTableDTO::Wrapper>
{
	DTO_INIT(ReceiptPageTableJsonVO, JsonVO<ReceiptPageTableDTO::Wrapper>);
};

/**
* ����һ����ȡ�����������ʾVO
*/
class ReceiptDetailJsonVO : public JsonVO<ReceiptDetailDTO::Wrapper>
{
	DTO_INIT(ReceiptDetailJsonVO, JsonVO<ReceiptDetailDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // _RECEIPTVO_VO_H