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
#ifndef _SAMPLEMENUDO_H_
#define _SAMPLEMENUDO_H_

#include "../DoInclude.h"
/**
 * ���Բ˵����ݿ�ʵ��
 */
class dv_mainten_record_lineDO
{
	// Ψһ��� �ƻ�ID
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	// �ƻ�ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// ��ĿID
	CC_SYNTHESIZE(uint64_t, subject_id, Subject_id);
	// ��Ŀ����
	CC_SYNTHESIZE(string, subject_code, Subject_code);
	// ��Ŀ����
	CC_SYNTHESIZE(string, subject_name, Subject_name);
	// ��Ŀ����
	CC_SYNTHESIZE(string, subject_type, Subject_type);
	// ��Ŀ����
	CC_SYNTHESIZE(string, subject_content, Subject_content);
	// ��׼
	CC_SYNTHESIZE(string, subject_standard, Subject_standard);
	// �������
	CC_SYNTHESIZE(string, mainten_status, Mainten_status);
	// �쳣����
	CC_SYNTHESIZE(string, mainten_result, Mainten_result);
	// Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// Ԥ���ֶ�3
	CC_SYNTHESIZE(int, attr3, Attr3);
	// Ԥ���ֶ�4
	CC_SYNTHESIZE(int, attr4, Attr4);
	// ������
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ������
	CC_SYNTHESIZE(string, update_by, Update_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
public:
	dv_mainten_record_lineDO() {}
	dv_mainten_record_lineDO(uint64_t line_id, uint64_t record_id, uint64_t subject_id, string subject_code, string subject_name, string subject_type, string subject_content, string subject_standard, string mainten_status, string mainten_result, string attr1, string attr2, int attr3, int attr4, string create_by, string create_time, string update_by, string update_time)
	{
		this->line_id = line_id;
		this->record_id = record_id;
		this->subject_id = subject_id;
		this->subject_code = subject_code;
		this->subject_name = subject_name;
		this->subject_type = subject_type;
		this->subject_content = subject_content;
		this->subject_standard = subject_standard;
		this->mainten_status = mainten_status;
		this->mainten_result = mainten_result;
		this->attr1 = attr1;
		this->attr2 = attr2;
		this->attr3 = attr3;
		this->attr4 = attr4;
		this->create_by = create_by;
		this->create_time = create_time;
		this->update_by = update_by;
		this->update_time = update_time;
	}
};

#endif // !_SAMPLEMENUDO_H_