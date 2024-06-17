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
 * 示例数据库实体类
 */

class DvMaintenRecordDO
{
	//记录ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_Id);
	//计划ID
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_Id);
	//计划编码
	CC_SYNTHESIZE(string, plan_code, Plan_Code);
	//计划名称
	CC_SYNTHESIZE(string, plan_name, Plan_Name);
	//计划类型
	CC_SYNTHESIZE(string, plan_type, Plan_Type);
	//设备ID
	CC_SYNTHESIZE(uint64_t, machinery_id, Machinery_Id);
	//设备编码
	CC_SYNTHESIZE(string, machinery_code, Machinery_Code);
	//设备名称
	CC_SYNTHESIZE(string, machinery_name, Machinery_Name);
	//品牌
	CC_SYNTHESIZE(string, machinery_brand, Machinery_Brand);
	//保养时间
	CC_SYNTHESIZE(string, mainten_time, Mainten_Time);
	//规格型号
	CC_SYNTHESIZE(string, machinery_spec, Machinery_Spec);
	//状态
	CC_SYNTHESIZE(string, status, Status);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//预留字段1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//预留字段2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//预留字段3
	CC_SYNTHESIZE(uint64_t, attr3, Attr3);
	//预留字段4
	CC_SYNTHESIZE(uint64_t, attr4, Attr4);
	//创建者
	CC_SYNTHESIZE(string, create_by, Create_By);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//更新者
	CC_SYNTHESIZE(string, update_by, Update_By);
	//更新时间
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
