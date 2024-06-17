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
#ifndef _DV_CHECK_RECORC_LINE_DO_
#define _DV_CHECK_RECORC_LINE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class DvCheckRecordLineDo
{
	//line_id
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	//record_id
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	//项目ID
	CC_SYNTHESIZE(uint64_t, subject_id, Subject_id);
	//项目编码
	CC_SYNTHESIZE(string, subject_code, Subject_code);
	//项目名称
	CC_SYNTHESIZE(string, subject_name, Subject_name);
	//项目类型
	CC_SYNTHESIZE(string, subject_type, Subject_type);
	//项目内容
	CC_SYNTHESIZE(string, subject_content, Subject_content);
	//项目标准
	CC_SYNTHESIZE(string, subject_standard, Subject_standard);
	//点检状态
	CC_SYNTHESIZE(string, check_status, Check_status);
	//点检结果
	CC_SYNTHESIZE(string, check_result, Check_result);
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
	DvCheckRecordLineDo() {
		line_id = 0;
		record_id = 0;
		subject_id = 0;
		subject_code = "";
		subject_name = "";
		subject_type = "";
		subject_content = "";
		subject_standard = "";
		check_status = "";
		check_result = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		create_time = "";
		update_by = "";
		update_timr = "";

	}
};

#endif // !_DV_CHECK_RECORC_LINE_DO_
