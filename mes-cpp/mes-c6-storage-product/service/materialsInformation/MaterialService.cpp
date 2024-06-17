#include "stdafx.h"
#include "MaterialService.h"
#include "../../dao/materialsInformation/MaterialDAO.h"

MaterialPageDTO::Wrapper MaterialService::listAll(const MaterialQuery::Wrapper& query)
{
	// �������ض���
	auto pages = MaterialPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	MaterialDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<MaterialDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (MaterialDO sub : result)
	{
		auto dto = MaterialDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, line_id, Line_id, issue_id, Issue_id, item_id, Item_id, item_code,Item_code, item_name, Item_name, specification, Specification, unit_of_measure, Unit_of_measure, quantity_issued, Quantity_issued, batch_code, Batch_code, warehouse_name, Warehouse_name, location_name, Location_name, area_name, Area_name, remark, Remark)
			pages->addData(dto);
	}
	return pages;
}

uint64_t MaterialService::saveData(const MaterialDTO::Wrapper& dto)
{
	// ��װDO����
	MaterialDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Issue_id, issue_id, Item_id, item_id, Item_code, item_code, Item_name, item_name, Specification, specification, Unit_of_measure, unit_of_measure, Quantity_issued, quantity_issued, Batch_code, batch_code, Warehouse_name, warehouse_name, Location_name, location_name, Area_name, area_name, Remark, remark)
		// ִ���������
		MaterialDAO dao;
	return dao.insert(data);
}

bool MaterialService::updateData(const MaterialDTO::Wrapper& dto)
{
	// ��װDO����
	MaterialDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Issue_id, issue_id, Item_id, item_id, Item_code, item_code, Item_name, item_name, Specification, specification, Unit_of_measure, unit_of_measure, Quantity_issued, quantity_issued, Batch_code, batch_code, Warehouse_name, warehouse_name, Location_name, location_name, Area_name, area_name, Remark, remark, Line_id, line_id)
		// ִ�������޸�
		MaterialDAO dao;
	return dao.update(data) == 1;
}

bool MaterialService::removeData(uint64_t id)
{
	MaterialDAO dao;
	return dao.deleteById(id) == 1;
}