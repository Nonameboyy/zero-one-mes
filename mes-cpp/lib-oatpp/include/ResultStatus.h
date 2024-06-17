#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/25 11:17:48
 
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
#ifndef _RESULT_STATUS_
#define _RESULT_STATUS_

#include <string>

/**
 * ��Ӧ���״̬
 */
class ResultStatus
{
public:
	// �����ʼ��
	explicit ResultStatus(std::string message, int code = 10000);
	// ��ȡ״̬��ʾ��Ϣ
	std::string getMessage();
	// ��ȡ״̬��
	int getCode();
private:
	// ״̬��
	int code;
	// ״̬��ʾ��Ϣ
	std::string message;
};

#endif // !_RESULT_STATUS_