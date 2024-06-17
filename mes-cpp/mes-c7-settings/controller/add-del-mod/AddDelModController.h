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
#ifndef _ADDDELMOD_CONTROLLER_
#define _ADDDELMOD_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/add-del-mod/AddDelModQuery.h"
#include "domain/dto/add-del-mod/AddDelModDTO.h"
#include "domain/vo/add-del-mod/AddDelModVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class AddDelModController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AddDelModController);
	// 3 定义接口
public:
	
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addWarehouse) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add-del-mod.controller.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/settings/add-warehouse", addWarehouse, BODY_DTO(AddDelModDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddWarehouse(dto));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("add-del-mod.controller.put.summary"), modifyWarehouse, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/settings/mod-warehouse", modifyWarehouse, BODY_DTO(AddDelModDTO::Wrapper, dto), execModifyWarehouse(dto));

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeWarehouse) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("add-del-mod.controller.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "warehouse_id", ZH_WORDS_GETTER("add-del-mod.controller.delete.warehouse_id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/settings/del-warehouse-by-warehouse_id/{warehouse_id}", removeWarehouse, PATH(UInt64, warehouse_id), execRemoveWarehouse(warehouse_id));

private:
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddWarehouse(const AddDelModDTO::Wrapper& dto);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyWarehouse(const AddDelModDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveWarehouse(const UInt64& warehouse_id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ADDDELMOD_CONTROLLER_