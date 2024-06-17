
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"

//新添加的文件
#include "return/ReturnController.h"
#include "return-ryan/ReturnController_r.h"
#include "controller/material/RController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif




#ifdef CLOSE_SWAGGER_DOC

#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else

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


	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(ReturnController);
	ROUTER_SIMPLE_BIND(ReturnController_r);
	ROUTER_SIMPLE_BIND(RController);
	
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	
	ROUTER_SIMPLE_BIND(SampleController);

	ROUTER_SIMPLE_BIND(UserController);

	ROUTER_SIMPLE_BIND(FileController);
	
	
	router->addController(WSContorller::createShared());
}
#endif
