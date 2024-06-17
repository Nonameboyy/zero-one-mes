/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "warehouseAreaService.h"
#include "dao/warehouseArea/warehouseAreaDAO.h"
//���ݸ�����query���ز�ѯ��Ӧ�Ľ��,����Ϊ��ҳ�������DTO
warehousePageDTO::Wrapper warehouseAreaService::listAll(const WarehouseAreaQuery::Wrapper& query)
{
	//�������ض���pageDTO
	auto pages = warehousePageDTO::createShared();
	pages->pageIndex = query->pageIndex;//��ȡ��ҳ��ѯ�Ĳ���:�ڼ�ҳ
	pages->pageSize = query->pageSize;//��ȡÿҳ��С

	//��ѯwm_storage_location�������query����������
	warehouseAreaDAO dao;//����DAO��:���ں����ݿ⽻��
	uint64_t count = dao.count(query);//���������ĸ���
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;//��¼����query������
	pages->calcPages();//����pagesize����һ���ж���ҳ
	list<warehouseAreaDO> result = dao.selectWithPage(query);
	//DO->DTO
	for (warehouseAreaDO sub : result)//DOЯ��������Ϊ:uint64_t location_id,string location_code,string location_name,uint64_t warehouse_id
	{//DTO����:UInt64 area_id,String area_code,String area_name,Int32 area,String remark
		auto dto = warehouseAreaListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, area_id, AreaId, area_code, AreaCode, area_name, AreaName, area, Area, remark,Remark)
		pages->addData(dto);

	}
	return pages;
}

uint64_t warehouseAreaService::saveData(const warehouseAreaListDTO::Wrapper& dto)
{
	// ��װDO����
	warehouseAreaDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, AreaId, area_id, AreaCode, area_code, AreaName, area_name, WarehouseId, warehouse_id, Area, area, Remark, remark)
	// ִ���������
	warehouseAreaDAO dao;
	return dao.insert(data);
}

bool warehouseAreaService::updateData(const warehouseAreaListDTO::Wrapper& dto)
{
	// ��װDO����
	warehouseAreaDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, AreaId, area_id, AreaCode, area_code, AreaName, area_name, WarehouseId, warehouse_id, Area, area, Remark, remark)
		// ִ�������޸�
	warehouseAreaDAO dao;
	return dao.update(data) == 1;
}

bool warehouseAreaService::removeData(uint64_t id)
{
	warehouseAreaDAO dao;
	return dao.deleteById(id) == 1;
}