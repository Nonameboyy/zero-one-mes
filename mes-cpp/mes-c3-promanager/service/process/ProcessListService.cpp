#include "stdafx.h"
#include "ProcessListService.h"
#include "../../dao/process/ProcessDAO.h"

// ��ҳ��ѯ�����б�����
ProcessListDTO::Wrapper ProcessListService::listAll(const ProcessListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ProcessListDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//��ѯ����������
	ProcessDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProRouteDO> result = dao.selectWithPage(query);
	//��DOת����DTO
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

// ͨ��id��ѯ��������
ProcessDTO::Wrapper ProcessListService::getById(const ProcessDetailQuery::Wrapper& query)
{
	// �������ض���
	auto dto = ProcessDTO::createShared();

	ProcessDAO dao;
	list<ProRouteDO> result = dao.selectById(query);

	//��DOת����DTO
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
// ��ӹ��� ��������
uint64_t ProcessListService::saveProcessAdd(const ProcessAddDTO::Wrapper& dto, const string username)
{
	// ��װDO����
	ProRouteDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RouteCode, routeCode, RouteName, routeName, RouteDesc, routeDesc, EnableFlag, enableFlag, Remark, remark)
	// ִ���������
	ProcessDAO dao;
	return dao.insert(data, username);
}
/**
 * �޸Ĺ��յ�service
 */
bool ProcessListService::updateData(const ProcessDTO::Wrapper& dto, const string updatename)
{
	// ��װDO����
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
* ��������
*/
list<ProcessAddDTO::Wrapper> ProcessListService::listAllForProcess(const ProcessListQuery::Wrapper& query)
{
	// �������ض���
	list<ProcessAddDTO::Wrapper> data;

	// ��ѯ����������
	ProcessDAO dao;
	list<ProRouteDO> result = dao.selectWithProcessExport(query);

	// ��DOת����DTO
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
//ɾ������
bool ProcessListService::removeData(uint64_t id)
{
	ProcessDAO dao;
	return dao.deleteById(id) == 1;
}