#pragma once
#ifndef _PRODUCTDTO_H_
#define _PRODUCTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//生产领料单列表数据模型
class ProductTableDTO :public oatpp::DTO
{
	DTO_INIT(ProductTableDTO, DTO);
	//唯一标识领料单id 隐藏
	API_DTO_FIELD(UInt64, issue_id, ZH_WORDS_GETTER("product.fields.issue_id"), true, 1);
	//领料单编号
	API_DTO_FIELD(String, issue_code, ZH_WORDS_GETTER("product.fields.issue_code"), true, "");
	//领料单名称
	API_DTO_FIELD(String, issue_name, ZH_WORDS_GETTER("product.fields.issue_name"), true, "");
	//生产工单
	API_DTO_FIELD(String, workorder_code, ZH_WORDS_GETTER("product.fields.workorder_code"), true, "");
	//客户编号
	API_DTO_FIELD(String, client_code, ZH_WORDS_GETTER("product.fields.client_code"), true, "");
	//客户名称
	API_DTO_FIELD(String, client_name, ZH_WORDS_GETTER("product.fields.client_name"), true, "");
	//领料日期
	API_DTO_FIELD(String, issue_date, ZH_WORDS_GETTER("product.fields.issue_date"), true, "");
	//单据状态
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("product.fields.status"), true, "");
};
//部门详情数据模型
class ProductDetailDTO :public ProductTableDTO
{
	DTO_INIT(ProductDetailDTO, ProductTableDTO);
	//领料仓库
	API_DTO_FIELD(String, warehouse_name, ZH_WORDS_GETTER("product.fields.warehouse_name"), true, "");
	//备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("product.fields.remark"), true, "");

};
class ProductPageDTO :public PageDTO<ProductTableDTO::Wrapper> {
	DTO_INIT(ProductPageDTO, PageDTO<ProductTableDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif