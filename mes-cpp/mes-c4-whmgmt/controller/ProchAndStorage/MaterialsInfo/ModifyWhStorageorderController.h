#pragma once
#ifndef _MODIFYWHSTORAGEORDERCONTROLLER_H_
#define _MODIFYWHSTORAGEORDERCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderDTO.h"
#include "../../../domain/vo/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ModifyWhStorageorderController :public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyWhStorageorderController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("whstorageorder.modify.summary"), modifyWhStorageorder, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/whmgmt/purchase/modify2", modifyWhStorageorder, BODY_DTO(ModifyWhStorageorderDTO::Wrapper, dto), execModifyWhStorageorder(dto));

	
private://定义接口执行函数
	//演示新增数据
	Uint64JsonVO::Wrapper execModifyWhStorageorder(const ModifyWhStorageorderDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_MODIFYWHSTORAGEORDERCONTROLLER_H_
