#pragma once
#ifndef _product_DTO_
#define _product_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 入库单据列表数据模型
 */
class ProductDTO : public oatpp::DTO
{
	DTO_INIT(ProductDTO, DTO);
	// 入库单id（唯一）
	API_DTO_FIELD(UInt64, recpt_id, ZH_WORDS_GETTER("product.fields.recpt_id"), true, 1);
	// 入库单编号
	API_DTO_FIELD(String, recpt_code, ZH_WORDS_GETTER("product.fields.recpt_code"), true, "rt_code");
	// 入库单名称
	API_DTO_FIELD(String, recpt_name, ZH_WORDS_GETTER("product.fields.recpt_name"), true, "rt_name");
	// 生产工单编码
	API_DTO_FIELD(String, workorder_code, ZH_WORDS_GETTER("product.fields.workorder_code"), true, "workorder_code");
	// 产品编码
	API_DTO_FIELD(String, product_code, ZH_WORDS_GETTER("product.fields.product_code"), true, "product_code");
	// 产品名称
	API_DTO_FIELD(String, product_name, ZH_WORDS_GETTER("product.fields.product_name"), true, " product_name");
	//
	API_DTO_FIELD(String, warehouse_name, ZH_WORDS_GETTER("product.fields.warehouse_name"), true, " warehouse_name");
	//
	//入库日期
	API_DTO_FIELD(String, recpt_date, ZH_WORDS_GETTER("product.fields.recpt_date"), true, "2024-05-17 00:29:30");
	//单据状态
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("product.fields.status"), true, "default");
};

/**
 * 退料列表分页传输对象
 */
class ProductPageDTO : public PageDTO<ProductDTO::Wrapper>
{
	DTO_INIT(ProductPageDTO, PageDTO<ProductDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_#pragma once
