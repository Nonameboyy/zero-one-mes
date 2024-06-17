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
#ifndef _RETURN_DO_R_
#define _RETURN_DO_R_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ReturnDO_r
{
	//�˻���ID
	CC_SYNTHESIZE(uint64_t, rt_id, Rt_id);
	// �˻������
	CC_SYNTHESIZE(string, rt_code, Rt_code);
	// �˻�������
	CC_SYNTHESIZE(string, rt_name, Rt_name);
	// �ɹ��������
	CC_SYNTHESIZE(string, po_code, Po_code);
	// ��Ӧ��ID
	CC_SYNTHESIZE(uint64_t, vendor_id, Vendor_id);
	// ��Ӧ�̱���
	CC_SYNTHESIZE(string, vendor_code, Vendor_code);
	// ��Ӧ������
	CC_SYNTHESIZE(string, vendor_name, Vendor_name);
	// ��Ӧ�̼��
	CC_SYNTHESIZE(string, vendor_nick, Vendor_nick);
	// ���κ�
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	// �˻�����
	CC_SYNTHESIZE(string, rt_date, Rt_date);
	// ����״̬
	CC_SYNTHESIZE(string, status, Status_);//Status �ѱ�����
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//	Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//	Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//	Ԥ���ֶ�3
	CC_SYNTHESIZE(int32_t, attr3, Attr3);
	//	Ԥ���ֶ�4
	CC_SYNTHESIZE(int32_t, attr4, Attr4);
	//	������
	CC_SYNTHESIZE(string, create_by, Create_by);
	//	����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//	������
	CC_SYNTHESIZE(string, update_by, Update_by);
	//	����ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);

public:
	ReturnDO_r() {
		rt_id = 1;
		rt_code = "111";
		rt_name = "rt_name";
		po_code = "222";
		vendor_id = 2;
		vendor_code = "333";
		vendor_name = "vendor_name";
		vendor_nick = "vendor_nick";
		batch_code = "444";
		rt_date = "2024-05-21 09:49:51";
		status = "status";
		remark = "remark";
		attr1 = "attr1";
		attr2 = "attr2";
		attr3 = 3;
		attr4 = 4;
		create_by = "create_by";
		create_time = "2024-05-21 09:49:51";
		update_by = "update_by";
		update_time = "2024-05-21 09:49:51";
	}
};

#endif // !_RETURN_DO_
