#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _PRODORDER1_CONTROLLER_
#define _PRODORDER1_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/ProdTask/ProdTaskDTO.h"
#include "domain/vo/ProdTask/ProdTaskVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 生产任务查询控制器，基础接口的使用
 */
class ProdTaskController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ProdTaskController);
public:
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("prod1.put.summary"), modifyProdTask, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/prodmgmt/prodschedule/modify", modifyProdTask, BODY_DTO(ProdTaskModifyDTO::Wrapper, dto), execModifyProdTask(dto));

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeProdTask) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("prod1.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("prod1.field.id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/prodmgmt/prodschedule/delete/{id}", removeProdTask, PATH(UInt64, id), execRemoveProdTask(id));

private:
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyProdTask(const ProdTaskModifyDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveProdTask(const UInt64& id);
	// 3.3 测试声明式服务调用1
	//ProdOrderJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	// 3.3 测试声明式服务调用2
	//ProdOrderPageJsonVO::Wrapper execQueryAll(const ProdOrderQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRODORDER1_CONTROLLER