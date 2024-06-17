#include "stdafx.h"
#include "SetService.h"
#include "../../dao/set/SetDAO.h"
//��ҳ��ѯ��������
SetProListPageDTO::Wrapper SetService::listAll(const SetProListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SetProListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	SetDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProProcessContentDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ProProcessContentDO sub : result)
	{
		auto dto = SetProListDTO::createShared();
				dto->processId = sub.getProcessId();
				dto->orderNum = sub.getOrderNum();
	 			dto->device = sub.getDevice();
				dto->contentText = sub.getContentText();
				dto->material = sub.getMaterial();
				dto->remark = sub.getRemark();
				dto->docUrl = sub.getDocUrl();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, contentId, ContentId, processId,ProcessId, orderNum,OrderNum, device, Device,
			 //contentText, ContentText,docUrl, DocUrl, material, Material, remark,Remark)
			pages->addData(dto);
	}
	return pages;
}
//��ӹ���
uint64_t SetService::saveData(const SetProAddTableDTO::Wrapper& dto, const string username)
{
	// ��װDO����
	ProProcessDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,ProcessId,processId,ProcessCode, processCode, ProcessName, processName,
		 EnableFlag, enableFlag, Attention, attention, Remark, remark);
		// ִ���������
		SetDAO dao;
	return dao.insertSet(data, username);
}
//��ӹ�����
uint64_t SetService::saveStepData(const SetProListDTO::Wrapper& dto, const string username)
{
	// ��װDO����
	ProProcessContentDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ContentId, contentId, ProcessId, processId, OrderNum, orderNum,ContentText, contentText,
		Device, device, DocUrl,docUrl,Material, material, Remark, remark);
	// ִ���������
	SetDAO dao;
	return dao.insertstepSet(data, username);
}

//�޸Ĺ���
bool SetService::updateData(const SetProAddTableDTO::Wrapper& dto, const string username)
{
	// ��װDO����
	ProProcessDO data;
	 	/*data.setProcessId(dto->processId.getValue(0));*/
	 	/*data.setName(dto->name.getValue(""));
	 	data.setSex(dto->sex.getValue(""));
	 	data.setAge(dto->age.getValue(1));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ProcessId, processId, ProcessCode, processCode, ProcessName, processName,
		 EnableFlag, enableFlag,Attention,attention,Remark, remark);
		// ִ�������޸�
		SetDAO dao;
	return dao.updateSet(data, username) == 1;
}

ProListPageDTO::Wrapper SetService::listAllForProcess(const ProListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ProListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	SetDAO dao;
	uint64_t count = dao.countForProcess(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProProcessDO> result = dao.selectWithPageForProcess(query);

	// ��DOת����DTO
	for (ProProcessDO sub : result)
	{
		auto dto = ProListDTO::createShared();
		dto->processId = sub.getProcessId();
		dto->processCode = sub.getProcessCode();
		dto->processName = sub.getProcessName();
		dto->enableFlag = sub.getEnableFlag();
		dto->remark = sub.getRemark();

		/*ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			processId, ProcessId,
			processCode, ProcessCode,
			processName, ProcessName,
			enableFlag, EnableFlag,
			remark, Remark);*/
		pages->addData(dto);
	}
	return pages;
}

ProDetailDTO::Wrapper SetService::getProcessDetail(const ProDetailQuery::Wrapper& query)
{
	// �������ض���
	auto dto = ProDetailDTO::createShared();

	// ��ѯ��������
	SetDAO dao;
	std::list<ProProcessDO> contentDo = dao.selectByid(query);
	auto item = contentDo.front();

	//// ��DOת����DTO
	//for (auto item : contentDo) {
	dto->processId = item.getProcessId();
	dto->processCode = item.getProcessCode();
	dto->processName = item.getProcessName();
	dto->attention = item.getAttention();
	dto->enableFlag = item.getEnableFlag();
	dto->remark = item.getRemark();
	//}
	/*ZO_STAR_DOMAIN_DO_TO_DTO(dto, item,
		processId, ProcessId,
		processCode, ProcessCode,
		processName, ProcessName,
		attention, Attention,
		enableFlag, EnableFlag,
		remark, Remark)*/

	return dto;
}

ListDTO::Wrapper SetService::getProcessNameList()
{
	auto data = ListDTO::createShared();
	// ��ѯ��������
	SetDAO dao;
	list<ProProcessDO> result = dao.selectProNameList();


	//��DOת����DTO
	for (ProProcessDO sub : result)
	{
		auto dto = ProNameListDTO::createShared();
		dto->processId = sub.getProcessId();
		dto->proCode = sub.getProcessCode();
		dto->proName = sub.getProcessName();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, routeid, RouteId, routecode, RouteCode, routedesc, RouteDesc, enableflag, EnableFlag, remark, Remark)
		data->addData(dto);
	}
	return data;
}

list<SetProListDTO::Wrapper> SetService::listAllForExport(const SetProListQuery::Wrapper& query)
{
	// �������ض���
	list<SetProListDTO::Wrapper> data;

	//��ѯ����
	SetDAO dao;

	list<ProProcessContentDO> result = dao.selectWithStepExport(query);
	//��DOת����DTO
	for (ProProcessContentDO sub : result)
	{
		auto dto = SetProListDTO::createShared();
		dto->processId = sub.getProcessId();
		dto->orderNum = sub.getOrderNum();
		dto->contentText = sub.getContentText();
		dto->device = sub.getDevice();
		dto->material = sub.getMaterial();
		dto->docUrl = sub.getDocUrl();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, routeid, RouteId, routecode, RouteCode, routedesc, RouteDesc, enableflag, EnableFlag, remark, Remark)
		data.emplace_back(dto);
	}
	return data;
}
