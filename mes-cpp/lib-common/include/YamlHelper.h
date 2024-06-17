#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 16:19:31

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
#ifndef _YAMLHELPER_H_
#define _YAMLHELPER_H_
#include "yaml-cpp/yaml.h"

class YamlHelper final
{
public:
	//************************************
	// Method:    getString
	// FullName:  YamlCpp::getString
	// Access:    public 
	// Returns:   std::string
	// Description: ��Properties����ȡYaml���ö�Ӧ���ַ���
	// Parameter: YAML::Node * node ���ݽڵ�
	// Parameter: const std::string & key ���ݵ�key����spring.datasource.url
	//************************************
	std::string getString(YAML::Node* node, const std::string& key);

	//************************************
	// Method:    parseDbConnUrl
	// FullName:  YamlHelper::parseDbConnUrl
	// Access:    public 
	// Returns:   void
	// Description: �������ݿ������ַ�����ȡ���ݿ������Ϣ
	// Parameter: const std::string& url ���ݿ������ַ���
	// Parameter: std::string * ip ����IP
	// Parameter: int * port ����˿�
	// Parameter: std::string * dbname �������ݿ�����
	//************************************
	void parseDbConnUrl(const std::string& url, std::string* ip, int* port, std::string* dbname);
};
#endif // _YAMLHELPER_H_
