/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/23 20:42:53

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
#ifndef _DVMACHINERYTYPEDO_H_
#define _DVMACHINERYTYPEDO_H_

#include "../DoInclude.h"

/**
 * dv_machinery_type���ݱ�ʵ����
 * �����ˣ�����
 */

class dvMachineryTypeDO
{
	// �豸����ID
	CC_SYNTHESIZE(uint64_t, machinery_type_id, MachineryTypeId)
	// �豸���ͱ���
	CC_SYNTHESIZE(std::string, machinery_type_code, MachineryTypeCode)
	// �豸��������
	CC_SYNTHESIZE(std::string, machinery_type_name, MachineryTypeName)
	// ������ID
	CC_SYNTHESIZE(uint64_t, parent_type_id, ParentTypeId)
	// ���и��ڵ�ID
	CC_SYNTHESIZE(std::string, ancestors, Ancestors)
	// �Ƿ�����
	CC_SYNTHESIZE(char, enable_flag, EnableFlag)
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark)
	// Ԥ���ֶ� 1 ~ 4
	CC_SYNTHESIZE(std::string, attr1, Attr1)
	CC_SYNTHESIZE(std::string, attr2, Attr2)
	CC_SYNTHESIZE(int, attr3, Attr3)
	CC_SYNTHESIZE(int, attr4, Attr4)
	// ������
	CC_SYNTHESIZE(std::string, create_by, CreateBy)
	// ����ʱ��
	CC_SYNTHESIZE(std::string, create_time, CreateTime)
	// ������
	CC_SYNTHESIZE(std::string, update_by, UpdateBy)
	// ����ʱ��
	CC_SYNTHESIZE(std::string, update_time, UpdateTime)
};

#endif // !_DVMACHINERYTYPEDO_H_