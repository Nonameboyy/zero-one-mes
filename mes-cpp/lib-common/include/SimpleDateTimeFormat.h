#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/24 14:27:06

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
#ifndef _SIMPLEDATETIMEFORMAT_H_
#define _SIMPLEDATETIMEFORMAT_H_
#include <string>

/**
 * ����һ���򵥵�ʱ���ʽ������
 * �ο���https://zh.cppreference.com/w/cpp/io/manip/put_time
 */
class SimpleDateTimeFormat final
{
public:
	//************************************
	// Method:    format
	// FullName:  SimpleDateTimeFormat::format
	// Access:    public static 
	// Returns:   std::string ���ظ�ʽ������ַ���
	// Description: ��ȡ��ǰʱ���ʽ�ַ���
	// Parameter: const std::string & fmt ��ʽ�ַ�����Ĭ��ֵ%Y-%m-%d %H:%M:%S����Ӧ��ʽ�磺2023-01-01 01:01:01��
	//************************************
	static std::string format(const std::string& fmt = "%Y-%m-%d %H:%M:%S");

	//************************************
	// Method:    formatWithMilli
	// FullName:  SimpleDateTimeFormat::formatWithMilli
	// Access:    public static 
	// Returns:   std::string ���ظ�ʽ������ַ���
	// Description: ��ȡ��ǰʱ���ʽ�ַ�����������ʱ���ȡ
	// Parameter: const std::string & fmt ��ʽ�ַ�����Ĭ��ֵ%Y-%m-%d %H:%M:%S����Ӧ��ʽ�磺2023-01-01 01:01:01��
	// Parameter: const std::string msDelim ������ǰ���ֵķָ����Ĭ���ǿո�
	//************************************
	static std::string formatWithMilli(const std::string& fmt = "%Y-%m-%d %H:%M:%S", const std::string msDelim = " ");
};

#endif // !_SIMPLEDATETIMEFORMAT_H_