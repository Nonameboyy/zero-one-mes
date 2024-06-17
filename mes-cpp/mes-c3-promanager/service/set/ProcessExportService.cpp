#include "stdafx.h"
#include "ProcessExportService.h"
#include "../../dao/set/SetExportDAO.h"
// �������� ��ѯ����
list<SetProAddTableDTO::Wrapper> ProcessExportService::listAll(const ProcessExportQuery::Wrapper& query)
{
	// �������ض���
	list<SetProAddTableDTO::Wrapper> data;

	//��ѯ����
	SetExportDAO dao;

	list<ProProcessDO> result = dao.selectWithProcessExport(query);
	//��DOת����DTO
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


