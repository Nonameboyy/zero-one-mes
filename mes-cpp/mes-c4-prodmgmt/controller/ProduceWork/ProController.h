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
#ifndef _PRODUCEWORK_CONTROLLER_
#define _PRODUCEWORK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/ProduceWork/ProduceWorkDTO.h"
#include "domain/vo/ProduceWork/ProduceWorkJsonVO.h"

/*
开发人员：尛孩子
*/

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 生产报工控制器
 */
class ProController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	//  2 定义控制器访问入口
	API_ACCESS_DECLARE(ProController);
	//  3 定义接口
public:
	 //3.1 定义获取报工详情
	ENDPOINT_INFO(queryProduceWorkFeedbackDetail) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("ProduceWork.query.summary"), ProduceWorkJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/prodmgmt/prodreport/querydetail/{record_id}", queryProduceWorkFeedbackDetail, PATH(UInt64, record_id), execProduceWorkDetail(record_id));

	// 定义添加报工接口
	ENDPOINT_INFO(addProduceWork) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ProduceWork.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/prodmgmt/prodreport/add", addProduceWork, BODY_DTO(ProduceWorkDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddProduceWork(dto));
	}

	// 修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("ProduceWork.put.summary"), modifyProduceWork, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/prodmgmt/prodreport/modify", modifyProduceWork, BODY_DTO(ProduceWorkDTO::Wrapper, dto), execModifyProduceWork(dto));
private:
	// 
	ProduceWorkJsonVO::Wrapper execProduceWorkDetail(const UInt64& record_id);

	
	Uint64JsonVO::Wrapper execAddProduceWork(const ProduceWorkDTO::Wrapper& dto);

	
	Uint64JsonVO::Wrapper execModifyProduceWork(const ProduceWorkDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_SAMPLE_CONTROLLER_