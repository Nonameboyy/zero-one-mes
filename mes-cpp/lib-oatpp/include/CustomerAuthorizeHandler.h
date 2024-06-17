#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/05 16:50:35

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
#ifndef _CUSTOMERAUTHORIZEHANDLER_H_
#define _CUSTOMERAUTHORIZEHANDLER_H_
#include "oatpp/web/server/handler/AuthorizationHandler.hpp"
#include "JWTUtil.h"

/**
 * �Զ�����Ȩʵ������ʵ��
 */
class CustomerAuthorizeObject : public oatpp::web::server::handler::AuthorizationObject
{
private:
	// �������ݼ�¼ʵ��
	PayloadDTO payload;
public:
	// �������ʼ��
	CustomerAuthorizeObject(PayloadDTO payload);
	// ��ȡ�������ݶ���
	const PayloadDTO& getPayload();
};

/**
 * �Զ�����Ȩ������
 */
class CustomerAuthorizeHandler : public oatpp::web::server::handler::BearerAuthorizationHandler
{
public:
	// �����ʼ����Կ��ȡ
	CustomerAuthorizeHandler();
	// ��Ȩ�߼�
	std::shared_ptr<AuthorizationObject> authorize(const oatpp::String& token) override;
};

#endif // _CUSTOMERAUTHORIZEHANDLER_H_