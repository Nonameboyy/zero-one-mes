#pragma once

#ifndef _ROUTER_
#define _ROUTER_
#include "oatpp/web/server/api/Endpoint.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
using namespace oatpp::web::server;
using namespace oatpp::web::server::api;

/**
 * ǰ�˷��ʷ�����·�ɰ󶨣����ڶ���ǰ�˷��ʺ�˽ӿںͷ���·����
 * swagger�ĵ�����ʾ����ַ��http://localhost:8090/swagger/ui
 */
class Router
{
private:
	// �ĵ����ʶ˵�
	Endpoints* docEndpoints;
	// ·�ɶ���
	HttpRouter* router;
public:
	// �����ʼ��
	Router(Endpoints* docEndpoints, HttpRouter* router);
	// ���г�ʼ��
	void initRouter();
private:
#ifdef HTTP_SERVER_DEMO
	// ������ʾ·��
	void createSampleRouter();
#endif
};

#endif // !_ROUTER_