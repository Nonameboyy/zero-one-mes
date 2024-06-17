#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 13:59:13

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
#ifndef _JWT_UTIL_
#define _JWT_UTIL_
#include <list>
#include <memory>
#include "domain/dto/PayloadDTO.h"

/**
 * JWT������
 */
class JWTUtil
{
private:
	//���ַ�������MD5����
	static std::string md5(const std::string& src);
public:
	//************************************
	// Method:    generateTokenByHmac
	// FullName:  JWTUtil::generateTokenByHmac
	// Access:    public static 
	// Returns:   std::string ����Token�ַ���
	// Description: ʹ��HMAC�㷨����Token
	// Parameter: const PayloadDTO& payloadDto ������Ϣ����
	// Parameter: const std::string& secretStr ��Կ
	//************************************
	static std::string generateTokenByHmac(const PayloadDTO& payloadDto, const std::string& secretStr);

	//************************************
	// Method:    verifyTokenByHmac
	// FullName:  JWTUtil::verifyTokenByHmac
	// Access:    public static 
	// Returns:   PayloadDTO ������Ϣ����
	// Description: ��֤HMAC Token
	// Parameter: const std::string& token Token�ַ���
	// Parameter: const std::string& secretStr ��Կ
	//************************************
	static PayloadDTO verifyTokenByHmac(const std::string& token, const std::string& secretStr);

	//************************************
	// Method:    generateTokenByRsa
	// FullName:  JWTUtil::generateTokenByRsa
	// Access:    public static 
	// Returns:   std::string
	// Description: ʹ��RSA Pem����Token����Կ���������ɹ��ߣ�http://www.metools.info/code/c80.html
	// Parameter: const PayloadDTO& payloadDto ������Ϣ
	// Parameter: const std::string& rsaPriKey RSA˽Կ
	//************************************
	static std::string generateTokenByRsa(const PayloadDTO& payloadDto, const std::string& rsaPriKey);

	//************************************
	// Method:    verifyTokenByRsa
	// FullName:  JWTUtil::verifyTokenByRsa
	// Access:    public static 
	// Returns:   PayloadDTO
	// Description: ��֤RSA Pem Token
	// Parameter: const std::string& token Token�ַ���
	// Parameter: const std::string& rsaPubKey RSA��Կ
	//************************************
	static PayloadDTO verifyTokenByRsa(const std::string& token, const std::string& rsaPubKey);
};
#endif // !_JWT_UTIL_
