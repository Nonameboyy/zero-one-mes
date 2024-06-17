#include "stdafx.h"
#include "ProcessExportService.h"
#include "../../dao/set/SetExportDAO.h"
// 导出工序 查询数据
list<SetProAddTableDTO::Wrapper> ProcessExportService::listAll(const ProcessExportQuery::Wrapper& query)
{
	// 构建返回对象
	list<SetProAddTableDTO::Wrapper> data;

	//查询数据
	SetExportDAO dao;

	list<ProProcessDO> result = dao.selectWithProcessExport(query);
	//将DO转换成DTO
	for (ProProcessDO sub : result)
	{
		auto dto = SetProAddTableDTO::createShared();
		dto->processCode= sub.getProcessCode();
		dto->processName = sub.getProcessName();
		dto->attention = sub.getAttention();
		dto->enableFlag = sub.getEnableFlag();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, routeid, RouteId, routecode, RouteCode, routedesc, RouteDesc, enableflag, EnableFlag, remark, Remark)
		data.emplace_back(dto);
	}
	return data;
}


