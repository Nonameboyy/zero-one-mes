#pragma once

#ifndef _RECEIPT_DTO_H
#define _RECEIPT_DTO_H

#include "../../GlobalInclude.h"
#include "../../dto/Receipt/ReceiptDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 单据列表数据模型
*/
class ReceiptDTO : public oatpp::DTO
{
	DTO_INIT(ReceiptDTO, DTO);
	// 数据库的表： wm_item_recpt 

	// 入库单ID
	API_DTO_FIELD_DEFAULT(Int32, recptId, ZH_WORDS_GETTER("receipt.query.fields.recptId"));

	// 入库单编号
	API_DTO_FIELD_DEFAULT(String, recptCode, ZH_WORDS_GETTER("receipt.query.fields.recptCode"));

	// 入库单名称
	API_DTO_FIELD_DEFAULT(String, recptName, ZH_WORDS_GETTER("receipt.query.fields.recptName"));

	// 供应商名称
	API_DTO_FIELD_DEFAULT(String, vendorName, ZH_WORDS_GETTER("receipt.query.fields.vendorName"));

	// 订单编号
	API_DTO_FIELD_DEFAULT(String, poCode, ZH_WORDS_GETTER("receipt.query.fields.poCode"));

	// 入库日期 
	API_DTO_FIELD_DEFAULT(String, recptDate, ZH_WORDS_GETTER("receipt.query.fields.recptDate"));

	// 单据状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("receipt.query.fields.status"));

};

/**
* 单据列表数据模型(分页传输对象)
*/
class ReceiptPageTableDTO : public PageDTO<ReceiptDTO::Wrapper>
{
	DTO_INIT(ReceiptPageTableDTO, PageDTO<ReceiptDTO::Wrapper>);
};

/**
* 单据列表数据详情
*/
class ReceiptDetailDTO : public ReceiptDTO
{
	DTO_INIT(ReceiptDetailDTO, DTO);
	// 数据库的表： wm_item_recpt
	
	// 入库仓库
	API_DTO_FIELD_DEFAULT(String, warehouseName, ZH_WORDS_GETTER("receipt.query.fields.warehouseName"));

	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("receipt.query.fields.remark"));


};

#include OATPP_CODEGEN_END(DTO)

#endif // _RECEIPT_DTO_H