/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:02:34

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
#include "stdafx.h"
#include "StringUtil.h"
#include "ServerInfo.h"
#include "HttpServer.h"
#include "controller/Router.h"
#include "controller/OtherComponent.hpp"
#include "DbInit.h"

#ifdef LINUX
#include "NacosClient.h"
#endif

// �Ƿ��Ƿ���Swagger�ĵ���
#ifndef _RELEASE_DOC_
// �鿴Swagger�ĵ���ʱ����Ҫ�������ݿ⣬�⿪�����ע�͹ر������������ݿ�
//#define _RELEASE_DOC_
#endif

/**
 * ������������
 * ע�⣺
 * ������������Ҫ����һ���ĸ�ʽ���磺sp=8090��sn=feign-cpp-sample
 * ǰ׺����ʵֵ֮��ʹ��=�ָ�
 */
bool getStartArg(int argc, char* argv[]) {
	// �������˿�
	std::string serverPort = "8090";
	// ���ݿ�������Ϣ
	std::string dbUsername = "root";
	std::string dbPassword = "123456";
	std::string dbName = "zo_mes";
	std::string dbHost = "172.22.32.136";
	int dbPort = 3306;
	int dbMax = 5;
#ifdef LINUX
	// Nacos���ò���
	std::string nacosAddr = "192.168.220.128:8848";
	std::string nacosNs = "4833404f-4b82-462e-889a-3c508160c6b4";
	std::string serviceName = "";
	std::string regIp = "";
#endif

	// ��ʼ����
	int currIndex = 1;
	bool isSetDb = false;
	while (currIndex < argc)
	{
		// ����ַ���
		auto args = StringUtil::split(argv[currIndex], "=");
		// �жϲ����Ƿ�Ϸ�
		if (args.size() != 2)
		{
			cout << "arg: " << argv[currIndex] << ", format error." << endl;
			exit(1);
		}

		// ���ݲ���ǰ׺�Բ�ͬ���Ը�ֵ
		std::string prefix = args[0];
		std::string val = args[1];
		if (prefix == "sp") serverPort = val;
		else if (prefix == "du")
		{
			isSetDb = true;
			dbUsername = val;
		}
		else if (prefix == "dp")
		{
			isSetDb = true;
			dbPassword = val;
		}
		else if (prefix == "dn")
		{
			isSetDb = true;
			dbName = val;
		}
		else if (prefix == "dh")
		{
			isSetDb = true;
			dbHost = val;
		}
		else if (prefix == "dP")
		{
			isSetDb = true;
			dbPort = atoi(val.c_str());
		}
		else if (prefix == "dm") dbMax = atoi(val.c_str());
#ifdef LINUX
		else if (prefix == "na") nacosAddr = val;
		else if (prefix == "ns") nacosNs = val;
		else if (prefix == "sn") serviceName = val;
		else if (prefix == "ip") regIp = val;
#endif
		// ��������
		currIndex++;
	}

	// ��¼���������õ��ڴ��з���ʹ��
	ServerInfo::getInstance().setServerPort(serverPort);
	ServerInfo::getInstance().setDbUsername(dbUsername);
	ServerInfo::getInstance().setDbPassword(dbPassword);
	ServerInfo::getInstance().setDbName(dbName);
	ServerInfo::getInstance().setDbHost(dbHost);
	ServerInfo::getInstance().setDbPort(dbPort);
	ServerInfo::getInstance().setDbMax(dbMax);
#ifdef LINUX
	ServerInfo::getInstance().setNacosAddr(nacosAddr);
	ServerInfo::getInstance().setNacosNs(nacosNs);
	ServerInfo::getInstance().setRegIp(regIp);
	ServerInfo::getInstance().setServiceName(serviceName);
#endif
	return isSetDb;
}

int main(int argc, char* argv[]) {
	// ������������ʼ��
	bool isSetDb = getStartArg(argc, argv);

#ifdef LINUX
	// ����Nacos�ͻ��˶���
	NacosClient nacosClient(
		ServerInfo::getInstance().getNacosAddr(),
		ServerInfo::getInstance().getNacosNs());
	// ��Nacos���������л�ȡ���ݿ�����
	if (!isSetDb)
	{
		YAML::Node node = nacosClient.getConfig("data-source.yaml");
		YamlHelper yaml;
		std::string dbUrl = yaml.getString(&node, "spring.datasource.url");
		if (dbUrl != "")
		{
			int dbPort = 0;
			std::string dbHost = "";
			std::string dbName = "";
			// �������ݿ������ַ���
			yaml.parseDbConnUrl(dbUrl, &dbHost, &dbPort, &dbName);
			// ��ȡ���ݿ��û���������
			std::string dbUsername = yaml.getString(&node, "spring.datasource.username");
			std::string dbPassword = yaml.getString(&node, "spring.datasource.password");
			// �����޸Ļ����е�����
			ServerInfo::getInstance().setDbUsername(dbUsername);
			ServerInfo::getInstance().setDbPassword(dbPassword);
			ServerInfo::getInstance().setDbName(dbName);
			ServerInfo::getInstance().setDbHost(dbHost);
			ServerInfo::getInstance().setDbPort(dbPort);
		}
	}

	// ע�����
	if (!ServerInfo::getInstance().getServiceName().empty() && !ServerInfo::getInstance().getRegIp().empty())
	{
		nacosClient.registerInstance(
			ServerInfo::getInstance().getRegIp(),
			atoi(ServerInfo::getInstance().getServerPort().c_str()),
			ServerInfo::getInstance().getServiceName());
	}
#endif

#ifndef _RELEASE_DOC_
	// ��ʼ���ݿ�����
	bool initConnPool = DbInit::initDbPool(DBConfig(
		ServerInfo::getInstance().getDbUsername(),
		ServerInfo::getInstance().getDbPassword(),
		ServerInfo::getInstance().getDbName(),
		ServerInfo::getInstance().getDbHost(),
		ServerInfo::getInstance().getDbPort(),
		ServerInfo::getInstance().getDbMax()));
	if (!initConnPool) return -1;
#endif

	// ����HTTP������
	HttpServer::startServer(ServerInfo::getInstance().getServerPort(),
		[=](Endpoints* doc, HttpRouter* router) {
			Router(doc, router).initRouter();
		},
		[](std::shared_ptr<AbstractComponentReg>* o) {
			*o = std::make_shared<OtherComponent>();
		});

#ifndef _RELEASE_DOC_
	// �ͷ����ݿ�����
	DbInit::releasePool();
#endif

#ifdef LINUX
	// ��ע�����
	if (!ServerInfo::getInstance().getServiceName().empty() && !ServerInfo::getInstance().getRegIp().empty())
	{
		nacosClient.deregisterInstance(
			ServerInfo::getInstance().getRegIp(),
			atoi(ServerInfo::getInstance().getServerPort().c_str()),
			ServerInfo::getInstance().getServiceName());
	}
#endif
	return 0;
}
