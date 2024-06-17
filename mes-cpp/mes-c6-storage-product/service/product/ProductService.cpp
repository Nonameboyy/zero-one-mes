#include "stdafx.h"
#include "ProductService.h"
#include "../../dao/product/ProductDAO.h"

ProductPageDTO::Wrapper ProductTableService::listAll(const ProductQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ProductPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ProductTableDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProductTableDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ProductTableDO sub : result)
	{
		auto dto = ProductTableDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, issue_id, Issue_id, issue_code, Issue_code, issue_name, Issue_name, workorder_code, Workorder_code, client_code, Client_code, client_name, Client_name, issue_date, Issue_date, status, Status1)
			pages->addData(dto);
	}
	return pages;
}

ProductDetailDTO::Wrapper ProductDetailService::listONE(const int& issue_id){
		ProductDetailDAO dao;
		ProductDetailDO result = dao.selectWithDetail(issue_id);
		// 将DO转换成DTO
		auto dto = ProductDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, result, issue_id, Issue_id, issue_code, Issue_code, issue_name, Issue_name, workorder_code, Workorder_code, client_code, Client_code, client_name, Client_name, issue_date, Issue_date, status, Status1, warehouse_name, Warehouse_name,remark,Remark)
		return dto;
	}
