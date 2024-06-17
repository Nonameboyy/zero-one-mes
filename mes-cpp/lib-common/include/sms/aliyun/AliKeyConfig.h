#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/25 15:53:32

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
#ifndef _ALIKEYCONFIG_H_
#define _ALIKEYCONFIG_H_
#include <string>

/**
 * 阿里云相关秘钥和key配置数据
 * 注意：此类的静态变量和静态函数需要再外部系统定义它们
 */
class AliKeyConfig final
{
public:
	// region-id
	static std::string region;
	// AccessKey
	static std::string ak;
	// AccessKeySecret
	static std::string sk;
	//************************************
	// Method:    init
	// FullName:  AliKeyConfig::init
	// Access:    public static 
	// Returns:   void
	// Description: 初始化配置数据
	// Parameter: const std::string& fileName 配置文件名
	// Parameter: const std::string& prefix sms配置前缀
	//************************************
	static void init(const std::string& fileName, const std::string& prefix);
};

#endif // !_ALIKEYCONFIG_H_