#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/17 16:25:30

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
#ifndef _LOCATIONMENUDO_H_
#define _LOCATIONMENUDO_H_

#include "../DoInclude.h"
/**
 * ���Բ˵����ݿ�ʵ��
 */
class LocationMenuDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, location_id, Location_id);
	// ��������
	CC_SYNTHESIZE(string, location_code, Location_code);
	//��������
	CC_SYNTHESIZE(string, location_name, Location_name);
	// ���ڲֿ�id
	CC_SYNTHESIZE(string, warehouse_id, Warehouse_id);
	//// ���
	//CC_SYNTHESIZE(double_t,area, Area);
	//// ���������
	//CC_SYNTHESIZE(double_t, max_loa, Max_loa);

public:
	LocationMenuDO() {}
	LocationMenuDO(string location_id, string location_code, string location_name, string warehouse_id)
	{
		this->location_id =location_id;
		this->location_code = location_code;
		this->location_name = location_name;
		this->warehouse_id = warehouse_id;
	}
};

#endif // !_SAMPLEMENUDO_H_