#pragma once

#ifndef _RECEIPT_QUERY_H
#define _RECEIPT_QUERY_H

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 单据列表查询，封装查询条件 分页查询
*/
class ReceiptTableQuery : public PageQuery
{
	DTO_INIT(ReceiptTableQuery, PageQuery);
	// 数据库的表： wm_item_recpt
	
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

};


/**
* 单据查询，查询单据详情
*/
class ReceiptDetailQuery : public oatpp::DTO
{
	DTO_INIT(ReceiptDetailQuery, DTO);
	// 数据库的表： wm_item_recpt

	// 入库单编号
	API_DTO_FIELD_DEFAULT(String, recptCode, ZH_WORDS_GETTER("prodmgmt.delete.fields.recptCode"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // _RECEIPT_QUERY_H