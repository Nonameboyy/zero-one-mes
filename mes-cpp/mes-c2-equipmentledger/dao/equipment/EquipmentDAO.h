#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _EQUIPMENT_DAO_
#define _EQUIPMENT_DAO_
#include "BaseDAO.h"
#include"../../domain/do/dv_machinery/dvMachineryDO.h"
#include"../../domain/query/equipment/EquipmentQuery.h"
#include"../../domain/do/dv_machinery_type/dvMachineryTypeDO.h"
#include"../../domain/do/md_workshop/md_workshopDO.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class EquipmentDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const EquipmentQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<dvMachineryDO> selectWithPage(const EquipmentQuery::Wrapper& query);
	// ͨ���豸ID��ѯ����
	list<dvMachineryDO> selectWithId(const EquipmentDetailQuery::Wrapper& query);
	// ��������
	uint64_t insert( dvMachineryDO& iObj);
	//ͨ���豸�������ƻ���豸����ID
	list<dvMachineryTypeDO> getMachinerytypeidByname(std::string name);
	//ͨ���������ƻ�ó���ID
	list<MdWorkshopDO> getWorkshopidByname(std::string name);
	// �޸�����
	int modify( dvMachineryDO iObj);
	//���ݳ���ID��ȡ����
	list<MdWorkshopDO> getWorkshopByid(std::int64_t id);
	//�����豸����ID��ȡ����
	list<dvMachineryTypeDO> getMachinerytypeByid(std::int64_t id);
	//�����豸ID��ȡ����
	list<dvMachineryDO> getMachineryByid(std::int64_t id);
	
};
#endif // 

