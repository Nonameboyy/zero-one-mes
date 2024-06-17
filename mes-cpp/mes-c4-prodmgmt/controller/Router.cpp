#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"

#include "controller/prodmgmt/RemoveWorkReportController.h"
#include "controller/productionorder/ProductionOrderController.h"
#include "controller/productioninvestigation/ProductionProcessController.h"
#include "controller/ProdOrder/ProdOrderController.h"
#include "controller/ProdWorkorder/ProdWorkorderController.h"
#include "controller/ApprovalStage/ApprovalStage.h"
#include "controller/ProdWorkorder/ProWorkorderController.h"
#include "controller/ProduceWork/ProController.h"
#include "controller/FeedBack/FeedBackController.h"
#include "controller/ProdTask/ProdTaskController.h"

// 如果定义了关闭Swagger文档宏
#ifdef CLOSE_SWAGGER_DOC
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints * docEndpoints, HttpRouter * router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
	
	ROUTER_SIMPLE_BIND(ProdWorkorderController);//shuibuzhao
	ROUTER_SIMPLE_BIND(ProWorkorderController);//xijin	
	ROUTER_SIMPLE_BIND(ProductionOrderController);//amie
	ROUTER_SIMPLE_BIND(ProductionProcessController);//amie
	ROUTER_SIMPLE_BIND(ProdOrderController);//dingzhen
	ROUTER_SIMPLE_BIND(FeedBackController);//jieke
	ROUTER_SIMPLE_BIND(ProdTaskController);//jieke
	ROUTER_SIMPLE_BIND(ProController);//Xhaizi
	ROUTER_SIMPLE_BIND(ApprovalStage);//qizhewoniu
	ROUTER_SIMPLE_BIND(RemoveWorkReportController);//shudeqilong
}


