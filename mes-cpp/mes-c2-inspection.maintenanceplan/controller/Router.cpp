/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

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
#include "Router.h"
#include "ApiHelper.h"
#include "ModifyPlan/ModifyPlanController.h"
#include "ModifyPlanStatus/ModifyPlanStatusController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "ModifyPlan/ModifyPlanController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif
#include "planSubject/PlanSubjectController.h"

#include "ExportPlan/ExportPlanController.h"
#include"query-ForeverOMC/MachineryPlanQueryController.h"
#include "../controller/device-list/DeviceListController.h"
#include "../controller/maintain-proj/MaintainProjController.h"
#include"./adddevice/AddDeviceController.h"
#include "addplan/AddPlanController.h"

#include "../controller/deletePlanSubject/DeletePlanSubjectController.h"

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
	//ROUTER_SIMPLE_BIND(AddController);
	//ROUTER_SIMPLE_BIND(PlanSubjectController);//测试项，abf，暂时注释
	ROUTER_SIMPLE_BIND(AddPlanController);
	ROUTER_SIMPLE_BIND(DeletePlanSubjectController);
	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(ExportPlanController);
	//ROUTER_SIMPLE_BIND(DeviceListController);
	ROUTER_SIMPLE_BIND(MaintainProjController);
	//ROUTER_SIMPLE_BIND(PlanSubjectController);
	ROUTER_SIMPLE_BIND(MachineryPlanQueryController);
	ROUTER_SIMPLE_BIND(ModifyPlanController);
	ROUTER_SIMPLE_BIND(ModifyPlanStatusController);
	ROUTER_SIMPLE_BIND(AddDeviceController);
	ROUTER_SIMPLE_BIND(ExportPlanController);
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定示例控制器
	ROUTER_SIMPLE_BIND(SampleController);
	// 绑定用户控制器
	ROUTER_SIMPLE_BIND(UserController);
	// 绑定文件控制器
	ROUTER_SIMPLE_BIND(FileController);

	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}
#endif
