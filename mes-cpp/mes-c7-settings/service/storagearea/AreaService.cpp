#include "stdafx.h"
#include "AreaService.h"
#include "../../dao/storagearea/AreaDAO.h"

AreaPageDTO::Wrapper AreaService::listAllAreabyPage(const AreaQuery::Wrapper& query)
{
	auto pages = AreaPageDTO::createShared();
	//当前页码
	pages->pageIndex = query->pageIndex;
	//每页查询条数
	pages->pageSize = query->pageSize;


	AreaDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	pages->total = count;
	pages->calcPages();
	std::list<AreaDO> res = dao.selectWithPage(query);
	for (AreaDO tmp : res)
	{
		auto dto = AreaDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, tmp,
			area_code, AreaCode, area_name, AreaName, areasize, AreaSize, enable_flag, Ison, id, Id, location_id, Lid, max_loa, MaxLoa, position_x, X, position_y, Y, position_z, Z, remarktext, Remark)
		pages->addData(dto);
	}

	return pages;
}

uint64_t AreaService::insertArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload)
{
	AreaDO data;
	data.setCreateBy(payload.getUsername());
	data.setUpdateBy(payload.getUsername());

	string createtime;
	string updatetime;

	time_t nowtime;
	struct tm* ptminfo;
	time(&nowtime);
	ptminfo = localtime(&nowtime);
	stringstream date;
	date << ptminfo->tm_year+1900 << "-" << ptminfo->tm_mon+1 << "-" << ptminfo->tm_mday << " " << ptminfo->tm_hour << ":" << ptminfo->tm_min << ":" << ptminfo->tm_sec;
	createtime = date.str();
	updatetime = date.str();
	data.setCreateTime(createtime);
	data.setUpdateTime(updatetime);

	data.setText1("");
	data.setText2("");
	data.setText3(0);
	data.setText4(0);

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		AreaCode, area_code, AreaName, area_name, AreaSize, areasize, 
		Ison, enable_flag, Id, id, Lid, location_id, MaxLoa, max_loa, X, position_x, Y, position_y, Z, position_z, Remark, remarktext)
	AreaDAO dao;
	return dao.insert(data);
}

bool AreaService::updateArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload)
{
	AreaDO data;
	data.setUpdateBy(payload.getUsername());
	string updatetime;

	time_t currtime;
	struct tm* p;
	time(&currtime);
	p = localtime(&currtime);
	stringstream ss;
	ss << p->tm_year+1900 << "-" << p->tm_mon+1 << "-" << p->tm_mday << " " << p->tm_hour << ":" << p->tm_min << ":" << p->tm_sec;
	updatetime = ss.str();

	data.setUpdateTime(updatetime);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		AreaCode, area_code, AreaName, area_name, AreaSize, areasize, Ison, enable_flag, Id, id, Lid, location_id, MaxLoa, max_loa, X, position_x, Y, position_y, Z, position_z, Remark, remarktext)

	AreaDAO dao;
	return dao.update(data) == 1;
}

bool AreaService::removeArea(std::list<int64_t>& ids)
{
	AreaDAO dao;
	return dao.deleteById(ids) == ids.size();
}
