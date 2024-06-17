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
#ifndef _PRODUCT_RECPT_DO_
#define _PRODUCT_RECPT_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����,��Ӧ��wm_storage_location������
 */
class ProductRecptDO
{
	//��ⵥ���,����
	CC_SYNTHESIZE(string, recpt_code, RecptCode);//��������recpt_code,����Ϊstring,���Ҷ���getRecptCode()����recpt_code
	// ��ⵥ����
	CC_SYNTHESIZE(string, recpt_name, RecptName);
	//������������
	CC_SYNTHESIZE(string, workorder_code, WorkorderCode);
	//������������
	CC_SYNTHESIZE(string, workorder_name, WorkorderName);
	//�������
	CC_SYNTHESIZE(string, recpt_date, RecptDate);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//��Ʒ����ID
	CC_SYNTHESIZE(uint64_t, item_id, ItemId);
public:
	ProductRecptDO()
	{
		recpt_code = "recpt_code";
		recpt_name = "recpt_name";
		workorder_code = "workorder_code";
		workorder_name = "workorder_name";
		recpt_date = "recpt_date";
		remark = "remark";
		item_id = 1;
	}
};

#endif // !_PRODUCT_RECPT_DO_
