/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/28 14:05:46

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
#include <iostream>
#include <signal.h>
#include "oatpp/network/Server.hpp"
#ifndef CLOSE_SWAGGER_DOC
#include "oatpp-swagger/Controller.hpp"
#endif
#include "../include/HttpServer.h"
#include "../include/AppComponent.hpp"
#include "../include/IpUtil.h"

// ���û�ж���رշ���������
#ifndef STOP_PWD
#define STOP_PWD "01star"
#endif

// ����һ��ȫ�ֱ����������Ƿ��÷���������
bool isAllowServerRun = true;

// ����ر����������
#include OATPP_CODEGEN_BEGIN(ApiController)
class ServerCloseController : public oatpp::web::server::api::ApiController {
public:
	ServerCloseController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) :oatpp::web::server::api::ApiController(objectMapper) {}
	static std::shared_ptr<ServerCloseController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
	{
		return std::make_shared<ServerCloseController>(objectMapper);
	}
	ENDPOINT("GET", "/system-kill/{pwd}", closeServer, PATH(String, pwd)) {
		if (pwd == STOP_PWD)
		{
			isAllowServerRun = false;
			OATPP_LOGD("Server", "server stop ok");
			return createResponse(Status::CODE_200, "server will close \r\n");
		}
		return createResponse(Status::CODE_200, "password is not right \r\n");
	}
};
#include OATPP_CODEGEN_END(ApiController)

void HttpServer::initServer(string port, string host, function<void(Endpoints*, HttpRouter*)> bindRouterFun, function<void(std::shared_ptr<AbstractComponentReg>*)> otherComponentRegCall)
{
	// ע�ỷ�����
	AppComponent components;
	// ע���������
	std::shared_ptr<AbstractComponentReg> other = nullptr;
	if (otherComponentRegCall)
	{
		otherComponentRegCall(&other);
	}

	// ���������˿ڵ�ConnectionProvider���
	uint16_t currPort = (uint16_t)strtoul(port.c_str(), NULL, 0);
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)([=] {
		return oatpp::network::tcp::server::ConnectionProvider::createShared({ host, currPort, oatpp::network::Address::IP_4 });
		}());
	// ��ȡ·�����
	OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
	// ��ȡ���Ӵ������
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler, "http");
	// ��ȡ�����ṩ���
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);
	// ��������
	oatpp::network::Server server(connectionProvider, connectionHandler);
	// ��ӡ��������Ϣ
	OATPP_LOGD("Server", "Running on port %s...", connectionProvider->getProperty("port").toString()->c_str());

	// �����ĵ��˵�
	oatpp::web::server::api::Endpoints docEndpoints;

	// ��ʼ��·��
	bindRouterFun(&docEndpoints, router.get());

#ifndef CLOSE_SWAGGER_DOC
	// ���API�ĵ�������
	router->addController(oatpp::swagger::Controller::createShared(docEndpoints));
#endif

	// ��ӹرշ��������
	router->addController(ServerCloseController::createShared());
	OATPP_LOGD("Server", "Router init success");
	OATPP_LOGD("Server", "local  api doc url is http://localhost:%s/swagger/ui", port.c_str());

	// ��ȡip��ַ
	std::vector<std::string> addresses;
	if (IpUtil::getLocalIpAddress(&addresses))
	{
		for (auto ip : addresses)
		{
			if (ip.find("127.") == string::npos &&
				ip.find("172.") == string::npos &&
				ip.find("::") == string::npos)
			{
				OATPP_LOGD("Server", "remote api doc url is http://%s:%s/swagger/ui", ip.c_str(), port.c_str());
				break;
			}
		}
	}

	// �󶨽����źż�����Ctrl + C��
	signal(SIGINT, [](int signum)
		{
			isAllowServerRun = false;
			OATPP_LOGD("Server", "server stop ok");
		});

	// ���з���
	server.run([=] {return isAllowServerRun; });
}

void HttpServer::startServer(string port, function<void(Endpoints*, HttpRouter*)> bindRouterFun, function<void(std::shared_ptr<AbstractComponentReg>*)> otherComponentRegCall /*= nullptr*/, string host /*= "0.0.0.0"*/)
{
	oatpp::base::Environment::init();

	initServer(port, host, bindRouterFun, otherComponentRegCall);

	/* Print how many objects were created during app running, and what have left-probably leaked */
	/* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
	std::cout << std::endl << "Environment:" << std::endl;
	std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << std::endl;
	std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << std::endl;

	oatpp::base::Environment::destroy();
}
