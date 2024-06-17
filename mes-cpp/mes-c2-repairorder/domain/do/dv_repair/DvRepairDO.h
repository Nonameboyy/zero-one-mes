#pragma once
/*
 * Copyright Zero One Star. All rights reserved.
 *
 * @Author: Heng_Xin
 * @Date: 2024/5/24 09:24:13
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
#ifndef _DV_REPAIR_DO_
#define _DV_REPAIR_DO_

#include "../DoInclude.h"

/**
 * �豸ά�޵� ���ݿ�ʵ����
 */
class DvRepairDO
{
    // ά�޵�ID (����)
    CC_SYNTHESIZE(uint64_t, repair_id, Repair_id);
    // ά�޵����
    CC_SYNTHESIZE(string, repair_code, Repair_code);
    // ά�޵�����
    CC_SYNTHESIZE(string, repair_name, Repair_name);
    // �豸ID
    CC_SYNTHESIZE(uint64_t, machinery_id, Machinery_id);
    // �豸����
    CC_SYNTHESIZE(string, machinery_code, Machinery_code);
    // �豸����
    CC_SYNTHESIZE(string, machinery_name, Machinery_name);
    // Ʒ��
    CC_SYNTHESIZE(string, machinery_brand, Machinery_brand);
    // ����ͺ�
    CC_SYNTHESIZE(string, machinery_spec, Machinery_spec);
    // �豸����ID
    CC_SYNTHESIZE(uint64_t, machinery_type_id, Machinery_type_id);
    // ��������
    CC_SYNTHESIZE(string, require_date, Require_date);
    // ά���������
    CC_SYNTHESIZE(string, finish_date, Finish_date);
    // ��������
    CC_SYNTHESIZE(string, confirm_date, Confirm_date);
    // ά�޽��
    CC_SYNTHESIZE(string, repair_result, Repair_result);
    // ά����Ա
    CC_SYNTHESIZE(string, accepted_by, Accepted_by);
    // ������Ա
    CC_SYNTHESIZE(string, confirm_by, Confirm_by);
    // ����״̬
    CC_SYNTHESIZE(string, status, Status);
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
    DvRepairDO() {
        repair_id = 0;
        repair_code = "";
        repair_name = "";
        machinery_id = 0;
        machinery_code = "";
        machinery_name = "";
        machinery_brand = "";
        machinery_spec = "";
        machinery_type_id = 0;
        require_date = "";
        finish_date = "";
        confirm_date = "";
        repair_result = "";
        accepted_by = "";
        confirm_by = "";
        status = "";
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

#endif // !_DV_REPAIR_DO_
