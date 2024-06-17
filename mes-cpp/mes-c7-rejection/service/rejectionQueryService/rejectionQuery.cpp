#include "stdafx.h"
#include "rejectionQuery.h"
#include "../../dao/rejection/rejectionQueryDAO.h"


RejectDetailDTO::Wrapper RejectTableQueryService::queryDetail(const RejectDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto detail = RejectDetailDTO::createShared();

	RejectDAO dao;
	list<RejectQueryDO> result=dao.detailmes(query); 
	
	
	for (RejectQueryDO sub : result)
	{
		auto dto = RejectDetailDTO::createShared();
		dto->rt_id = sub.getRt_id();
		dto->rt_code = sub.getRt_code();
		dto->rt_name = sub.getRt_name();
		dto->workorder_id = sub.getWorkorder_id();
		dto->location_name = sub.getLocation_name();
		dto->area_name = sub.getArea_name();
		dto->rt_date = sub.getRt_date();
		dto->status = sub.getStatus();
		//.............................
		dto->warehouse_name = sub.getWarehouse_name();
		dto->workorder_code = sub.getWorkorder_code();
		dto->workorder_id = sub.getWorkorder_id();
		dto->warehouse_code = sub.getWarehouse_code();
		dto->location_id = sub.getLocation_id();
		dto->location_code = sub.getLocation_code();
		dto->area_id = sub.getArea_id();
		dto->area_code = sub.getArea_code();


		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rt_id, Rt_id, rt_code, Rt_code, rt_name, Rt_name, workorder_id, Workorder_id)
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, location_name, Location_name, area_name, Area_name, rt_date, Rt_date, status, Status)
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, warehouse_name, Warehouse_name, workorder_code, Workorder_code, workorder_id, Workorder_id, warehouse_code, Warehouse_code)
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, location_id, Location_id, location_code, Location_code, area_id, Area_id, area_code, Area_code)

			detail = dto;
	}
			return detail;

}


RejectPageDTO::Wrapper RejectTableQueryService::listAll(const RejectQuery::Wrapper& query)
{	// 构建返回对象
	auto pages = RejectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RejectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RejectQueryDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RejectQueryDO sub : result)
	{
		auto dto = RejectTableDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		dto->rt_id = sub.getRt_id();
		dto->rt_code = sub.getRt_code();
		dto->rt_name = sub.getRt_name();
		dto->workorder_id = sub.getWorkorder_id();
		dto->location_name = sub.getLocation_name();
		dto->area_name = sub.getArea_name();
		dto->rt_date = sub.getRt_date();
		dto->status = sub.getStatus();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rt_id, Rt_id, rt_code, Rt_code, rt_name, Rt_name, workorder_id, Workorder_id)
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, location_name, Location_name, area_name, Area_name, rt_date, Rt_date, status, Status)
			pages->addData(dto);

	}
	return pages;
}
//保存数据
uint64_t RejectTableQueryService::saveData(const RejectTableDTO::Wrapper& dto)
{
	// 组装DO数据
	RejectQueryDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	data.setRt_code(dto->rt_code.getValue(""));
	data.setRt_id(dto->rt_id.getValue(1));
	data.setRt_name(dto->rt_name.getValue(""));
	data.setWorkorder_id(dto->workorder_id.getValue(""));
	data.setWarehouse_name(dto->warehouse_name.getValue(""));
	data.setLocation_name(dto->location_name.getValue(""));
	data.setArea_name(dto->area_name.getValue(""));
	data.setRt_date(dto->rt_date.getValue(""));
	data.setStatus(dto->status.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,  Rt_id,rt_id,Rt_code ,rt_code, Rt_name, rt_name,  Workorder_id, workorder_id)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Location_name, location_name, Area_name, area_name,  Rt_date,rt_date,  Status,status )
		// 执行数据添加
		RejectDAO dao;
	return dao.insert(data);
}

bool RejectTableQueryService::updateData(const RejectTableDTO::Wrapper& dto)
{
	// 组装DO数据
	RejectQueryDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	data.setRt_code(dto->rt_code.getValue(""));
	data.setRt_id(dto->rt_id.getValue(1));
	data.setRt_name(dto->rt_name.getValue(""));
	data.setWorkorder_id(dto->workorder_id.getValue(""));
	data.setWarehouse_name(dto->warehouse_name.getValue(""));
	data.setLocation_name(dto->location_name.getValue(""));
	data.setArea_name(dto->area_name.getValue(""));
	data.setRt_date(dto->rt_date.getValue(""));
	data.setStatus(dto->status.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rt_id, rt_id, Rt_code, rt_code, Rt_name, rt_name, Workorder_id, workorder_id)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Location_name, location_name, Area_name, area_name, Rt_date, rt_date, Status, status)
		// 执行数据修改
		RejectDAO dao;
	return dao.update(data) == 1;
}
