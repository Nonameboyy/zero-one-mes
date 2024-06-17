#include "stdafx.h"
#include "SetService.h"
#include "../../dao/set/SetDAO.h"
//分页查询所有数据
SetProListPageDTO::Wrapper SetService::listAll(const SetProListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = SetProListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	SetDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProProcessContentDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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
//添加工序
uint64_t SetService::saveData(const SetProAddTableDTO::Wrapper& dto, const string username)
{
	// 组装DO数据
	ProProcessDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,ProcessId,processId,ProcessCode, processCode, ProcessName, processName,
		 EnableFlag, enableFlag, Attention, attention, Remark, remark);
		// 执行数据添加
		SetDAO dao;
	return dao.insertSet(data, username);
}
//添加工序步骤
uint64_t SetService::saveStepData(const SetProListDTO::Wrapper& dto, const string username)
{
	// 组装DO数据
	ProProcessContentDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ContentId, contentId, ProcessId, processId, OrderNum, orderNum,ContentText, contentText,
		Device, device, DocUrl,docUrl,Material, material, Remark, remark);
	// 执行数据添加
	SetDAO dao;
	return dao.insertstepSet(data, username);
}

//修改工序
bool SetService::updateData(const SetProAddTableDTO::Wrapper& dto, const string username)
{
	// 组装DO数据
	ProProcessDO data;
	 	/*data.setProcessId(dto->processId.getValue(0));*/
	 	/*data.setName(dto->name.getValue(""));
	 	data.setSex(dto->sex.getValue(""));
	 	data.setAge(dto->age.getValue(1));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ProcessId, processId, ProcessCode, processCode, ProcessName, processName,
		 EnableFlag, enableFlag,Attention,attention,Remark, remark);
		// 执行数据修改
		SetDAO dao;
	return dao.updateSet(data, username) == 1;
}

ProListPageDTO::Wrapper SetService::listAllForProcess(const ProListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ProListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	SetDAO dao;
	uint64_t count = dao.countForProcess(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProProcessDO> result = dao.selectWithPageForProcess(query);

	// 将DO转换成DTO
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
	// 构建返回对象
	auto dto = ProDetailDTO::createShared();

	// 查询工序详情
	SetDAO dao;
	std::list<ProProcessDO> contentDo = dao.selectByid(query);
	auto item = contentDo.front();

	//// 将DO转换成DTO
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
	// 查询工序详情
	SetDAO dao;
	list<ProProcessDO> result = dao.selectProNameList();


	//将DO转换成DTO
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
	// 构建返回对象
	list<SetProListDTO::Wrapper> data;

	//查询数据
	SetDAO dao;

	list<ProProcessContentDO> result = dao.selectWithStepExport(query);
	//将DO转换成DTO
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
