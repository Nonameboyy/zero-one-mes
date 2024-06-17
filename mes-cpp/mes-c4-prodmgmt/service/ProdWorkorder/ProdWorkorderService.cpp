#include "stdafx.h"
#include "ProdWorkorderService.h"
#include "../../dao/ProdWorkorder/ProdWorkorderDAO.h"

//获取生产工单详情
ProdWorkorderInfoDTO::Wrapper ProdWorkorderService::listDetail(const uint64_t& workorder_id) {
	
	ProdWorkorderDAO dao;
	list<ProdWorkorderInfoDO> result = dao.selectByWorkorderId(workorder_id);
	auto temp_dto = ProdWorkorderInfoDTO::createShared();
	for (ProdWorkorderInfoDO sub : result) {

		ZO_STAR_DOMAIN_DO_TO_DTO(temp_dto, sub, workorder_id, Workorder_id, workorder_code, Workorder_code, workorder_name, Workorder_name, order_source, Order_source, source_code, Source_code, status, Status, workorder_type, Workorder_type, product_code, Product_code, product_name, Product_name, product_spc, Product_spc, unit_of_measure, Unit_of_measure, quantity, Quantity, request_date, Request_date, batch_code, Batch_code, client_code, Client_code, client_name, Client_name, vendor_code, Vendor_code, vendor_name, Vendor_name, remark, Remark)

	}
	return temp_dto;
	//// 组装DO数据
	//ProdWorkorderInfoDO data;
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Workorder_id, workorder_id)
	////ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Workorder_id, workorder_id, Workorder_code, workorder_code, Workorder_name, workorder_name, Order_source, order_source, Source_code, source_code, Status, status, Workorder_type, workorder_type, Product_code, product_code, Product_name, product_name, Product_spc, product_spc, Unit_of_measure, unit_of_measure, Quantity, quantity, Request_date, request_date, Batch_code, batch_code, Client_code, client_code, Client_name, client_name, Vendor_code, vendor_code, Vendor_name, vendor_name, Remark, remark)
	//
	//// 执行数据添加
	//ProdWorkorderDAO dao;	
	// DO转DTO
	//list<ProdWorkorderInfoDO> result = dao.selectByWorkorderId(data);
	//auto temp_dto = ProdWorkorderInfoDTO::createShared();
	//for (ProdWorkorderInfoDO sub : result) {	
	//	
	//	ZO_STAR_DOMAIN_DO_TO_DTO(temp_dto, sub, workorder_id, Workorder_id, workorder_code, Workorder_code, workorder_name, Workorder_name, order_source, Order_source, source_code, Source_code, status, Status, workorder_type, Workorder_type, product_code, Product_code, product_name, Product_name, product_spc, Product_spc, unit_of_measure, Unit_of_measure, quantity, Quantity, request_date, Request_date, batch_code, Batch_code, client_code, Client_code, client_name, Client_name, vendor_code, Vendor_code, vendor_name, Vendor_name, remark, Remark)
	//	
	//}
	//return temp_dto;
}

//获取生产工单列表
GetProdWorkorderListPageDTO::Wrapper ProdWorkorderService::listAll(const GetProdWorkorderListQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = GetProdWorkorderListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ProdWorkorderDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GetProdWorkorderListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (GetProdWorkorderListDO sub : result)
	{
		auto dto = GetProdWorkorderListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, workorder_id, Workorder_id, workorder_code, Workorder_code, workorder_name, Workorder_name, workorder_type, Workorder_type, order_source, Order_source, source_code, Source_code, product_code, Product_code, product_name, Product_name, product_spc, Product_spc, unit_of_measure, Unit_of_measure, quantity, Quantity, quantity_changed, Quantity_changed, quantity_produced, Quantity_produced, batch_code, Batch_code, client_code, Client_code, client_name, Client_name, request_date, Request_date, status , Status)
		pages->addData(dto);
	}
	return pages;
}

//获取生产工单BOM列表
ProdWorkorderBomListPageDTO::Wrapper ProdWorkorderService::listBom(const ProdWorkorderBomListQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = ProdWorkorderBomListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ProdWorkorderDAO dao;
	uint64_t count = dao.countBom(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProdWorkorderBomListDO> result = dao.selectByBomId(query);
	// 将DO转换成DTO
	for (ProdWorkorderBomListDO sub : result)
	{
		auto dto = ProdWorkorderBomListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, line_id, Line_id, item_code, Item_code, item_name, Item_name, item_spc, Item_spc, unit_of_measure, Unit_of_measure, item_or_product, Item_or_product, quantity, Quantity)
		pages->addData(dto);
	}
	return pages;
}

//添加生产工单
uint64_t ProdWorkorderService::saveData(const AddProdWorkorderDTO::Wrapper& dto)
{
	// 组装DO数据
	AddProdWorkorderDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Workorder_id, workorder_id, Workorder_code, workorder_code, Workorder_name, workorder_name, Order_source, order_source, Status, status, Workorder_type, workorder_type, Product_code, product_code, Product_name, product_name, Product_spc, product_spc, Unit_of_measure, unit_of_measure, Quantity, quantity, Request_date, request_date, Batch_code, batch_code, Remark, remark, Product_id, product_id, Ancestors, ancestors)
	// 执行数据添加
	ProdWorkorderDAO dao;
	return dao.insert(data);
}