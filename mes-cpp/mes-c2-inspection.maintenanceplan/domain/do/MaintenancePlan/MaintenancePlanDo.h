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
#ifndef _MAINTENANCEPLAN_DO_
#define _MAINTENANCEPLAN_DO_
#include "../DoInclude.h"
#include "../../GlobalInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class MaintenancePlanDo
{
	//�ƻ�ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �ƻ����
	CC_SYNTHESIZE(string, code, Code);
	// �ƻ�����
	CC_SYNTHESIZE(string, name, Name);
	// �ƻ�����
	CC_SYNTHESIZE(string, type, Type);
	// Ƶ������
	CC_SYNTHESIZE(string, cycletype, Cycletype);
	// Ƶ�ʴ���
	CC_SYNTHESIZE(int32_t, cyclecount, Cyclecount);
	// �ƻ���ʼʱ��
	CC_SYNTHESIZE(string, startdate, Startdate);
	// �ƻ�����ʱ��
	CC_SYNTHESIZE(string, enddate, Enddate);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ������
	CC_SYNTHESIZE(string, updateby, Updateby);
	// ����ʱ��
	CC_SYNTHESIZE(string, updatetime, Updatetime);
public:
	MaintenancePlanDo() {
		id = 0;
		code = "";
		name = "";
		type = "";
		cycletype = "";
		cyclecount = 0;
		startdate = "";
		enddate = "";
		//status = "";
		remark = "";
		updateby = "";
		updatetime = "";
	}
};

#endif // !_SAMPLE_DO_
