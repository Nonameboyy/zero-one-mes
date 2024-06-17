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
 * ��дһ�����ŷ������
 * ע�⣺
 * 1���������֧��Windowsƽ̨��Ҫʹ�ô��������Linux��������ʹ��
 * 2��ʹ�õ�ʱ����Ҫ����AliKeyConfig����س�Ա�����ͳ�Ա����������ָ��ak��sk���ֵ
 */
class AliSmsSender
{
public:
	//************************************
	// Method:    AliSmsSender
	// FullName:  AliSmsSender::AliSmsSender
	// Access:    public 
	// Returns:   
	// Description: �����ʼ��
	// Parameter: const std::string& keyfilename key�����ļ�����
	// Parameter: const std::string& prefix ���ö�ȡǰ׺
	//************************************
	AliSmsSender(const std::string& keyfilename = "key-config.yaml", const std::string& prefix = "aliyun.sms");
	// ����
	~AliSmsSender();
	//************************************
	// Method:    sendSms
	// FullName:  AliSmsSender::sendSms
	// Access:    public 
	// Returns:   std::shared_ptr<AliSmsResult> ���ͽ��
	// Description: ���͵�����Ϣ
	// Parameter: const std::string& phoneNumber �ֻ�����
	// Parameter: const std::string& signName ǩ�����ơ��磺�����ƶ��Ų���
	// Parameter: const std::string& templateCode ����ģ��CODE���磺SMS_15******
	// Parameter: const std::string& templateParams ģ�����ֵ��json���ݸ�ʽ���磺{"code":"996007"}
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
	// Description: �������Ͷ��ţ��ýӿڵ������֧��100�����롣ע�������������в�����ʽ����json��ʽ�ַ���
	// Parameter: const std::string & phoneNumbers �ֻ������б��磺["132xxxxxxx","159xxxxxxx"]
	// Parameter: const std::string & signNames ����ǩ�����ƣ�����ǩ���ĸ����������ֻ�����ĸ�����ͬ������һһ��Ӧ��
	//												 �磺["ǩ��1","ǩ��2"]
	// Parameter: const std::string & templateCode ����ģ��CODE���磺SMS_15******
	// Parameter: const std::string & templateParams ����ģ�������Ӧ��ʵ��ֵ��ģ�����ֵ�ĸ����������ֻ����롢ǩ���ĸ�����ͬ������һһ��Ӧ����ʾ��ָ���ֻ������з���Ӧǩ���Ķ��ţ��Ҷ���ģ���еı��������滻Ϊ��Ӧ��ֵ��
	//												 �磺[{"code":"996007"},{"code":"857857"}]
	//************************************
	std::shared_ptr<AliSmsResult> sendSmsBatch(
		const std::string& phoneNumbers,
		const std::string& signNames,
		const std::string& templateCode,
		const std::string& templateParams);
};

#endif // !_ALISMSSENDER_H_