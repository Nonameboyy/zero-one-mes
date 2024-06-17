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
#ifndef _MERGEMENU_DAO_
#define _MERGEMENU_DAO_
#include "BaseDAO.h"
#include "../../domain/do/adress/AreaMenuDO.h"
#include "../../domain/do/adress/LocationMenuDO.h"
#include "../../domain/do/adress/WarehouseMenuDO.h"
#include"MergeMenuMapper.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class MergeMenuDAO : public BaseDAO
{
public:
	//��ѯ���вֿ�
	list<WarehouseMenuDO> selectallwarehouse();
	// ��ѯ�ֿ������п���
	list<LocationMenuDO> selectlocation(const string& warehouse_id);
	// ��ѯ���������п�λ
	list<AreaMenuDO> selectarea(const string& location_id);
};
#endif // !_SAMPLE_DAO_
