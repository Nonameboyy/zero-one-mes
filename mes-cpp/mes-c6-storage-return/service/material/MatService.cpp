#include "stdafx.h"
#include "MatService.h"
#include "../../dao/material/MatDAO.h"

GetReturnListPageDTO::Wrapper MatService::listAll(const GetReturnListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetReturnListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	MatDAO dao;
	uint64_t count = dao.count1(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<MatlistDO> result = dao.selectWithPage1(query);
	// ��DOת����DTO
	for (MatlistDO sub : result)
	{
		auto dto = GetReturnListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rtcode, Rtcode, rtname, Rtname, pocode, Pocode, vendorcode, Vendorcode, vendorname, Vendorname, rtdate, Rtdate, statuss, Statuss)
		pages->addData(dto);

	}
	return pages;
}

uint64_t MatService::saveData(const AddReturnDTO::Wrapper& dto1)
{
	// ��װlistDO����
	MatlistDO data1;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data1, dto1, Rtid, rtid, Rtcode, rtcode, Rtname, rtname, Pocode, pocode, Vendorname, vendorname, Batchcode, batchcode, Rtdate, rtdate, Statuss, statuss, Remark, remark)

	// ִ���������
	MatDAO dao;
	return dao.insert1(data1);
}

bool MatService::updateData(const AddReturnDTO::Wrapper& dto)
{
	// ��װlistDO����
	MatlistDO data1;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data1, dto, Rtid, rtid, Rtcode, rtcode, Rtname, rtname, Pocode, pocode, Vendorname, vendorname, Batchcode, batchcode, Rtdate, rtdate, Statuss, statuss, Remark, remark)

	// ִ���������
	MatDAO dao;
	return dao.update1(data1)==1;
}

bool MatService::removeData(uint64_t id)
{
	MatDAO dao;
	return dao.deleteById1(id) == 1;
}
