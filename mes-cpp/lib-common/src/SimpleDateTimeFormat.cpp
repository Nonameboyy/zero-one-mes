/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/24 15:45:36

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
#include "pch.h"
#include "../include/SimpleDateTimeFormat.h"
#include <chrono>
#include <sstream>
#include <iomanip>

std::string SimpleDateTimeFormat::format(const std::string& fmt /*= "%Y-%m-%d %H:%M:%S"*/)
{
	// ��ȡ��ǰʱ��
	auto now = std::chrono::system_clock::now();
	
	// ��ʽʱ��
	std::stringstream ss;
	auto tNow = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tNow), fmt.c_str());
	return ss.str();
}

std::string SimpleDateTimeFormat::formatWithMilli(const std::string& fmt /*= "%Y-%m-%d %H:%M:%S"*/, const std::string msDelim /*= " "*/)
{
	// ��ȡ��ǰʱ��
	auto now = std::chrono::system_clock::now();
	
	// ��ʽ��ʱ��
	std::stringstream ss;
	auto tNow = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tNow), fmt.c_str());

	// ��ȡ��ǰʱ�������
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	// ��ȡ��ǰʱ��ĺ���
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	// �������������
	auto ms = tMilli - tSeconds;
	ss << msDelim << std::setfill('0') << std::setw(3) << ms.count();
	return ss.str();
}
