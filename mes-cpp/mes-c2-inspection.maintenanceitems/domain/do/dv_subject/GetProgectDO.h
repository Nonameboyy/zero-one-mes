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
#ifndef _GETPROGECT_DO_
#define _GETPROGECT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */

//通过id查询数据库 项目详情
class GetProgectIdDO
{
	//项目ID
	CC_SYNTHESIZE(string, subjectId, SubjectId);

public:
	GetProgectIdDO() {
		subjectId = "";
	}
};

//项目分页查询
class GetProgectListAllDO
{
	// 项目编码
	CC_SYNTHESIZE(string, subjectCode, SubjectCode);

	// 项目名称
	CC_SYNTHESIZE(string, subjectName, SubjectName);

	// 项目类型
	CC_SYNTHESIZE(string, subjectType, SubjectType);
public:
	GetProgectListAllDO() {
		subjectCode = "";
		subjectName = "";
		subjectType = "";
	}
};

class GetProgectListSomeDO
{
	//项目ID
	CC_SYNTHESIZE(string, subjectId, SubjectId);

	// 项目编码
	CC_SYNTHESIZE(string, subjectCode, SubjectCode);

	// 项目名称
	CC_SYNTHESIZE(string, subjectName, SubjectName);

	// 项目类型
	CC_SYNTHESIZE(string, subjectType, SubjectType);

	// 项目内容
	CC_SYNTHESIZE(string, subjectContent, SubjectContent);

	//标准
	CC_SYNTHESIZE(string, subjectStandard, SubjectStandard);

	//是否启用
	CC_SYNTHESIZE(string, enableFlag, EnableFlag);

	//备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	GetProgectListSomeDO() {
		subjectId= "";
		subjectCode = "";
		subjectName = "";
		subjectType = "";
		subjectContent = "";
		subjectStandard = "";
		enableFlag = "N";

	}

};

#endif // !_GETPROGECT_DO_
