#include "stdafx.h"
#include "RawMaterialOpService.h"
#include "dao/RawMaterialOp/RawMaterialOpDAO.h"


bool RawMaterialOpService::updateData(const RawMaterialOpDTO::Wrapper& dto)
{
	RawMaterialOpDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rt_Id, rt_id, Rt_Code, rt_code, Rt_Name, rt_name,
		Workororder_Id, workororder_id, Workororder_Code, workororder_code,
		Warehouse_Id, warehouse_id, Warehouse_Code, warehouse_code, Warehouse_Name, warehouse_name,
		Location_Id, location_id, Location_Code, location_code, Location_Name, location_name,
		Area_Id, area_id, Area_Code, area_code, Area_Name, area_name,
		Rt_Date, rt_date,
		Remark, remark);
	// ִ�������޸�
	RawMaterialOpDAO dao;
	return dao.update(data) == 1;
}

//ִ������ɾ��
bool RawMaterialOpService::removeData(uint64_t id)
{
	RawMaterialOpDAO dao;
	return dao.deleteById(id) == 1;
}

RawMaterialOpPageDTO::Wrapper RawMaterialOpService::listAll(const RawMaterialOpQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RawMaterialOpPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	RawMaterialOpDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RawMaterialOpDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (RawMaterialOpDO sub : result)
	{
		auto dto = RawMaterialOpDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rt_id, Rt_Id, rt_code, Rt_Code, rt_name, Rt_Name,
			workororder_id, Workororder_Id, workororder_code, Workororder_Code,
			warehouse_id, Warehouse_Id, warehouse_code, Warehouse_Code, warehouse_name, Warehouse_Name,
			location_id, Location_Id, location_code, Location_Code, location_name, Location_Name,
			area_id, Area_Id, area_code, Area_Code, area_name, Area_Name,
			rt_date, Rt_Date,
			remark, Remark);
		pages->addData(dto);
	}
	return pages;
}
