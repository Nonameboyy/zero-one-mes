#include "stdafx.h"
#include "productController.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/PayloadDTO.h"
#include "domain/dto/PayloadDTO.h"
#include"service/document/productService.h"

// 3.3 ��ʾ��ҳ��ѯ����
ProductPageJsonVO::Wrapper ProductController::execQueryProduct(const ProductPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ProductService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ProductPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
//detailQuery
ProductJsonVO::Wrapper ProductController::execQueryProductDetail(const ProductDetailQuery::Wrapper& query)
{
	// ����һ��Service
	ProductService service;
	// ��ѯ����
	auto result = service.queryDetail(query);
	// ��Ӧ���
	auto jvo = ProductJsonVO::createShared();
	jvo->success(result);
	return jvo;
}