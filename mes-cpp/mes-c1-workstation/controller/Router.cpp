#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
#include "controller/workstation/WorkStationController.h"
#include "humanresource/HumanResourceListController.h"
#include "add-wf-for-ws/AddWorkFixtureForWorkStationController.h"
#include "get-wf-for-ws/GetWorkFixtureForWorkStationController.h"
#include "deviceresource/DeviceResourceController.h"
#include "equipment/EquipmentController.h"
#include "wk_delete/Delete_Workwear_Controller.h"
#include "wk_change/WorkeChange_Controller.h"
#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif

// ��������˹ر�Swagger�ĵ���
#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	ROUTER_SIMPLE_BIND(WorkStationController);
	ROUTER_SIMPLE_BIND(HumanResourceListController);
	ROUTER_SIMPLE_BIND(AddWorkFixtureForWorkStationController);
	ROUTER_SIMPLE_BIND(GetWorkFixtureForWorkStationController);
	ROUTER_SIMPLE_BIND(DeviceResourceController);
	ROUTER_SIMPLE_BIND(EquipmentController);
	ROUTER_SIMPLE_BIND(ChangeWorkwearController);
	ROUTER_SIMPLE_BIND(DeleteWorkwearController);
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);
	// ���ļ�������
	ROUTER_SIMPLE_BIND(FileController);

	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif
