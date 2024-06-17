#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/24 15:34:00

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
#ifndef _APPCOMPONENT_HPP_
#define _APPCOMPONENT_HPP_

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#ifndef CLOSE_SWAGGER_DOC
#include "SwaggerComponent.hpp"
#endif
#include "ErrorHandler.h"
#include "SystemInterceptor.h"

/**
 * ��oatpp::base::Environment�д����ͱ���Application�������������ע��
 * �����ʼ����˳���Ǵ��ϵ���
 */
class AppComponent
{
public:
#ifndef CLOSE_SWAGGER_DOC
	// ������Ⱦ�ӿ��ĵ���Swagger���
	SwaggerComponent swaggerComponent;
#endif

	// ����·�����
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)([] {
		return oatpp::web::server::HttpRouter::createShared();
		}());
	// ����ObjectMapper�������Controller��API�����л�/�����л�DTO
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)([] {
		auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
		objectMapper->getDeserializer()->getConfig()->allowUnknownFields = false;
		return objectMapper;
		}());
	// ����ʹ��Router���·��http�����ConnectionHandler���
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, httpConnectionHandler)("http", [] {
		OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
		OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);
		// ����һ�����Ӵ�����
		auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);
		// ���ͨ�ô�������
		connectionHandler->setErrorHandler(std::make_shared<ErrorHandler>(objectMapper));
		// ��ӿ�������������
		connectionHandler->addRequestInterceptor(std::make_shared<CrosRequestInterceptor>());
		// ��ӿ�����Ӧ������
		connectionHandler->addResponseInterceptor(std::make_shared<CrosResponseInterceptor>());
		// ���У������������
		connectionHandler->addRequestInterceptor(std::make_shared<CheckRequestInterceptor>(objectMapper));
		return connectionHandler;
		}());
};

#endif // _APPCOMPONENT_HPP_