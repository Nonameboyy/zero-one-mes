/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 14:37:50

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
#include "jwt/jwt.hpp"
#include <openssl/md5.h>
#include <iostream>
#include "JWTUtil.h"
using namespace jwt;

#define JU_VERIFY_CATCH(__p__) \
catch (const jwt::TokenExpiredError& e) { \
	std::cerr << "TokenExpiredError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::TOKEN_EXPIRED_ERROR); \
} \
catch (const jwt::SignatureFormatError& e) { \
	std::cerr << "SignatureFormatError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::SIGNATUREFORMAT_ERROR); \
} \
catch (const jwt::DecodeError& e) { \
	std::cerr << "DecodeError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::DECODE_ERROR); \
} \
catch (const jwt::VerificationError& e) { \
	std::cerr << "VerificationError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::VERIFICATION_ERROR); \
} \
catch (const std::exception& e) { \
	std::cerr << "OtherError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::OTHER_ERROR); \
}

std::string JWTUtil::md5(const std::string& src)
{
	MD5_CTX ctx;
	std::string md5_string;
	unsigned char md[16] = { 0 };
	char tmp[33] = { 0 };
	MD5_Init(&ctx);
	MD5_Update(&ctx, src.c_str(), src.size());
	MD5_Final(md, &ctx);
	for (int i = 0; i < 16; ++i)
	{
		memset(tmp, 0x00, sizeof(tmp));
		snprintf(tmp, sizeof(tmp), "%02X", md[i]);
		md5_string += tmp;
	}
	return md5_string;
}

std::string JWTUtil::generateTokenByHmac(const PayloadDTO& payloadDto, const std::string& secretStr)
{
	//1 创建JWT头，设置签名算法和类型
	jwt_header hdr = jwt_header{ jwt::algorithm::HS256 };
	//2 将负载信息封装到Payload中
	jwt::jwt_payload jp;
	//2.1 呼叫属性转换
	payloadDto.propToJwt(&jp);
	//2.2 失效时间在内部处理
	jp.add_claim("exp", std::chrono::system_clock::now() + std::chrono::seconds{ payloadDto.getExp() });
	//3 创建HMAC签名器
	jwt::jwt_signature sgn{ md5(secretStr) };
	std::error_code ec{};
	//4 生成token
	auto res = sgn.encode(hdr, jp, ec);
	return res;
}

PayloadDTO JWTUtil::verifyTokenByHmac(const std::string& token, const std::string& secretStr)
{
	PayloadDTO p;
	using namespace jwt::params;
	try {
		jwt_object dec_obj = jwt::decode(token, algorithms({ "HS256" }), secret(string_view(md5(secretStr))), verify(true));
		// 呼叫属性转换
		p.propToPayload(&dec_obj);
		// 失效时间在内部处理
		p.setExp(dec_obj.payload().get_claim_value<int64_t>("exp"));
	}
	JU_VERIFY_CATCH(p);
	return p;
}

std::string JWTUtil::generateTokenByRsa(const PayloadDTO& payloadDto, const std::string& rsaPriKey)
{
	jwt::jwt_object obj;
	obj.secret(rsaPriKey);
	obj.header().algo(jwt::algorithm::RS256);
	// 呼叫属性转换
	payloadDto.propToJwt(&obj);
	// 失效时间在内部处理
	obj.add_claim("exp", std::chrono::system_clock::now() + std::chrono::seconds{ payloadDto.getExp() });
	return obj.signature();
}

PayloadDTO JWTUtil::verifyTokenByRsa(const std::string& token, const std::string& rsaPubKey)
{
	PayloadDTO p;
	using namespace jwt::params;
	try {
		jwt_object dec_obj = jwt::decode(token, algorithms({ "RS256" }), secret(rsaPubKey), verify(true));
		// 呼叫属性转换
		p.propToPayload(&dec_obj);
		// 失效时间在内部处理
		p.setExp(dec_obj.payload().get_claim_value<int64_t>("exp"));
	}
	JU_VERIFY_CATCH(p);
	return p;
}
