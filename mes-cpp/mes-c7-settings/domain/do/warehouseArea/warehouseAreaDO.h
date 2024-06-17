#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _WAREHOUSE_AREA_DO_
#define _WAREHOUSE_AREA_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����,��Ӧ��wm_storage_location������
 */
class warehouseAreaDO
{
	//����ID
	CC_SYNTHESIZE(uint64_t, area_id, AreaId);//��������area_id,����Ϊuint64_t,���Ҷ���getAreaId()����area_id
	//��������
	CC_SYNTHESIZE(string, area_code, AreaCode);
	//��������
	CC_SYNTHESIZE(string, area_name, AreaName);
	//�ֿ�ID
	CC_SYNTHESIZE(uint64_t, warehouse_id, WarehouseId);
	//�������
	CC_SYNTHESIZE(uint32_t, area, Area);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	warehouseAreaDO()
	{
		area_id = 0;
		area_code = "default code";
		area_name = "default name";
		area = 0;
		remark = "";
	}
};

#endif // !_WAREHOUSE_AREA_DO_
