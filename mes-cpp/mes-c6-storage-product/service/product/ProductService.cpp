#include "stdafx.h"
#include "ProductService.h"
#include "../../dao/product/ProductDAO.h"

ProductPageDTO::Wrapper ProductTableService::listAll(const ProductQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ProductPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProductTableDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProductTableDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
		// ��DOת����DTO
		auto dto = ProductDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, result, issue_id, Issue_id, issue_code, Issue_code, issue_name, Issue_name, workorder_code, Workorder_code, client_code, Client_code, client_name, Client_name, issue_date, Issue_date, status, Status1, warehouse_name, Warehouse_name,remark,Remark)
		return dto;
	}
