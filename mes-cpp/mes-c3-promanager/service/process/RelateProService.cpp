#include "stdafx.h"
#include "RelateProService.h"
#include "../../dao/process/RelateProDAO.h"

//添加关联产品
uint64_t RelateProService::saveData(const AddRelateProDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	ProRouteProductDO data;
		data.setItem_Code(dto->item_code.getValue(""));
		data.setItem_Name(dto->item_name.getValue(""));
		data.setSpecification(dto->specification.getValue(""));
		data.setUnit_Of_Measure(dto->unit_of_measure.getValue(""));
		data.setRemark(dto->remark.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Item_Code, item_code, Item_Name, item_name, Specification, specification,
							Unit_Of_Measure, unit_of_measure, Remark,remark)
		// 执行数据添加
		RelateProDAO dao;
	return dao.insert(data, payload);
}
//修改关联产品
bool RelateProService::updateData(const ModRelateProDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	ProRouteProductDO data;
	data.setItem_Code(dto->item_code.getValue(""));
	data.setItem_Name(dto->item_name.getValue(""));
	data.setSpecification(dto->specification.getValue(""));
	data.setUnit_Of_Measure(dto->unit_of_measure.getValue(""));
	data.setRemark(dto->remark.getValue(""));
	data.setRecord_Id(dto->record_id.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Item_Code, item_code, Item_Name, item_name, Specification, specification,
		Unit_Of_Measure, unit_of_measure, Remark, remark, Record_Id, record_id)
		// 执行数据修改
		RelateProDAO dao;
	return dao.update(data, payload) == 1;
}
//删除关联产品
bool RelateProService::removeData(uint64_t id)
{
	RelateProDAO dao;
	return dao.deleteById(id) == 1;
}
//导出关联产品
ExportRelateProDTO::Wrapper RelateProService::listAll(const uint64_t& id)
{
	RelateProDAO dao;
	list<ProRouteProductDO> result = dao.selectById(id);
	if (result.empty())
		printf("-----------------error-----------------------\n");
	ProRouteProductDO DO = result.front();
	auto dto = ExportRelateProDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, DO, record_id, Record_Id, route_id, Route_Id, item_id, Item_Id, item_name, Item_Name, unit_of_measure, Unit_Of_Measure, specification, Specification, RPmodels, Remark)
		return dto;
}

