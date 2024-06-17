#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/25 16:18:28

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
#ifndef _ALISMSSENDER_H_
#define _ALISMSSENDER_H_
#include <memory>
#include "AliSmsResult.h"

/**
 * 书写一个短信发送组件
 * 注意：
 * 1、此组件不支持Windows平台，要使用此组件请在Linux环境下面使用
 * 2、使用的时候需要定义AliKeyConfig类相关成员变量和成员函数，用于指定ak和sk相关值
 */
class AliSmsSender
{
public:
	//************************************
	// Method:    AliSmsSender
	// FullName:  AliSmsSender::AliSmsSender
	// Access:    public 
	// Returns:   
	// Description: 构造初始化
	// Parameter: const std::string& keyfilename key配置文件名称
	// Parameter: const std::string& prefix 配置读取前缀
	//************************************
	AliSmsSender(const std::string& keyfilename = "key-config.yaml", const std::string& prefix = "aliyun.sms");
	// 析构
	~AliSmsSender();
	//************************************
	// Method:    sendSms
	// FullName:  AliSmsSender::sendSms
	// Access:    public 
	// Returns:   std::shared_ptr<AliSmsResult> 发送结果
	// Description: 发送单条信息
	// Parameter: const std::string& phoneNumber 手机号码
	// Parameter: const std::string& signName 签名名称。如：阿里云短信测试
	// Parameter: const std::string& templateCode 短信模板CODE。如：SMS_15******
	// Parameter: const std::string& templateParams 模板参数值，json数据格式。如：{"code":"996007"}
	//************************************
	std::shared_ptr<AliSmsResult> sendSms(
		const std::string& phoneNumber,
		const std::string& signName,
		const std::string& templateCode,
		const std::string& templateParams);
	//************************************
	// Method:    sendSmsBatch
	// FullName:  AliSmsSender::sendSmsBatch
	// Access:    public 
	// Returns:   std::shared_ptr<AliSmsResult>
	// Description: 批量发送短信，该接口单次最多支持100个号码。注意批量发送所有参数格式都是json格式字符串
	// Parameter: const std::string & phoneNumbers 手机号码列表。如：["132xxxxxxx","159xxxxxxx"]
	// Parameter: const std::string & signNames 短信签名名称，短信签名的个数必须与手机号码的个数相同、内容一一对应。
	//												 如：["签名1","签名2"]
	// Parameter: const std::string & templateCode 短信模板CODE。如：SMS_15******
	// Parameter: const std::string & templateParams 短信模板变量对应的实际值，模板变量值的个数必须与手机号码、签名的个数相同、内容一一对应，表示向指定手机号码中发对应签名的短信，且短信模板中的变量参数替换为对应的值。
	//												 如：[{"code":"996007"},{"code":"857857"}]
	//************************************
	std::shared_ptr<AliSmsResult> sendSmsBatch(
		const std::string& phoneNumbers,
		const std::string& signNames,
		const std::string& templateCode,
		const std::string& templateParams);
};

#endif // !_ALISMSSENDER_H_