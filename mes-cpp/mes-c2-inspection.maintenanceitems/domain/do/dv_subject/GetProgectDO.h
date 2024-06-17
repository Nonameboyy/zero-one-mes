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
 * ʾ�����ݿ�ʵ����
 */

//ͨ��id��ѯ���ݿ� ��Ŀ����
class GetProgectIdDO
{
	//��ĿID
	CC_SYNTHESIZE(string, subjectId, SubjectId);

public:
	GetProgectIdDO() {
		subjectId = "";
	}
};

//��Ŀ��ҳ��ѯ
class GetProgectListAllDO
{
	// ��Ŀ����
	CC_SYNTHESIZE(string, subjectCode, SubjectCode);

	// ��Ŀ����
	CC_SYNTHESIZE(string, subjectName, SubjectName);

	// ��Ŀ����
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
	//��ĿID
	CC_SYNTHESIZE(string, subjectId, SubjectId);

	// ��Ŀ����
	CC_SYNTHESIZE(string, subjectCode, SubjectCode);

	// ��Ŀ����
	CC_SYNTHESIZE(string, subjectName, SubjectName);

	// ��Ŀ����
	CC_SYNTHESIZE(string, subjectType, SubjectType);

	// ��Ŀ����
	CC_SYNTHESIZE(string, subjectContent, SubjectContent);

	//��׼
	CC_SYNTHESIZE(string, subjectStandard, SubjectStandard);

	//�Ƿ�����
	CC_SYNTHESIZE(string, enableFlag, EnableFlag);

	//��ע
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
