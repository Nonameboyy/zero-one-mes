#include "stdafx.h"
#include "PickService.h"
#include "../../dao/pick/PickDAO.h"

//PickPageDTO::Wrapper PickService::listAll(const PickQuery::Wrapper& query)
//{
//	// 构建返回对象
//	auto pages = PickDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// 查询数据总条数
//	PickDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return pages;
//	}
//
//	// 分页查询数据
//	pages->total = count;
//	pages->calcPages();
//	list<PickDO> result = dao.selectWithPage(query);
//	// 将DO转换成DTO
//	for (PickDO sub : result)
//	{
//		auto dto = PickDTO::createShared();
//		// 		dto->id = sub.getId();
//		// 		dto->name = sub.getName();
//		// 		dto->sex = sub.getSex();
//		// 		dto->age = sub.getAge();
//		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
//			pages->addData(dto);
//
//	}
//	return pages;
//}

uint64_t PickService::saveData(const PickDTO::Wrapper& dto)
{
	// 组装DO数据
	PickDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Icode, issueCode, Iname, issueName, Wcode, workorderCode)
		// 执行数据添加
		PickDAO dao;
	return dao.insert(data);
}

bool PickService::updateData(const PickDTO::Wrapper& dto)
{
	// 组装DO数据
	PickDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Icode, issueCode, Iname, issueName, Wcode, workorderCode,Id,issueId)
		// 执行数据添加
		PickDAO dao;
	return dao.update(data) == 1;
}


