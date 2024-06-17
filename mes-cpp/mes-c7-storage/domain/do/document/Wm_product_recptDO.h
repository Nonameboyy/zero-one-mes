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
#ifndef _WM_PRODUCT_RECPTDO_H_
#define  _WM_PRODUCT_RECPTDO_H_

#include "../DoInclude.h"
/**
 * ���Բ˵����ݿ�ʵ��
 */
class Wm_product_recptDO
{
	// ��ⵥID
	CC_SYNTHESIZE(int64_t, recpt_id, Recpt_id);
	//��ⵥ���
	CC_SYNTHESIZE(string, recpt_code, Recpt_code);
	//��ⵥ����
	CC_SYNTHESIZE(string, recpt_name, Recpt_name);
	// ��������id
	CC_SYNTHESIZE(int64_t, workorder_id, Workorder_id);
	// ������������
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	// ������������
	CC_SYNTHESIZE(string, workorder_name, Workorder_name);
	// ��Ʒ����id
	CC_SYNTHESIZE(int64_t, item_id, Item_id);
	//// ��Ʒ���ϱ���
	//CC_SYNTHESIZE(string, item_code, Item_code);
	////��Ʒ��������
	//CC_SYNTHESIZE(string, item_name, Item_name);
	////����ͺ�
	//CC_SYNTHESIZE(string, specification, Specification);
	////��λ
	//CC_SYNTHESIZE(string, uint_of_measure, Unit_of_measure);
	//�������
	CC_SYNTHESIZE(string, recpt_date, Recpt_date);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	Wm_product_recptDO() {}
	Wm_product_recptDO(int64_t recpt_id, string recpt_code, string recpt_name, int64_t workorder_id, string workorder_code, string workorder_name, string recpt_date, string remark,int64_t item_id)
	{
		this->recpt_id = recpt_id;
		this->recpt_code = recpt_code;
		this->recpt_name = recpt_name;
		this->workorder_id = workorder_id;
		this->workorder_code = workorder_code;
		this->workorder_name = workorder_name;
		this->recpt_date = recpt_date;
		this->remark = remark;
		this->item_id = item_id;
	}
};

#endif // !_SAMPLEMENUDO_H_