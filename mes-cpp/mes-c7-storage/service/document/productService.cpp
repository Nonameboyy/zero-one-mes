#include "stdafx.h"
#include "productService.h"
#include "../../dao/document/productDAO.h"


ProductDTO::Wrapper ProductService::queryDetail(const ProductDetailQuery::Wrapper& query)
{
	// �������ض���
	auto detail = ProductDTO::createShared();

	ProductDAO dao;
	list<ProductDO> result = dao.detailmes(query);


	for (ProductDO sub : result)
	{
		auto dto = ProductDTO::createShared();
		dto->recpt_id = sub.getRecpt_id();
		dto->recpt_code = sub.getRecpt_code();
		dto->recpt_name = sub.getRecpt_name();
		dto->workorder_code = sub.getWorkorder_code();
		dto->product_name = sub.getProduct_name();
		dto->product_code= sub.getProduct_code();
		dto->recpt_date = sub.getRecpt_date();
		dto->status = sub.getStatus();

		dto->warehouse_name = sub.getWarehouse_name();




		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, recpt_id, Recpt_id, recpt_code, Recpt_code, recpt_name, Recpt_name, workorder_code, Workorder_code)
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, product_name, Product_name, product_code, Product_code, recpt_date, Recpt_date, status, Status, warehouse_name, Warehouse_name)

			detail = dto;
	}
	return detail;

}


ProductPageDTO::Wrapper ProductService::listAll(const ProductPageQuery::Wrapper& query)
{	// �������ض���
	auto pages = ProductPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProductDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProductDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ProductDO sub : result)
	{
		auto dto = ProductDTO::createShared();
	
		dto->recpt_id = sub.getRecpt_id();
		dto->recpt_code = sub.getRecpt_code();
		dto->recpt_name = sub.getRecpt_name();
		dto->workorder_code = sub.getWorkorder_code();
		dto->product_name = sub.getProduct_name();
		dto->product_code = sub.getProduct_code();
		dto->recpt_date = sub.getRecpt_date();
		dto->status = sub.getStatus();
		dto->warehouse_name = sub.getWarehouse_name();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, recpt_id, Recpt_id, recpt_code, Recpt_code, recpt_name, Recpt_name, workorder_code, Workorder_code)
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, product_name, Product_name, product_code, Product_code, recpt_date, Recpt_date, status, Status,warehouse_name,Warehouse_name)
			pages->addData(dto);

	}
	return pages;
}
