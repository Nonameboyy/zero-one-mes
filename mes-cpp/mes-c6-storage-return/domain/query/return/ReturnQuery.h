#pragma once

#ifndef _RETURNQUERY_H_
#define _RETURNQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询单据信息的数据传输模型
 */
class ReturnQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(ReturnQuery, PageQuery);
	// 退货单编号
	API_DTO_FIELD_DEFAULT(String, returnCode, ZH_WORDS_GETTER("return.fields.rtcode"));
	// 退货单名称
	API_DTO_FIELD_DEFAULT(String, returnName, ZH_WORDS_GETTER("return.fields.rtname"));
	// 采购单编号
	API_DTO_FIELD_DEFAULT(String, purchaseCode, ZH_WORDS_GETTER("return.fields.pucode"));
	// 供应商名称
	API_DTO_FIELD_DEFAULT(String, vendorName, ZH_WORDS_GETTER("return.fields.vename"));
};

/**
* 定义一个查询单一单据详细信息的数据传输模型
*/
class ReturnDetailQuery : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(ReturnDetailQuery, oatpp::DTO);
	// 退货单编号
	API_DTO_FIELD(String, returnCode, ZH_WORDS_GETTER("return.fields.rtcode"), true, "notnull");
};

/**
* 定义一个添加新退货单据信息的数据传输模型
*/
class ReturnAdd : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(ReturnAdd, oatpp::DTO);
	// 退货单编号
	API_DTO_FIELD(String, returnCode, ZH_WORDS_GETTER("return.fields.rtcode"), true, "RTV123");
	// 退货单名称
	API_DTO_FIELD(String, returnName, ZH_WORDS_GETTER("return.fields.rtname"), true, "01star");
	// 采购单编号
	API_DTO_FIELD(String, purchaseCode, ZH_WORDS_GETTER("return.fields.pucode"), false, "null");
	// 供应商名称
	API_DTO_FIELD(String, vendorName, ZH_WORDS_GETTER("return.fields.vename"), true, "01star");
	// 批次号
	API_DTO_FIELD(String, batchCode, ZH_WORDS_GETTER("return.fields.batchcode"), false, "null");
	// 退货日期
	API_DTO_FIELD(String, returndate, ZH_WORDS_GETTER("return.fields.rtdate"), true, "2024-5-21");
	// 单据状态
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("return.fields.status"), true, "PREPARE");
	// 备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("return.fields.remark"), false, " ");
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_RETURNQUERY_H_