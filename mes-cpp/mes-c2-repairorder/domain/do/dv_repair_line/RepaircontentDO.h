#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/24 10:08:32

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
#ifndef _REPAIRCONTENT_DO_
#define _REPAIRCONTENT_DO_
#include "../DoInclude.h"
#include "../../../../mes-c2-equipmentledger/domain/do/dv_subject/dvSubjectDO.h"
/**
 * dv_repaircontent_line数据库实体类
 */
class dv_repair_lineDO
{
	// 行id
	CC_SYNTHESIZE(uint64_t, line_id, line_Id);
	// 维修单id
	CC_SYNTHESIZE(uint64_t, repair_id, repair_Id);
	// 项目id
	CC_SYNTHESIZE(uint64_t, subject_id, subject_Id);
	// 项目编码
	CC_SYNTHESIZE(string, subject_code, subject_Code);
	//项目名称 
	CC_SYNTHESIZE(string, subject_name, subject_Name);
	//项目类型
	CC_SYNTHESIZE(string, subject_type, subject_Type);
	//项目内容
	CC_SYNTHESIZE(string, subject_content, subject_Content);
	//故障描述
	CC_SYNTHESIZE(string, malfunction, Malfunction);
	//故障描述资源
	CC_SYNTHESIZE(string, malfunction_url, Malfunction_url);
	//维修情况
	CC_SYNTHESIZE(string, repair_des, repair_Des);
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
	CC_SYNTHESIZE(string, create_by, Create_by);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//更新者
	CC_SYNTHESIZE(string, update_by, Update_by);
	//更新时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	
public:
	dv_repair_lineDO() {
		line_id = 0;
		repair_id = 1;
		subject_id = 1;
		subject_code = "";
		subject_name = "";
		subject_type = "";
		subject_content = "";
		malfunction = "";
		malfunction_url = "";
		repair_des = "";
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

#endif // !_REPAIRCONTENT_DO_
