#include "stdafx.h"
#include "productController.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/PayloadDTO.h"
#include "domain/dto/PayloadDTO.h"
#include"service/document/productService.h"

// 3.3 演示分页查询数据
ProductPageJsonVO::Wrapper ProductController::execQueryProduct(const ProductPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ProductService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ProductPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
//detailQuery
ProductJsonVO::Wrapper ProductController::execQueryProductDetail(const ProductDetailQuery::Wrapper& query)
{
	// 定义一个Service
	ProductService service;
	// 查询数据
	auto result = service.queryDetail(query);
	// 响应结果
	auto jvo = ProductJsonVO::createShared();
	jvo->success(result);
	return jvo;
}