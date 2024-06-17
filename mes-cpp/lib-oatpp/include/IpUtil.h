#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/20 16:19:48

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
#ifndef _IPUTIL_H_
#define _IPUTIL_H_
#include <string>
#include <vector>

/**
 * ip��ַ������
 */
class IpUtil
{
public:
	//************************************
	// Method:    getLocalIpAddress
	// FullName:  IpUtil::getLocalIpAddress
	// Access:    public static 
	// Returns:   size_t ����ip��ַ��
	// Description: ��ȡip��ַ�б�
	// Parameter: std::vector<std::string> * addresses �洢ip��ַ������
	//************************************
	static size_t getLocalIpAddress(std::vector<std::string>* addresses);
};

#endif // !_IPUTIL_H_