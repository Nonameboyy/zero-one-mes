#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/29 16:37:06

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
#ifndef _SYSTEMINTERCEPTOR_H_
#define _SYSTEMINTERCEPTOR_H_
#include "oatpp/web/server/interceptor/RequestInterceptor.hpp"
#include "oatpp/web/server/interceptor/ResponseInterceptor.hpp"

/**
 * ��������������
 */
class CrosRequestInterceptor : public oatpp::web::server::interceptor::RequestInterceptor
{
public:
	// ������ִ���߼�
	std::shared_ptr<OutgoingResponse> intercept(const std::shared_ptr<IncomingRequest>& request) override;
};

/**
 * ������Ӧ������
 */
class CrosResponseInterceptor : public oatpp::web::server::interceptor::ResponseInterceptor {
public:
	// ������ִ���߼�
	std::shared_ptr<OutgoingResponse> intercept(const std::shared_ptr<IncomingRequest>& request, const std::shared_ptr<OutgoingResponse>& response) override;
};

/**
 * У��ƾ֤����������
 */
class CheckRequestInterceptor : public oatpp::web::server::interceptor::RequestInterceptor
{
private:
	// DTO���л�����
	std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_objectMapper;
public:
	// �����ʱ�����������л�����
	explicit CheckRequestInterceptor(const std::shared_ptr<oatpp::data::mapping::ObjectMapper>& objectMapper);
	// ������ִ���߼�
	std::shared_ptr<OutgoingResponse> intercept(const std::shared_ptr<IncomingRequest>& request) override;
};

#endif // !_SYSTEMINTERCEPTOR_H_