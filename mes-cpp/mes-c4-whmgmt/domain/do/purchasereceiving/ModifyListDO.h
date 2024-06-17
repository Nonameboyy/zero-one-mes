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
#ifndef _MODIFYLIST_DO_
#define _MODIFYLIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ModifyListDO
{
	// ��ⵥid 
	CC_SYNTHESIZE(uint64_t, recptid, Recptid);
	// ��ⵥ���
	CC_SYNTHESIZE(string, recptcode, Recptcode);
	// ��ⵥ����
	CC_SYNTHESIZE(string, recptname, Recptname);
	// �������
	CC_SYNTHESIZE(string, recptdate, Recptdate);
	// �ɹ�������
	CC_SYNTHESIZE(string, pocode, Pocode);
	//����״̬
	CC_SYNTHESIZE(string, status, Status);
	//��Ӧ��id
	CC_SYNTHESIZE(int16_t, vendorid, Vendorid);
	//���ֿ�
	CC_SYNTHESIZE(string, warehousename, Warehousename);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);

public:
	ModifyListDO() {
		recptid = -1;
		recptcode = "";
		recptname = "";
		recptdate = "";
		pocode = "";
		status = "PREPARE";
		vendorid = -1;
		warehousename = "";
		remark = "";
	}
};

#endif // !_SAMPLE_DO_
