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
 * 设备维修单 数据库实体类
 */
class DvRepairDO
{
    // 维修单ID (主键)
    CC_SYNTHESIZE(uint64_t, repair_id, Repair_id);
    // 维修单编号
    CC_SYNTHESIZE(string, repair_code, Repair_code);
    // 维修单名称
    CC_SYNTHESIZE(string, repair_name, Repair_name);
    // 设备ID
    CC_SYNTHESIZE(uint64_t, machinery_id, Machinery_id);
    // 设备编码
    CC_SYNTHESIZE(string, machinery_code, Machinery_code);
    // 设备名称
    CC_SYNTHESIZE(string, machinery_name, Machinery_name);
    // 品牌
    CC_SYNTHESIZE(string, machinery_brand, Machinery_brand);
    // 规格型号
    CC_SYNTHESIZE(string, machinery_spec, Machinery_spec);
    // 设备类型ID
    CC_SYNTHESIZE(uint64_t, machinery_type_id, Machinery_type_id);
    // 报修日期
    CC_SYNTHESIZE(string, require_date, Require_date);
    // 维修完成日期
    CC_SYNTHESIZE(string, finish_date, Finish_date);
    // 验收日期
    CC_SYNTHESIZE(string, confirm_date, Confirm_date);
    // 维修结果
    CC_SYNTHESIZE(string, repair_result, Repair_result);
    // 维修人员
    CC_SYNTHESIZE(string, accepted_by, Accepted_by);
    // 验收人员
    CC_SYNTHESIZE(string, confirm_by, Confirm_by);
    // 单据状态
    CC_SYNTHESIZE(string, status, Status);
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
