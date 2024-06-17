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
#include "controller/purchasereceiving/AddListController.h"
#include "controller/purchasereceiving/ModifyListController.h"
#include "controller/purchasereceiving/information/GetListController.h"
#include "PurchaseReceipt/GetReceiptController.h"
#include "controller/ProchAndStorage/MaterialsInfo/AddWhStorageorderController.h"
#include "controller/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderController.h"
#include "controller/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderController.h"
#include "WarehouseInbound/WarehouseInboundController.h"
#include "WarehouseDelete/WarehouseDeleteController.h"
#include "WarehouseExport/WarehouseExportController.h"

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
	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(GetReceiptController);//shudeqilong	
	ROUTER_SIMPLE_BIND(ModifyListController);//upup
	ROUTER_SIMPLE_BIND(AddListController);//upup
	ROUTER_SIMPLE_BIND(GetListController);//upup
	ROUTER_SIMPLE_BIND(AddWhStorageorderController);//xiaoyang
	ROUTER_SIMPLE_BIND(ModifyWhStorageorderController);//xiaoyang
	ROUTER_SIMPLE_BIND(DeleteWhStorageorderController);//xiaoyang
	ROUTER_SIMPLE_BIND(WarehouseInboundController);//xinye
	ROUTER_SIMPLE_BIND(WarehouseDeleteController);//xinye
	ROUTER_SIMPLE_BIND(WarehouseExportController);//xinye
}
