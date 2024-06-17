#include "stdafx.h"
#include "storageService.h"
#include "dao/storage/storageDAO.h"


uint64_t storageService::update(const storageDTO::Wrapper& dto)
{
	storageDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Re_Id, re_id, Re_Code, re_code, Re_Name, re_name,
		Workororder_Id, workororder_id, Workororder_Code, workororder_code,
		Warehouse_Id, warehouse_id, Warehouse_Code, warehouse_code, Warehouse_Name, warehouse_name,
		Location_Id, location_id, Location_Code, location_code, Location_Name, location_name,
		Area_Id, area_id, Area_Code, area_code, Area_Name, area_name,
		Re_Date, re_date,
		Remark, remark);
	// ִ�������޸�
	storageDAO dao;
	return dao.update(data) == 1;
}

//ִ������ɾ��
bool storageService::removeData(uint64_t id)
{
	storageDAO dao;
	return dao.deleteById(id) == 1;
}

storagePageDTO::Wrapper storageService::listAll(const storageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = storagePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	storageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<storageDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (storageDO sub : result)
	{
		auto dto = storageDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, re_id, Re_Id, re_code, Re_Code, re_name, Re_Name,
			workororder_id, Workororder_Id, workororder_code, Workororder_Code,
			warehouse_id, Warehouse_Id, warehouse_code, Warehouse_Code, warehouse_name, Warehouse_Name,
			location_id, Location_Id, location_code, Location_Code, location_name, Location_Name,
			area_id, Area_Id, area_code, Area_Code, area_name, Area_Name,
			re_date, Re_Date,
			remark, Remark);
		pages->addData(dto);
	}
	return pages;
}
