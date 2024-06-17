#include "stdafx.h"
#include "DetectionItemSettingsService.h"
#include "../../domain/do/DetectionItemSettings/DetectionItemSettingsDO.h"
#include "../../dao/DetectionItemSettings/DetectionItemSettingsDAO.h"

DetectionItemSettingsPageDTO::Wrapper DetectionItemSettingsService::listAll(const DetectionItemSettingsQuery::Wrapper& query)
{
	auto pages = DetectionItemSettingsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	DetectionItemSettingsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)	return pages;
	pages->total = count;
	pages->calcPages();
	list<DetectionItemSettingsDO> res = dao.selectWithPage(query,0);

	for (DetectionItemSettingsDO sub : res) {
		auto dto = DetectionItemSettingsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, code, Code, name, Name, type, Type, tool, Tool, remark, Remark);
		pages->addData(dto);
	}
	return pages;
	return {};
}

uint64_t DetectionItemSettingsService::saveData(const DetectionItemSettingsDTO::Wrapper& dto)
{
	DetectionItemSettingsDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Code, code, Name, name, Type, type, Tool, tool, Remark, remark);
	DetectionItemSettingsDAO dao;
	return dao.insert(data);
	return {};
}

bool DetectionItemSettingsService::updateData(const DetectionItemSettingsDTO::Wrapper& dto)
{
	DetectionItemSettingsDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Code, code, Name, name, Type, type, Tool, tool, Remark, remark);
	DetectionItemSettingsDAO dao;
	return dao.update(data) == 1;
	return true;
}

bool DetectionItemSettingsService::removeData(uint64_t id)
{
	DetectionItemSettingsDAO dao;
	return dao.remove(id) == 1;
	return 1;
}

list<DetectionItemSettingsDO> DetectionItemSettingsService::listAllExort(const DetectionItemSettingsQuery::Wrapper& query)
{
	DetectionItemSettingsDAO dao;
	//查看数据是否存在
	auto count = dao.count(query);
	//不存在返回空
	if (count < 1)
		return {};
	//查询所有数据
	auto dos = dao.selectWithPage(query, 1);
	return dos;
}
