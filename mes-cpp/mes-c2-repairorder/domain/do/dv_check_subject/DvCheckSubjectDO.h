#pragma once
/*
 * Copyright Zero One Star. All rights reserved.
 *
 * @Author: Heng_Xin
 * @Date: 2024/5/24 09:49:51
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *	  https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * */
#ifndef _DV_CHECK_SUBJECT_
#define _DV_CHECK_SUBJECT_

#include "../DoInclude.h"
#include "../DoInclude.h"

 /**
  * �����Ŀ ���ݿ�ʵ����
  */
class DvCheckSubjectDO
{
    // ��ˮ�� (����)
    CC_SYNTHESIZE(long long, record_id, Record_id);
    // �ƻ�ID
    CC_SYNTHESIZE(long long, plan_id, Plan_id);
    // �豸ID
    CC_SYNTHESIZE(long long, subject_id, Subject_id);
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
    // ��ע
    CC_SYNTHESIZE(string, remark, Remark);
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
    DvCheckSubjectDO() {
        record_id = 0;
        plan_id = 0;
        subject_id = 0;
        subject_code = "";
        subject_name = "";
        subject_type = "";
        subject_content = "";
        subject_standard = "";
        remark = "";
        attr1 = "";
        attr2 = "";
        attr3 = 0;
        attr4 = 0;
        create_by = "";
        create_time = "";
        update_by = "";
        update_time = "";
    }
};

#endif // !_DV_CHECK_SUBJECT_