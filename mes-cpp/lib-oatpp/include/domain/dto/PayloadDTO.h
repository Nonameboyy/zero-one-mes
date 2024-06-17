#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/22 20:18:53

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
#ifndef _PAYLOADDTO_H_
#define _PAYLOADDTO_H_
#include "jwt/jwt.hpp"

/**
 * ������Ϣ��ȡ״̬����
 */
enum class PayloadCode
{
	// ��Ϣ��֤����ɹ�
	SUCCESS,
	// Token�ѹ���
	TOKEN_EXPIRED_ERROR,
	// ǩ����ʽ����
	SIGNATUREFORMAT_ERROR,
	// ���ܴ���
	DECODE_ERROR,
	// ��֤����
	VERIFICATION_ERROR,
	// ��������
	OTHER_ERROR
};

/**
 * ������Ϣʵ����
 */
class PayloadDTO
{
public:
	// ��ȡ״̬���Ӧ��ö��ֵ����
	static std::string getCodeName(PayloadCode code) 
	{
		switch (code)
		{
		case PayloadCode::SUCCESS:
			return "SUCCESS";
		case PayloadCode::TOKEN_EXPIRED_ERROR:
			return "TOKEN_EXPIRED_ERROR";
		case PayloadCode::SIGNATUREFORMAT_ERROR:
			return "SIGNATUREFORMAT_ERROR";
		case PayloadCode::DECODE_ERROR:
			return "DECODE_ERROR";
		case PayloadCode::VERIFICATION_ERROR:
			return "VERIFICATION_ERROR";
		case PayloadCode::OTHER_ERROR:
			return "OTHER_ERROR";
		default:
			return "NONE";
		}
	}
	// ��ȡƾ֤ǰ׺
	static std::string getTokenPrefix() {
		return "Bearer ";
	}
private:
	// Token�ַ�����Ӧ��ֵ
	std::string token;
	// ��������
	std::string sub;
	// ƾ֤��Чʱ�����룩
	int64_t exp;
	// �û����
	std::string id;
	// �û���
	std::string username;
	// �û�ӵ�е�Ȩ��
	std::list<std::string> authorities;
	// ����״̬ϵ��Ϣ
	PayloadCode code;
public:
	PayloadDTO()
	{
		this->username = "";
		this->exp = 0;
		this->sub = "";
		this->setCode(PayloadCode::SUCCESS);
	}
	PayloadDTO(std::string _sub, int64_t _exp, std::string _username, std::list<std::string> _authorities) :
		sub(_sub), exp(_exp), username(_username), authorities(_authorities)
	{
		this->setCode(PayloadCode::SUCCESS);
	}
	
	// getter/setter
	std::string getSub() const { return sub; }
	void setSub(std::string val) { sub = val; }
	int64_t getExp() const { return exp; }
	void setExp(int64_t val) { exp = val; }
	std::string getUsername() const { return username; }
	void setUsername(std::string val) { username = val; }
	std::list<std::string>& getAuthorities() { return authorities; }
	void setAuthorities(std::list<std::string> val) { authorities = val; }
	PayloadCode getCode() const { return code; }
	void setCode(PayloadCode val) { code = val; }
	std::string getId() const { return id; }
	void setId(std::string val) { id = val; }
	std::string getToken() const { return token; }
	void setToken(std::string val) { token = val; }

	// ���Ȩ��
	void putAuthority(std::string authstr) { authorities.push_back(authstr); }
	
	// ��Payload������ת����jwt_object��
	// ע�⣺���������ֶκ���Ҫά���˷���
	template<class T>
	void propToJwt(T* obj) const
	{
		// ת��Ȩ���б�
		obj->add_claim("authorities", authorities);
		// ת���û���
		obj->add_claim("user_name", username);
		// ת��id
		obj->add_claim("id", id);
		// TIP�������ֶ��ں��油�伴��
	}

	// ��jwt_object������ת����Payload��
	// ע�⣺���������ֶκ���Ҫά���˷���
	void propToPayload(jwt::jwt_object* obj) 
	{
		// ��ȡ������Ϣ
		auto payload = obj->payload();
		auto _payload = payload.create_json_obj();

		// ת��Ȩ���б�
		if (_payload.contains("authorities"))
			setAuthorities(payload.get_claim_value<std::list<std::string>>("authorities"));
		// ת���û���
		setUsername(payload.get_claim_value<std::string>("user_name"));
		// ת����������id
		if (_payload["id"].is_number()) 
			setId(std::to_string(_payload["id"].get<int64_t>()));
		// ת���ַ�������id
		else
			setId(_payload["id"].get<std::string>());
		// TIP�������ֶ��ں��油�伴��
	}
};

#endif // !_PAYLOADDTO_H_