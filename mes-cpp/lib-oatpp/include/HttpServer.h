#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/27 16:49:14

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
#ifndef _HTTPSERVER_H_
#define _HTTPSERVER_H_
#include <string>
#include "oatpp/web/server/api/Endpoint.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "AbstractComponentReg.h"
using namespace std;
using namespace oatpp::web::server::api;
using namespace oatpp::web::server;

/**
 * ����HttpServer���
 */
class HttpServer
{
private:
	// ��ʼ��������
	static void initServer(string port, string host, function<void(Endpoints*, HttpRouter*)> bindRouterFun, function<void(std::shared_ptr<AbstractComponentReg>*)> otherComponentRegCall);
public:
	//************************************
	// Method:    startServer
	// FullName:  HttpServer::startServer
	// Access:    public static 
	// Returns:   int
	// Description: ����HTTP������
	// Parameter: string port �󶨶˿�
	// Parameter: function<void(Endpoints*, HttpRouter*)> bindRouterFun ��ʼ��·�ɻص�
	// Parameter: function<void(std::shared_ptr<AbstractComponentReg>*> otherComponentRegCall �������Ҫ���ⲿע���������ͨ���ûص�ִ�����ע�ᣬĬ��Ϊnullptr
	// Parameter: string host �󶨵�ַ��Ĭ��ֵ0.0.0.0
	//************************************
	static void startServer(string port, function<void(Endpoints*, HttpRouter*)> bindRouterFun, function<void(std::shared_ptr<AbstractComponentReg>*)> otherComponentRegCall = nullptr, string host = "0.0.0.0");
};

#endif // _HTTPSERVER_H_