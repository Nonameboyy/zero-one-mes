#pragma once

#ifndef _WORKFIXTUREFORWORKSTATION_CONTROLLER_H_
#define _WORKFIXTUREFORWORKSTATION_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/add-wf-for-ws/AddWorkFixtureForWorkStationDTO.h"
#include "domain/vo/add-wf-for-ws/AddWorkFixtureForWorkStationVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class AddWorkFixtureForWorkStationController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AddWorkFixtureForWorkStationController);
	// 3 定义接口
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addWorkFixtureForWorkStation) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("wf_for_ws.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/ws/add/wf_for_ws", addWorkFixtureForWorkStation, BODY_DTO(AddWorkFixtureForWorkStationDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddWorkFixtureForWorkStation(dto));
	}
private:
	Uint64JsonVO::Wrapper execAddWorkFixtureForWorkStation(const AddWorkFixtureForWorkStationDTO::Wrapper& dto);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
