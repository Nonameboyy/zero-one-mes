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
#ifndef _DVMAINTEMRECORD_DO_	
#define _DVMAINTEMRECORD_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */

class DvMaintenRecordDO
{
	//��¼ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_Id);
	//�ƻ�ID
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_Id);
	//�ƻ�����
	CC_SYNTHESIZE(string, plan_code, Plan_Code);
	//�ƻ�����
	CC_SYNTHESIZE(string, plan_name, Plan_Name);
	//�ƻ�����
	CC_SYNTHESIZE(string, plan_type, Plan_Type);
	//�豸ID
	CC_SYNTHESIZE(uint64_t, machinery_id, Machinery_Id);
	//�豸����
	CC_SYNTHESIZE(string, machinery_code, Machinery_Code);
	//�豸����
	CC_SYNTHESIZE(string, machinery_name, Machinery_Name);
	//Ʒ��
	CC_SYNTHESIZE(string, machinery_brand, Machinery_Brand);
	//����ʱ��
	CC_SYNTHESIZE(string, mainten_time, Mainten_Time);
	//����ͺ�
	CC_SYNTHESIZE(string, machinery_spec, Machinery_Spec);
	//״̬
	CC_SYNTHESIZE(string, status, Status);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//Ԥ���ֶ�3
	CC_SYNTHESIZE(uint64_t, attr3, Attr3);
	//Ԥ���ֶ�4
	CC_SYNTHESIZE(uint64_t, attr4, Attr4);
	//������
	CC_SYNTHESIZE(string, create_by, Create_By);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//������
	CC_SYNTHESIZE(string, update_by, Update_By);
	//����ʱ��
	CC_SYNTHESIZE(string, update_time, Update_Time);

public:
	DvMaintenRecordDO() {
		record_id = 0;
		plan_id = 0;
		plan_code = "";
		plan_name = "";
		plan_type = "";
		machinery_id = 0;
		machinery_code = "";
		machinery_name = "";
		machinery_brand = "";
		machinery_spec = "";
		status = "";
		remark = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		update_by = "";
	}
};



#endif // !_DVMAINTEMRECORD_DO_
