/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/08 21:56:28

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
#ifdef USE_ALISMS
#include "Macros.h"
#include "sms/aliyun/AliKeyConfig.h"
#include "NacosClient.h"

/**
 * �ڴ����AliKeyConfig�ྲ̬��Ա��������
 */
std::string AliKeyConfig::region = "";
std::string AliKeyConfig::ak = "";
std::string AliKeyConfig::sk = "";

/**
 * �ڴ����AliKeyConfig��ʼ�������Ķ���
 */
void AliKeyConfig::init(const std::string& fileName, const std::string& prefix /*= "aliyun.sms"*/)
{
	// �Ѿ���ʼ���Ͳ��ڳ�ʼ��
	if (!ak.empty()) return;

	// ��������ID
	region = "cn-hangzhou";
#ifdef LINUX
	// ��Nacos�л�ȡ��������
	NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
	YAML::Node node = nacosClient.getConfig(fileName);
	YamlHelper yaml;
	ak = yaml.getString(&node, prefix + ".ak");
	sk = yaml.getString(&node, prefix + ".sk");
#endif
}

#endif // USE_ALISMS