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
#ifndef _AREAMENUDO_H_
#define _AREAMENUDO_H_

#include "../DoInclude.h"
/**
 * ���Բ˵����ݿ�ʵ��
 */
class AreaMenuDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, area_id, Area_id);
	// ��λ����
	CC_SYNTHESIZE(string,area_code,Area_code);
	//��λ����
	CC_SYNTHESIZE(string, area_name, Area_name);
	// ���ڿ���id
	CC_SYNTHESIZE(string,location_id,Location_id);
	//// ���
	//CC_SYNTHESIZE(double_t,area, Area);
	//// ���������
	//CC_SYNTHESIZE(double_t, max_loa, Max_loa);

public:
	AreaMenuDO() {}
	AreaMenuDO(string area_id, string area_code, string area_name, string location_id)
	{
		this->area_id = area_id;
		this->area_code =area_code;
		this->area_name = area_name;
		this->location_id = location_id;
	}
};

#endif // !_SAMPLEMENUDO_H_