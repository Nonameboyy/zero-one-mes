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
  * 点检项目 数据库实体类
  */
class DvCheckSubjectDO
{
    // 流水号 (主键)
    CC_SYNTHESIZE(long long, record_id, Record_id);
    // 计划ID
    CC_SYNTHESIZE(long long, plan_id, Plan_id);
    // 设备ID
    CC_SYNTHESIZE(long long, subject_id, Subject_id);
    // 项目编码
    CC_SYNTHESIZE(string, subject_code, Subject_code);
    // 项目名称
    CC_SYNTHESIZE(string, subject_name, Subject_name);
    // 项目类型
    CC_SYNTHESIZE(string, subject_type, Subject_type);
    // 项目内容
    CC_SYNTHESIZE(string, subject_content, Subject_content);
    // 标准
    CC_SYNTHESIZE(string, subject_standard, Subject_standard);
    // 备注
    CC_SYNTHESIZE(string, remark, Remark);
    // 预留字段1
    CC_SYNTHESIZE(string, attr1, Attr1);
    // 预留字段2
    CC_SYNTHESIZE(string, attr2, Attr2);
    // 预留字段3
    CC_SYNTHESIZE(int, attr3, Attr3);
    // 预留字段4
    CC_SYNTHESIZE(int, attr4, Attr4);
    // 创建者
    CC_SYNTHESIZE(string, create_by, Create_by);
    // 创建时间
    CC_SYNTHESIZE(string, create_time, Create_time);
    // 更新者
    CC_SYNTHESIZE(string, update_by, Update_by);
    // 更新时间
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