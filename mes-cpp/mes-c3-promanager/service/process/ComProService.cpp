#include "stdafx.h"
#include "ComProService.h"
#include "../../mes-c3-promanager/dao/process/ProcessDAO.h"
#include "../../dao/process/ComProDAO.h"

//查询
ComProPageDTO::Wrapper ComProService::listAll(const ProQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ComProPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ComProDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProRouteProcessDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ProRouteProcessDO sub : result)
	{
		auto dto = ComProListDTO::createShared();
		//dto->xxxx=sub.xxxx;
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, process_id, ProcessId, process_code, ProcessCode, process_name, ProcessName,
			key_flag, KeyFlag, next_process_name, NextProcessName, link_type, LinkType, is_check, IsCheck, default_pre_time, DefaultPreTime,
			default_suf_time, DefaultSufTime, color_code, ColorCode)
			pages->addData(dto);
	}
	return pages;
}
//新增
uint64_t ComProService::saveData(const NewProcessDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	ProRouteProcessDO data;
	// 	data.xxxxx(dto->name.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RouteId, route_id, ProcessId, process_id, NextProcessId, nextprocess_id, ProcessCode, process_code, ProcessName, process_name,
		KeyFlag, key_flag, NextProcessName, next_process_name, LinkType, link_type, IsCheck, is_check, DefaultPreTime, default_pre_time,
		DefaultSufTime, default_suf_time, ColorCode, color_code, Remark, Remark)
		// 执行数据添加
		ComProDAO dao;
	return dao.insert(data, payload);
}
//修改
bool ComProService::updateData(const ModifyProDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	ProRouteProcessDO data;
	// 	data.xxx(dto->id.getValue(0));
	data.setProcessCode(dto->process_code.getValue({}));
	data.setProcessName(dto->process_name.getValue({}));
	data.setKeyFlag(dto->key_flag.getValue({}));
	data.setNextProcessName(dto->next_process_name.getValue({}));
	data.setLinkType(dto->link_type.getValue({}));
	data.setIsCheck(dto->is_check.getValue({}));
	data.setDefaultPreTime(dto->default_pre_time.getValue({}));
	data.setDefaultSufTime(dto->default_suf_time.getValue({}));
	data.setColorCode(dto->color_code.getValue({}));
	data.setRemark(dto->Remark.getValue({}));
	data.setRecordId(dto->record_id.getValue({}));
	// 执行数据修改
	ComProDAO dao;
	return dao.update(data, payload) == 1;
}


/**
 * 删除组成工序的service
 */
bool ComProService::removeData(list<uint64_t> id)
{
	ProcessDAO dao;
	if (dao.deleteById(id)) {
		return true;
	}
	else {
		return false;
	}
}