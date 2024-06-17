#include "stdafx.h"
#include "ProcessListService.h"
#include "../../dao/process/ProcessDAO.h"

// 分页查询工艺列表数据
ProcessListDTO::Wrapper ProcessListService::listAll(const ProcessListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ProcessListDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//查询数据总条数
	ProcessDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProRouteDO> result = dao.selectWithPage(query);
	//将DO转换成DTO
	for (ProRouteDO sub : result)
	{
		auto dto = ProcessDTO::createShared();
		dto->routeId = sub.getRouteId();
		dto->routeCode = sub.getRouteCode();
		dto->routeName = sub.getRouteName();
		dto->routeDesc = sub.getRouteDesc();
		dto->enableFlag = sub.getEnableFlag();
		dto->remark = sub.getRemark();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, routeid, RouteId, routecode, RouteCode, routedesc, RouteDesc, enableflag, EnableFlag, remark, Remark)
			pages->addData(dto);
	}
	
	return pages;
}

// 通过id查询工艺详情
ProcessDTO::Wrapper ProcessListService::getById(const ProcessDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto dto = ProcessDTO::createShared();

	ProcessDAO dao;
	list<ProRouteDO> result = dao.selectById(query);

	//将DO转换成DTO
	for (ProRouteDO sub : result)
	{
		dto->routeId = sub.getRouteId();
		dto->routeCode = sub.getRouteCode();
		dto->routeName = sub.getRouteName();
		dto->routeDesc = sub.getRouteDesc();
		dto->enableFlag = sub.getEnableFlag();
		dto->remark = sub.getRemark();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, routeId, RouteId, routeCode, RouteCode, routeDesc, RouteDesc, enableFlag, EnableFlag, remark, Remark)
	}

	return dto;
}
// 添加工艺 保存数据
uint64_t ProcessListService::saveProcessAdd(const ProcessAddDTO::Wrapper& dto, const string username)
{
	// 组装DO数据
	ProRouteDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RouteCode, routeCode, RouteName, routeName, RouteDesc, routeDesc, EnableFlag, enableFlag, Remark, remark)
	// 执行数据添加
	ProcessDAO dao;
	return dao.insert(data, username);
}
/**
 * 修改工艺的service
 */
bool ProcessListService::updateData(const ProcessDTO::Wrapper& dto, const string updatename)
{
	// 组装DO数据
	ProRouteDO data;
	/*data.setRouteCode(dto->routeCode.getValue({})); 
	data.setRouteName(dto->routeName.getValue({})); 
	data.setRouteDesc(dto->routeDesc.getValue({})); 
	data.setEnableFlag(dto->enableFlag.getValue({})); 
	data.setRemark(dto->remark.getValue({})); 
	data.setRouteId(dto->routeId.getValue({}));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RouteCode, routeCode, RouteName, routeName, RouteDesc, routeDesc, EnableFlag, enableFlag, Remark, remark, RouteId, routeId)
	ProcessDAO dao;
	return dao.update(data, updatename) == 1;
}
/**
* 导出工艺
*/
list<ProcessAddDTO::Wrapper> ProcessListService::listAllForProcess(const ProcessListQuery::Wrapper& query)
{
	// 构建返回对象
	list<ProcessAddDTO::Wrapper> data;

	// 查询数据总条数
	ProcessDAO dao;
	list<ProRouteDO> result = dao.selectWithProcessExport(query);

	// 将DO转换成DTO
	for (ProRouteDO sub : result)
	{
		auto dto = ProcessAddDTO::createShared();
		dto->routeCode = sub.getRouteCode();
		dto->routeName = sub.getRouteName();
		dto->routeDesc = sub.getRouteDesc();
		dto->enableFlag = sub.getEnableFlag();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, routeCode, RouteCode, routedesc, RouteDesc, enableflag, EnableFlag, remark, Remark)
		data.emplace_back(dto);
	}
	return data;
}
//删除工艺
bool ProcessListService::removeData(uint64_t id)
{
	ProcessDAO dao;
	return dao.deleteById(id) == 1;
}