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
#ifndef _MODIFY_PLAN_STATUS_DO_
#define _MODIFY_PLAN_STATUS_DO_
#include "../DoInclude.h"
#include "../../GlobalInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ModifyPlanStatusDo
{
	// �ƻ�ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �ƻ�״̬���ݸ������ɣ������޸ģ�
	CC_SYNTHESIZE(string, status, Status);
	// ������
	CC_SYNTHESIZE(string, updateby, Updateby);
	// ����ʱ��
	CC_SYNTHESIZE(string, updatetime, Updatetime)
public:
	ModifyPlanStatusDo() {
		id = 0;
		status = "";
		updateby = "";
		updatetime = "";
	}
};

#endif // !_SAMPLE_DO_
