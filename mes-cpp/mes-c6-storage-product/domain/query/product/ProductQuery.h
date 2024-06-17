#pragma once
#ifndef _PRODUCTQUERY_H_
#define _PRODUCTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 生产领料列表查询
 */
class ProductQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(ProductQuery, PageQuery);
	//领料单编号
	API_DTO_FIELD_DEFAULT(String, issue_code, ZH_WORDS_GETTER("product.fields.issue_code"));
	//领料单名称
	API_DTO_FIELD_DEFAULT(String, issue_name, ZH_WORDS_GETTER("product.fields.issue_name"));
	//仓库名称
	API_DTO_FIELD_DEFAULT(String, warehouse_name, ZH_WORDS_GETTER("product.fields.warehouse_name"));
	//领料日期
	API_DTO_FIELD_DEFAULT(String, issue_date, ZH_WORDS_GETTER("product.fields.issue_date"));
	//单据状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("product.fields.status"));

};
//详情查询
class ProductDetailQuery : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(ProductDetailQuery, DTO);
	//领料单编号
	API_DTO_FIELD_DEFAULT(UInt64, issue_id, ZH_WORDS_GETTER("product.fields.issue_id"));
	

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DEPTQUERY_H_