#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:51:41

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
#ifndef _PRO_PROCESS_DO_
#define _PRO_PROCESS_DO_

#include "../DoInclude.h"
#include <string>
#include <list>
using namespace std;
class ProProcessDO
{
	//生产工序ID
	CC_SYNTHESIZE(uint64_t, processid, ProcessId);
	//生产工序编号
	CC_SYNTHESIZE(string, processcode, ProcessCode);
	//生产工序名称
	CC_SYNTHESIZE(string, processname, ProcessName);
	//生产工序说明
	CC_SYNTHESIZE(string, attention, Attention);
	//是否启用
	CC_SYNTHESIZE(string, enableflag, EnableFlag);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);

public:
	ProProcessDO() {
		processid = 1;
		processcode = "";
		processname = "";
		attention = "";
		enableflag = "";
		remark = "";
	}

};

#endif // !_PRO_PROCESS_
