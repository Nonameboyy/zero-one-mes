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
#ifndef _DEVICE_RESOURCE_DAO_
#define _DEVICE_RESOURCE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/deviceresource/DeviceResourceDO.h"
#include "../../domain/query/deviceresource/DeviceResourceQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DeviceResourceDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const DeviceResourceQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<DeviceResourceDO> selectWithPage(const DeviceResourceQuery::Wrapper& query);
	// ��������
	uint64_t insert(const DeviceResourceDO& iObj);
	// �޸�����
	int update(const DeviceResourceDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t deviceResourceId);
};
#endif // !_DEVICE_RESOURCE_DAO_
