#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PRODUCT_RECPT_CONTROLLER_
#define _PRODUCT_RECPT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/item-information/ProductRecptQuery.h"
#include "domain/dto/item-information/ProductRecptDTO.h"
#include "domain/vo/item-information/ProductRecptVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 产品入库管理控制器
 */
class ProductRecptController : public oatpp::web::server::api::ApiController //继承控制器
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(ProductRecptController);
	//定义接口
public:
	// 1.1 定义分页查询接口描述,接口名为queryProductRecpt
	ENDPOINT_INFO(queryProductRecpt) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product-recpt.query.summary")); //分页查询产品入库数据
		//定义需要授权
		API_DEF_ADD_AUTH();
		//定义参数返回类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductRecptPageJsonVO);
		//定义分页查询参数
		API_DEF_ADD_PAGE_PARAMS();
		//定义其他参数
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_code", ZH_WORDS_GETTER("product-recpt.field.recpt_code"), "recpt_code", false);//入库单编号,输入可以为空
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_name", ZH_WORDS_GETTER("product-recpt.field.recpt_name"), "recpt_name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_code", ZH_WORDS_GETTER("product-recpt.field.workorder_code"), "workorder_code", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("product-recpt.field.warehouse_name"), "warehouse_name", false);
	}
	//1.2定义查询接口处理
	ENDPOINT(API_M_GET, "/storage/material/query-product_recpt-page", queryProductRecpt, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为ProductRecptQuery领域模型,包含查询信息(recpt_code,recpt_name,workorder_code,warehouse_name)
		API_HANDLER_QUERY_PARAM(query, ProductRecptQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryProductRecpt(query));
	}

	//2.1定义新增产品入库接口描述
	ENDPOINT_INFO(addProductRecpt) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product-recpt.post.summary"));//"新增一条产品入库数据"
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//2.2新增产品入库接口处理
	ENDPOINT(API_M_POST, "/storage/material/add-product_recpt", addProductRecpt, BODY_DTO(ProductRecptDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddProductRecpt(dto));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("product-recpt.put.summary"), modifyProductRecpt, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/storage/material/mod-product_recpt", modifyProductRecpt, BODY_DTO(ProductRecptDTO::Wrapper, dto), execModifyProductRecpt(dto));

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeProductRecpt) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("product-recpt.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "recpt_id", ZH_WORDS_GETTER("product-recpt.field.recpt_id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/storage/material/del-product_recpt-by-recpt_id/{recpt_id}", removeProductRecpt, PATH(UInt64, recpt_id), execRemoveProductRecpt(recpt_id));


private:
	// 1.3 分页查询产品入库
	ProductRecptPageJsonVO::Wrapper execQueryProductRecpt(const ProductRecptQuery::Wrapper& query);
	//2.3新增产品入库
	Uint64JsonVO::Wrapper execAddProductRecpt(const ProductRecptDTO::Wrapper& dto);
	// 3.3 删除入库单行
	Uint64JsonVO::Wrapper execRemoveProductRecpt(const UInt64& recpt_id);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyProductRecpt(const ProductRecptDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_PRODUCT_RECPT_CONTROLLER_